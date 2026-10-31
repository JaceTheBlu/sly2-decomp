#!/usr/bin/env python3
"""Replace local re-declarations of a struct with the shared header.

  migrate_struct.py STRUCT HEADER [--dry-run] [FILE ...]
  e.g. migrate_struct.py CLOCK clock.h

Most sources declare the classes they touch locally (`struct CLOCK { float t; float dt; };`, field names and
padding vary).  For every source with a simple local definition of STRUCT (scalars, pointers, arrays and padding;
no unions, nested types or methods):
  - the layout is computed and every named local field is matched by offset and size to a field of the canonical
    definition in include/HEADER (or one element of a canonical array: `a[3]` -> `art[3]` style is not attempted,
    such files are skipped);
  - the local definition is removed and `#include "HEADER"` added;
  - accesses `.old` / `->old` become the canonical names.  A renamed access that belonged to another struct cannot
    pass unnoticed: it either fails to compile (no such member) or changes the code, and objcheck reports both
    (--careful skips files where another local struct has a field of the same name instead).
Files it cannot handle are listed and left alone.  Run tools/objcheck.py check afterwards: a source whose code
changes, or that no longer compiles, must be reverted (git checkout FILE).
"""
import os, re, sys, glob, collections

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SIZES = {'char': 1, 'uchar': 1, 'unsigned char': 1, 'signed char': 1, 'u8': 1, 's8': 1, 'byte': 1,
         'short': 2, 'ushort': 2, 'unsigned short': 2, 'u16': 2, 's16': 2,
         'int': 4, 'uint': 4, 'unsigned int': 4, 'unsigned': 4, 'float': 4, 's32': 4, 'u32': 4, 'f32': 4,
         'long': 8, 'ulong': 8, 'unsigned long': 8, 'TICK': 8, 's64': 8, 'u64': 8, 'double': 8}


def kind(ty, ptr):
    return 'p' if ptr else ('f' if ty in ('float', 'f32', 'double') else 'i')


def parse_fields(body):
    """[(name, offset, elem size, count, kind)] for a simple struct body, or None.  kind: f float, p pointer, i int."""
    body = re.sub(r'\bstruct\s+(?=[A-Za-z_]\w*\s*\*)', '', body)   # `struct DLI *pdliNext`
    if re.search(r'\b(union|struct|class|enum)\b|\(|\{|::|operator|public:|private:|virtual|static', body): return None
    off = 0; out = []; align = 1
    for decl in [d.strip() for d in body.split(';') if d.strip()]:
        m = re.match(r'((?:unsigned |signed |const |volatile )*[A-Za-z_]\w*)\s*(.*)$', decl, re.S)
        if not m: return None
        ty = m.group(1).replace('const ', '').replace('volatile ', '').strip()
        for item in [x.strip() for x in m.group(2).split(',')]:
            mi = re.fullmatch(r'(\**)\s*([A-Za-z_]\w*)\s*((?:\[[^\]]+\])*)', item)
            if not mi: return None
            ptr, name, dims = mi.groups()
            sz = 4 if ptr else SIZES.get(ty)
            if sz is None: return None
            n = 1
            for dexpr in re.findall(r'\[([^\]]+)\]', dims):
                try: n *= int(eval(dexpr.replace('U', ''), {}))
                except Exception: return None
            off = (off + sz - 1) // sz * sz; align = max(align, sz)
            out.append((name, off, sz, n, kind(ty, ptr))); off += sz * n
    return out


def canonical(struct, header):
    t = re.sub(r'/\*.*?\*/|//[^\n]*', '', open(os.path.join(ROOT, 'include', header)).read(), flags=re.S)
    t = re.sub(r'typedef\s+unsigned long\s+(\w+)\s*;', lambda m: SIZES.setdefault(m.group(1), 8) and '', t)
    m = re.search(r'struct\s+%s\s*\{((?:[^{}]|\{[^{}]*\})*)\};' % struct, t, re.S)
    # anonymous unions: every member is a candidate at the union's offset
    out = []; off = 0
    for part in re.split(r'(union\s*\{[^{}]*\}\s*;)', m.group(1)):
        if part.startswith('union'):
            members = parse_fields(re.search(r'\{([^{}]*)\}', part).group(1))
            al = max(sz for n, o, sz, c, k in members); off = (off + al - 1) // al * al
            out += [(n, off, sz, c, k) for n, o, sz, c, k in members]
            off += max(sz * c for n, o, sz, c, k in members)
        elif part.strip():
            for n, o, sz, c, k in parse_fields(part):
                off = (off + sz - 1) // sz * sz
                out.append((n, off, sz, c, k)); off += sz * c
    return out


def main():
    a = [x for x in sys.argv[1:] if not x.startswith('--')]
    dry = '--dry-run' in sys.argv
    struct, header = a[0], a[1]
    canon = canonical(struct, header)
    by_off = collections.defaultdict(list)   # (offset, size) -> canonical candidates (several for a union)
    for n, o, sz, cnt, k in canon: by_off[o, sz].append((n, cnt, k))
    files = [os.path.abspath(f) for f in a[2:]] or sorted(glob.glob(os.path.join(ROOT, 'src', '**', '*.c*'), recursive=True))
    defre = re.compile(r'^[ \t]*(?:typedef[ \t]+)?struct[ \t]+%s[ \t]*\{([^{}]*)\}[ \t]*(?:%s[ \t]*)?;[ \t]*\n' % (struct, struct), re.M)
    done = 0; skipped = {}
    for p in files:
        if os.sep + 'lib' + os.sep in p: continue
        t = open(p, encoding='utf-8', errors='surrogateescape').read()
        ms = list(defre.finditer(t))
        if not ms: continue
        rel = os.path.relpath(p, ROOT)
        if len(ms) > 1: skipped[rel] = 'several definitions'; continue
        fields = parse_fields(re.sub(r'/\*.*?\*/|//[^\n]*', '', ms[0].group(1), flags=re.S))
        if fields is None: skipped[rel] = 'not a simple struct'; continue
        ren = {}
        ok = True
        for n, o, sz, cnt, k in fields:
            if re.fullmatch(r'pad\w*|_?unk\w*', n): continue
            cands = [c for c in by_off.get((o, sz), []) if c[1] == cnt]
            if not cands: ok = False; skipped[rel] = f'field {n} @0x{o:X} has no canonical counterpart'; break
            same = [c for c in cands if c[2] == k]
            if not same: ok = False; skipped[rel] = f'field {n} @0x{o:X} is {k}, canonical {cands[0][0]} is {cands[0][2]}'; break
            c = next((x for x in same if x[0] == n), same[0])
            if c[0] != n: ren[n] = c[0]
        if not ok: continue
        # other local structs of the file must not have fields with the renamed names
        others = t[:ms[0].start()] + t[ms[0].end():]
        if '--careful' in sys.argv and ren and any(re.search(r'\{[^{}]*\b%s\b[^{}]*\}' % re.escape(old), others) for old in ren):
            skipped[rel] = 'a renamed field name is also used by another struct'; continue
        u = others
        # static asserts on the size of the local stand-in (typedef char X[sizeof(STRUCT)==8?1:-1];) checked the
        # stand-in, not the real type: they go with it
        u = re.sub(r'^[ \t]*typedef[ \t]+char[ \t]+\w+[ \t]*\[[^\]\n]*(?:sizeof|__alignof__)[ \t]*\([ \t]*(?:struct[ \t]+)?%s[ \t]*\)[^\n]*\n'
                   % struct, '', u, flags=re.M)
        for old, new in ren.items():
            u = re.sub(r'(\.|->)\s*%s\b' % re.escape(old), r'\g<1>' + new, u)
        if f'#include "{header}"' not in u:
            u = f'#include "{header}"\n' + u
        done += 1
        if not dry: open(p, 'w', encoding='utf-8', errors='surrogateescape').write(u)
    print(f'{done} file(s) migrated to include/{header}' + (' (dry run)' if dry else ''))
    from collections import Counter
    for why, n in Counter(skipped.values()).most_common(): print(f'  skipped {n}: {why}')
    if '--verbose' in sys.argv:
        for f, why in sorted(skipped.items()): print('   ', f, why)


if __name__ == '__main__':
    main()
