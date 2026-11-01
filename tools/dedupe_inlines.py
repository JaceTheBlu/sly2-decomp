#!/usr/bin/env python3
"""Replace local copies of the helpers in include/vu0.h by the header (phase 4).

  dedupe_inlines.py [--dry-run] [FILE ...]

A one-line `static inline` / `static __inline__` definition in a source is replaced when it is the same function
as a helper of include/vu0.h: same text once parameter and local names are made positional, whitespace (also
inside asm strings) is collapsed, `inline`/`__inline__` are treated alike and the quadword type spelling
(`qword`, `VU0_QWORD`, `u128`...) is ignored.  Calls to the local name are renamed to the helper's name.  A file is
skipped when the helper's name already means something else in it.  Check with tools/objcheck.py afterwards.
"""
import os, re, sys, glob

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HEADER = 'vu0.h'
DEF = re.compile(r'^[ \t]*static[ \t]+(?:__inline__|inline)[ \t][^\n]*\{[^\n]*\}[ \t]*\n', re.M)
QW = r'(?:vu0_qword|qword|u128|s128|QWORD|int __attribute__\(\(mode\(TI\)\)\))'
KEYWORDS = {'static', 'inline', '__inline__', 'float', 'int', 'return', '__asm__', 'asm', 'volatile', 'unsigned',
            'QW', 'if', 'else', 'f', 'r', 'j', 'x', 'y', 'z'}


def normalize(d):
    """(name, normal form) of a one-line definition."""
    d = d.strip().replace('__inline__', 'inline')
    d = re.sub(QW, 'QW', d)
    m = re.match(r'static inline\s+(.*?)\b(\w+)\s*\(([^)]*)\)\s*\{(.*)\}\s*$', d, re.S)
    if not m: return None, None
    ret, name, params, body = m.groups()
    # positional names for parameters and locals (identifiers declared after a type)
    ids = [p.split()[-1].lstrip('*') for p in params.split(',') if p.strip() and p.strip() != 'void']
    ids += re.findall(r'\b(?:QW|float|int)\s+\*?(\w+)\s*[;=,]', body)
    t = ret + '(' + params + '){' + body + '}'
    for i, n in enumerate(dict.fromkeys(ids)):
        if n in KEYWORDS: continue
        t = re.sub(r'(?<!%)\b' + re.escape(n) + r'\b', 'v%d' % i, t)
    t = re.sub(r'"([^"]*)"', lambda s: '"' + re.sub(r'\s*,\s*', ',', re.sub(r'\s+', ' ', s.group(1).strip())) + '"', t)
    t = re.sub(r'\s+', ' ', t)
    t = re.sub(r' ?([(){};,:=*<>?]) ?', r'\1', t)
    return name, t


def main():
    dry = '--dry-run' in sys.argv
    hdr = open(os.path.join(ROOT, 'include', HEADER)).read()
    canon = {}
    for m in DEF.finditer(hdr):
        n, t = normalize(m.group(0))
        if n: canon[t] = n
    files = [os.path.abspath(f) for f in sys.argv[1:] if not f.startswith('--')] or \
        sorted(glob.glob(os.path.join(ROOT, 'src', '**', '*.c*'), recursive=True))
    done = 0; removed = 0
    for p in files:
        if os.sep + 'lib' + os.sep in p or not p.endswith(('.c', '.cpp')): continue
        t = open(p, encoding='utf-8', errors='surrogateescape').read()
        ren = {}; drop = []
        for m in DEF.finditer(t):
            n, norm = normalize(m.group(0))
            if norm in canon: drop.append(m); ren[n] = canon[norm]
        if not drop: continue
        u = t
        for m in reversed(drop): u = u[:m.start()] + u[m.end():]
        # the helper names must not already mean something else in the file
        # the helper names must not already mean something else in the file: no other definition or
        # declaration of that name may remain (C++ would see an overload; C a conflicting definition)
        if any(re.search(r'\b' + h + r'\s*\([^;{()]*(?:\([^()]*\)[^;{()]*)*\)\s*[;{]', u) for h in set(ren.values())):
            continue
        if any(re.search(r'\b' + h + r'\b', u) for h in set(ren.values()) if h not in ren):
            continue
        for old, new in ren.items():
            if old != new: u = re.sub(r'\b' + re.escape(old) + r'\b(?=\s*\()', new, u)
        u = f'#include "{HEADER}"\n' + u
        done += 1; removed += len(drop)
        if not dry: open(p, 'w', encoding='utf-8', errors='surrogateescape').write(u)
    print(f'{done} file(s): {removed} local helper definition(s) replaced by include/{HEADER}' + (' (dry run)' if dry else ''))


if __name__ == '__main__':
    main()
