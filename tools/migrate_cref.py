#!/usr/bin/env python3
"""Replace local C++ re-declarations of class CRef by include/cref.h (phase 2).

  migrate_cref.py [--dry-run]

A .cpp file is converted when its local `struct/class CRef { ... };` has the CRef layout (m_tagk, then an int
m_tag or a union u {n, g, pv}) and only methods that cref.h declares the same way.  The definition goes, the
include comes, and union accesses are renamed (`.u.n` -> `.m_tag`, `.u.g` -> `.m_g`, `.u.pv` -> `.m_p`).
Declaring more operator= overloads than a file had can change which one an assignment calls: objcheck reports it,
and such files must be reverted.
"""
import os, re, sys, glob

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ALLOWED = {'CRef() { m_tagk = -1; }', 'CRef(int tagk) { InitTag(tagk); }', 'CRef(const CRef &r);', 'CRef(const CRef &);',
           '~CRef() { Decref(); }', 'CRef &operator=(const CRef &r);', 'CRef &operator=(const CRef &);',
           'CRef &operator=(float g);', 'CRef &operator=(int n);', 'CRef &operator=(bool f);',
           'CRef &operator=(void *pv);', 'CRef &operator=(qword q);', 'void Decref();', 'void InitTag(int tagk);'}
DEF = re.compile(r'^(?:struct|class)\s+CRef\s*\{(.*?)^\}\s*;[ \t]*\n', re.M | re.S)


def ok(body):
    b = re.sub(r'//[^\n]*|/\*.*?\*/', '', body, flags=re.S)
    b = re.sub(r'\bpublic\s*:', '', b)
    b = re.sub(r'^\s*int m_tagk;\s*(?:int m_tag;|union\s*\{\s*int n;\s*float g;\s*void \*pv;\s*\}\s*u;)', '', b)
    if b == re.sub(r'//[^\n]*|/\*.*?\*/', '', body, flags=re.S): return False
    meths = re.findall(r'[^;{}]*\([^;{}]*\)\s*(?:const\s*)?(?:\{[^{}]*\}|;)', b)
    rest = b
    for m in meths: rest = rest.replace(m, '', 1)
    return not rest.strip() and all(re.sub(r'\s+', ' ', m).strip() in ALLOWED for m in meths)


def main():
    dry = '--dry-run' in sys.argv; n = 0
    for p in sorted(glob.glob(os.path.join(ROOT, 'src', '**', '*.cpp'), recursive=True)):
        t = open(p, encoding='utf-8', errors='surrogateescape').read()
        ms = list(DEF.finditer(t))
        if len(ms) != 1 or not ok(ms[0].group(1)): continue
        u = t[:ms[0].start()] + t[ms[0].end():]
        for old, new in (('n', 'm_tag'), ('g', 'm_g'), ('pv', 'm_p')):
            u = re.sub(r'(\.|->)\s*u\.%s\b' % old, r'\g<1>' + new, u)
        if '#include "cref.h"' not in u: u = '#include "cref.h"\n' + u
        n += 1
        if not dry: open(p, 'w', encoding='utf-8', errors='surrogateescape').write(u)
    print(f'{n} file(s) converted to include/cref.h' + (' (dry run)' if dry else ''))


if __name__ == '__main__':
    main()
