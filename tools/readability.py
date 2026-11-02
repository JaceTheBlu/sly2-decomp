#!/usr/bin/env python3
"""Readability metrics for the game code (src/ minus the Sony SDK in src/lib/).  Needs no compiler or game files.

  readability.py            print the metrics
  readability.py --record   also append them to config/readability_history.csv (one row per day)

Every count except the first two is "files that still have X": lower is better, 0 is the goal.
See docs/READABILITY_PLAN.md for what each phase is expected to bring down.
"""
import os, re, sys, csv, glob, datetime

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HIST = os.path.join(ROOT, 'config', 'readability_history.csv')

CHECKS = [   # (column, description, regex searched in the code with comments removed, or in the comments)
    ('local_types', 'files declaring their own struct/class/union', r'^\s*(?:typedef\s+)?(?:struct|class|union)\s+\w*\s*(?::[^{;]*)?\{', 'code'),
    ('pad_fields', 'files with padNN[] filler fields', r'\bpad[0-9A-Fa-f_]*\s*\[', 'code'),
    ('m2c_macros', 'files using M2C_FIELD/M2C_UNK/M2C_ERROR', r'\bM2C_\w+', 'code'),
    ('m2c_temps', 'files with m2c temporaries (temp_v0, sp10, var_s0...)', r'\b(?:temp|var|phi)_(?:[asvtf]\w*|ra)\b|\bsp[0-9A-F]{1,3}\b', 'code'),
    ('addr_calls', 'files calling/declaring func_XXXXXXXX', r'\bfunc_[0-9A-F]{8}\b', 'code'),
    ('addr_data', 'files using D_XXXXXXXX', r'\bD_[0-9A-F]{8}\b', 'code'),
    ('inline_asm', 'files with inline asm', r'\b__asm__\b|\basm\s*\(', 'code'),
    ('history', 'files with matching-history comments (agent/lane/wave notes)', r'Claude agent|\blane ?[A-Z]?\d|\bwave[ -]?\d|\bw\dlane|^// history:', 'comments'),
]


def strip_comments(t):
    comments = []
    def keep(m):
        comments.append(m.group(0)); return ' ' if m.group(0).startswith('/*') else ''
    code = re.sub(r'//[^\n]*|/\*.*?\*/', keep, t, flags=re.S)
    return code, '\n'.join(comments)


def measure():
    srcs = [p for p in glob.glob(os.path.join(ROOT, 'src', '**', '*.c*'), recursive=True)
            if p.endswith(('.c', '.cpp')) and os.sep + 'lib' + os.sep not in p]
    res = {'files': len(srcs)}
    for col, *_ in CHECKS: res[col] = 0
    data_used = set()
    for p in srcs:
        code, com = strip_comments(open(p, errors='ignore').read())
        data_used.update(re.findall(r'\bD_([0-9A-F]{8})\b', code))
        for col, desc, rx, where in CHECKS:
            if re.search(rx, code if where == 'code' else com, re.M): res[col] += 1
    # function names: game functions only (sources outside src/lib)
    lib = set()
    mp = os.path.join(ROOT, 'config', 'matched.csv')
    if os.path.exists(mp):
        lib = {int(r['addr'], 16) for r in csv.DictReader(open(mp)) if r['source'].startswith('src/lib/')}
    names = [(int(r['Start'], 16), r['Name']) for r in csv.DictReader(open(os.path.join(ROOT, 'config', 'functions.csv')))]
    game = [n for a, n in names if a not in lib]
    res['functions'] = len(game)
    res['named_functions'] = sum(1 for n in game if not re.match(r'func_[0-9A-F]{8}$|junk_', n))
    named_data = sum(1 for l in open(os.path.join(ROOT, 'config', 'symbol_addrs.txt')) if 'type:data' in l)
    res['data_named'] = named_data
    res['data_unnamed'] = len(data_used)
    return res


def main():
    r = measure()
    f = r['files']
    print(f"game functions with a real name: {r['named_functions']}/{r['functions']} ({r['named_functions']/r['functions']:.1%})")
    print(f"global data: {r['data_named']} named, {r['data_unnamed']} D_XXXXXXXX still referenced")
    print(f"game source files: {f}  (src/lib excluded)")
    for col, desc, *_ in CHECKS:
        print(f"  {r[col]:5d} ({r[col]/f:6.1%})  {desc}")
    if '--record' in sys.argv:
        cols = ['date', 'functions', 'named_functions', 'data_named', 'data_unnamed', 'files'] + [c for c, *_ in CHECKS]
        rows = list(csv.DictReader(open(HIST))) if os.path.exists(HIST) else []
        today = datetime.date.today().isoformat()
        rows = [x for x in rows if x['date'] != today] + [dict(date=today, **{k: r[k] for k in cols[1:]})]
        with open(HIST, 'w', newline='') as fh:
            w = csv.DictWriter(fh, cols, lineterminator='\n'); w.writeheader(); w.writerows(rows)
        print('recorded in', os.path.relpath(HIST, ROOT))


if __name__ == '__main__':
    main()
