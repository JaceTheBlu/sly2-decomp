#!/usr/bin/env python3
"""Merge every local definition of a struct into one proposed layout (phase 2 helper).

  consolidate.py STRUCT [--min N]

Reads all simple local definitions of STRUCT in src/ (the same ones tools/migrate_struct.py understands), lays
them out, and prints, for each offset, the field sizes/kinds seen and the names used with their counts.  Generic
names (pad, unk, x4C, f10, a, b…) are ranked last.  Conflicts (different sizes or kinds at one offset) are flagged:
they usually mean a union, or a stand-in declaration that is wrong about that field.
The output is a starting point for include/<header>.h, not a header: pick names, check conflicts in the code.
"""
import os, re, sys, glob, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from migrate_struct import parse_fields

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GENERIC = re.compile(r'(pad|unk|_)\w*|[a-z]{0,2}[0-9A-Fa-f]{1,4}|[a-z]|[A-Z]\d*|field\w*|x[0-9A-Fa-f]+')


def collect(struct):
    defre = re.compile(r'^[ \t]*(?:typedef[ \t]+)?struct[ \t]+%s[ \t]*\{([^{}]*)\}' % struct, re.M)
    out = []
    for p in glob.glob(os.path.join(ROOT, 'src', '**', '*.c*'), recursive=True):
        if os.sep + 'lib' + os.sep in p: continue
        t = open(p, errors='ignore').read()
        for m in defre.finditer(t):
            f = parse_fields(re.sub(r'/\*.*?\*/|//[^\n]*', '', m.group(1), flags=re.S))
            if f is not None: out.append((os.path.relpath(p, ROOT), f))
    return out


def main():
    struct = sys.argv[1]
    defs = collect(struct)
    by = collections.defaultdict(lambda: collections.defaultdict(collections.Counter))
    for src, fields in defs:
        for n, o, sz, cnt, k in fields:
            if re.fullmatch(r'pad\w*|_?unk\w*', n): continue
            by[o][(sz, cnt, k)][n] += 1
    print(f'{struct}: {len(defs)} simple local definitions')
    for o in sorted(by):
        shapes = by[o]
        flag = '  CONFLICT' if len(shapes) > 1 else ''
        for (sz, cnt, k), names in sorted(shapes.items(), key=lambda x: -sum(x[1].values())):
            ranked = sorted(names.items(), key=lambda x: (bool(GENERIC.fullmatch(x[0])), -x[1]))
            print(f'  0x{o:03X} {k}{sz}' + (f'[{cnt}]' if cnt > 1 else '   ') +
                  f' x{sum(names.values()):<3d} ' + ', '.join(f'{n}({c})' for n, c in ranked[:6]) + flag)
            flag = ''


if __name__ == '__main__':
    main()
