#!/usr/bin/env python3
"""Refactoring safety net: compare compiled code against a recorded baseline (no game executable needed).

  objcheck.py baseline                 compile every source, record build/baseline.json
  objcheck.py check [SRC ...]          recompile the given sources (default: every source that differs from the
                                       baseline commit, see --base) and compare each function with the baseline
  objcheck.py check --all              recompile and compare everything

Every function in the tree matches the original game, so a source change that leaves the compiled function
identical to the baseline cannot break the match.  "Identical" is stricter than matchtool.py: the raw object words
(relocation addends included) must be equal AND every relocation must point at the same target.  A relocation target
is identified by address, not by name: function names resolve through config/functions.csv + symbol_addrs.txt,
`D_XXXXXXXX` through the address in the name, and data names through `type:data` lines in symbol_addrs.txt.  So a
rename (func_0013DA18 -> LoadSwFromBrx) passes, while pointing a call at a different function fails.

Functions are keyed by address, so renaming the function itself and moving it to another file both pass.
"""
import os, sys, re, json, glob, struct, subprocess
from concurrent.futures import ThreadPoolExecutor
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import matchtool as M
import progress as P

BASELINE = os.path.join(M.ROOT, 'build', 'baseline.json')


def all_sources():
    return sorted(glob.glob(os.path.join(M.ROOT, 'src', '**', '*.cpp'), recursive=True) +
                  glob.glob(os.path.join(M.ROOT, 'src', '**', '*.c'), recursive=True))


def symbol_table():
    """name -> address for every named function and data symbol."""
    tab = {n: a for n, (a, s) in M.load_functions().items()}
    for line in open(os.path.join(M.ROOT, 'config', 'symbol_addrs.txt')):
        m = re.match(r'(\S+)\s*=\s*0x([0-9A-Fa-f]+);', line)
        if m: tab.setdefault(m.group(1), int(m.group(2), 16))
    return tab


def ident(name, tab):
    """Address of a relocation target when it can be known, else its exact name.

    A .cpp file that declares `float func_0011CF60(float)` outside extern "C" calls `func_0011CF60__Ff`: the address
    is still the one in the name, and after a rename (RadNormalize__Ff) the call is `RadNormalize__Ff__Ff`, which
    resolves through its `RadNormalize__Ff` prefix."""
    if name in tab: return '@%06X' % tab[name]
    m = re.fullmatch(r'(?:D|func|jtbl|jumptable)_([0-9A-Fa-f]{8})(?:__\w*)?', name)
    if m: return '@%06X' % int(m.group(1), 16)
    parts = name.split('__')
    for k in range(len(parts) - 1, 0, -1):
        if '__'.join(parts[:k]) in tab: return '@%06X' % tab['__'.join(parts[:k])]
    return name


def key(name):
    """Baseline key of a compiled function: its address, or for compiler-generated helpers (type info, static
    initialisers, local classes) a form without the parts that renames change (file path, enclosing function)."""
    if name.startswith('@'): return name
    name = re.sub(r'^(_GLOBAL_\$[ID]\$).*', r'\1', name)
    return re.sub(r'func_[0-9A-Fa-f]{8}|[A-Za-z_]\w*__F\w*', 'F', name)


def read_obj_full(path):
    """Like matchtool.read_obj, but relocations keep their symbol: {sec: {off: (type, symname)}}."""
    d = open(path, 'rb').read()
    shoff, = struct.unpack_from('<I', d, 0x20); shentsize, shnum, shstrndx = struct.unpack_from('<HHH', d, 0x2E)
    secs = []
    for i in range(shnum):
        name, typ, flags, addr, off, size, link, info, align, entsize = struct.unpack_from('<10I', d, shoff + i * shentsize)
        secs.append(dict(name=name, type=typ, off=off, size=size, link=link, info=info))
    shstr = secs[shstrndx]
    for s in secs:
        s['name'] = d[shstr['off'] + s['name']:d.index(b'\0', shstr['off'] + s['name'])].decode()
    symtab = next(s for s in secs if s['type'] == 2)
    strtab = secs[symtab['link']]
    syms = []
    for i in range(symtab['size'] // 16):
        nm, val, size, info, other, shndx = struct.unpack_from('<IIIBBH', d, symtab['off'] + i * 16)
        n = d[strtab['off'] + nm:d.index(b'\0', strtab['off'] + nm)].decode()
        if not n and (info & 0xf) == 3 and shndx < len(secs): n = secs[shndx]['name']   # section symbol
        syms.append(dict(name=n, value=val, size=size, type=info & 0xf, shndx=shndx))
    relocs = {}
    for s in secs:
        if s['type'] == 9:
            r = relocs.setdefault(s['info'], {})
            for i in range(s['size'] // 8):
                off, inf = struct.unpack_from('<II', d, s['off'] + i * 8)
                r[off] = (inf & 0xff, syms[inf >> 8]['name'])
    return d, secs, syms, relocs


def fingerprint(src, tab):
    """{function key: [hex words, [[word index, reloc type, target], ...]]} for one source, or None if it fails."""
    of = None
    for attempt in range(3):   # the Windows compiler under wibo very occasionally fails under heavy parallel load
        try:
            of = compile_obj(src)
        except Exception:
            of = None
        if of is not None: break
    if of is None: return None
    try:
        d, secs, syms, relocs = read_obj_full(of)
    finally:
        os.remove(of)
    out = {}
    for s in syms:
        if s['type'] != 2 or s['size'] == 0 or s['shndx'] >= len(secs): continue
        sec = secs[s['shndx']]
        words = struct.unpack_from('<%dI' % (s['size'] // 4), d, sec['off'] + s['value'])
        rel = sorted([(o - s['value']) // 4, t, ident(n, tab)] for o, (t, n) in relocs.get(s['shndx'], {}).items()
                     if s['value'] <= o < s['value'] + s['size'])
        out[ident(s['name'], tab)] = [''.join('%08x' % w for w in words), rel]
    return out


def compile_obj(src):
    """Compile exactly as progress.py does; return the object path (caller removes it) or None."""
    head = open(src, errors='ignore').read(2000)
    if 'SLY2_CC:' in head or 'SLY2_CFLAGS:' in head or 'SLY2_ASM:' in head:
        try:
            return M.compile_src(src)
        except SystemExit:
            return None
    import tempfile
    fd, of = tempfile.mkstemp(suffix='.o'); os.close(fd); os.remove(of)
    if src.endswith('.c'):
        flags = ['-x', 'c', '-O2', '-G0', '-ffast-math', '-mvu0-use-vf0-vf31', '-B' + P.B + '/', '-I' + M.M2C_INC]
    else:
        flags = M.CFLAGS
    subprocess.run(M.WIBO_CMD + [M.CC, '-c'] + M.INCLUDES + flags + [os.path.relpath(src, M.ROOT), '-o', of],
                   capture_output=True, text=True, cwd=M.ROOT, timeout=120)
    return of if os.path.exists(of) else None


def build(srcs, tab):
    res = {}
    with ThreadPoolExecutor(int(os.environ.get('JOBS', os.cpu_count() or 2))) as ex:
        for src, fp in zip(srcs, ex.map(lambda s: fingerprint(s, tab), srcs)):
            res[os.path.relpath(src, M.ROOT)] = fp
    return res


def git(*args):
    return subprocess.run(['git'] + list(args), capture_output=True, text=True, cwd=M.ROOT).stdout


def changed_sources(base):
    names = git('diff', '--name-only', base, '--', 'src', 'include').split() + \
            git('ls-files', '--others', '--exclude-standard', '--', 'src', 'include').split()
    if any(n.startswith('include/') for n in names):   # a shared header changed: every includer may compile differently
        return all_sources()
    return sorted({os.path.join(M.ROOT, n) for n in names if n.endswith(('.c', '.cpp')) and os.path.exists(os.path.join(M.ROOT, n))})


def main():
    a = sys.argv[1:]
    if not a or a[0] not in ('baseline', 'check'):
        print(__doc__); sys.exit(2)
    tab = symbol_table()
    if a[0] == 'baseline':
        res = build(all_sources(), tab)
        fail = [s for s, fp in res.items() if fp is None]
        # address key -> every compiled variant (a few functions are built from two sources).  Only variants that
        # matchtool/progress.py recorded as a match count: src/P2/gifs.cpp, for one, also builds a non-matching copy.
        import csv
        ok = {(r['source'], int(r['addr'], 16)) for r in csv.DictReader(open(os.path.join(M.ROOT, 'config', 'matched.csv')))
              if r['status'] == 'match'}
        funcs = {}; nonmatching = {}
        for s, fp in res.items():
            for k, v in (fp or {}).items():
                if k.startswith('@') and (s.replace(os.sep, '/'), int(k[1:], 16)) not in ok:
                    nonmatching[s + ' ' + k] = v; continue
                if v not in funcs.setdefault(key(k), []): funcs[key(k)].append(v)
        os.makedirs(os.path.dirname(BASELINE), exist_ok=True)
        json.dump({'commit': git('rev-parse', 'HEAD').strip(), 'functions': funcs, 'nonmatching': nonmatching,
                   'failed': fail}, open(BASELINE, 'w'))
        print(f'baseline: {len(funcs)} functions from {len(res)} sources at {git("rev-parse", "--short", "HEAD").strip()}'
              f' -> {os.path.relpath(BASELINE, M.ROOT)}')
        for s in fail: print('  BUILD FAILED (not in baseline):', s)
        return
    if not os.path.exists(BASELINE):
        sys.exit('no baseline: run `objcheck.py baseline` on a clean, fully matching tree first')
    base = json.load(open(BASELINE))
    # a relocation target the baseline only knew by name may have been given an address since (a rename that
    # added the name to symbol_addrs.txt): resolve the baseline's names again with today's table
    for vs in base['functions'].values():
        for v in vs:
            for r in v[1]:
                if not r[2].startswith('@'): r[2] = ident(r[2], tab)
    rest = [x for x in a[1:] if not x.startswith('--')]
    if '--all' in a: srcs = all_sources()
    elif rest: srcs = [os.path.abspath(x) for x in rest]
    else: srcs = changed_sources(base['commit'])
    res = build(srcs, tab)
    bad = 0; n = 0
    for s, fp in sorted(res.items()):
        if fp is None:
            print('BUILD FAILED', s); bad += 1; continue
        for k, v in sorted(fp.items()):
            n += 1
            bs = base['functions'].get(key(k))
            if bs is None:
                print(f'NEW        {s}: {k} (not in baseline)'); bad += 1
            elif v not in bs and base.get('nonmatching', {}).get(s + ' ' + k) == v:
                pass   # a known non-matching copy (another source holds the match), unchanged
            elif v not in bs:
                b = bs[0]
                why = 'code' if b[0] != v[0] else 'relocations'
                print(f'DIFFERS    {s}: {k} ({why})'); bad += 1
                if why == 'relocations':
                    for x, y in zip(b[1], v[1]):
                        if x != y: print(f'           first difference: baseline {x}  now {y}'); break
                    else: print(f'           baseline {len(b[1])} relocations, now {len(v[1])}')
    if '--all' in a:
        seen = {key(k) for fp in res.values() for k in (fp or {})}
        for k in sorted(set(base['functions']) - seen): print('MISSING   ', k); bad += 1
    print(f'{n} functions in {len(res)} sources checked, {bad} problem(s)')
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
