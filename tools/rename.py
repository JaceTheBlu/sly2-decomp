#!/usr/bin/env python3
"""Rename functions and global data everywhere in the project.

  rename.py OLD NEW [OLD NEW ...]      e.g. rename.py func_0013DA18 LoadSwFromBrx D_003DD490 g_sw
  rename.py --map FILE                 one "OLD NEW" pair per line (# comments allowed)
  options: --dry-run      show what would change, write nothing
           --merge-used   NEW may already appear in the sources (callers that already use the name for this
                          address, see tools/resolve_names.py)

OLD is the current name of a function (func_XXXXXXXX or an existing name) or a data symbol (D_XXXXXXXX or a name
already given with type:data).  NEW is the symbol name: a plain C name (LoadSwFromBrx) or a g++ 2.95 mangled name
(LoadSwFromBrx__FP2SW) when the signature is known, as the existing names in config/symbol_addrs.txt are.

What changes:
  - config/functions.csv, config/symbol_addrs.txt (a data symbol gets a `type:data` line), config/matched.csv
  - every whole-word occurrence in src/ and include/ (code and comments)
  - a source file named after the function is renamed with it (src/hand/func_0013DA18.cpp -> LoadSwFromBrx.cpp)
NEW may be a name the same address already has in symbol_addrs.txt (an alias): the func_ name is then retired.

Renames never change the compiled code; check with `tools/objcheck.py check` afterwards anyway.
"""
import os, re, sys, csv, glob

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CFG = os.path.join(ROOT, 'config')
IDENT = re.compile(r'[A-Za-z_][A-Za-z0-9_$]*\Z')


def load_symbols():
    """name -> (address, kind) from symbol_addrs.txt and functions.csv."""
    syms = {}
    for r in csv.DictReader(open(os.path.join(CFG, 'functions.csv'))):
        syms[r['Name']] = (int(r['Start'], 16), 'func')
    for line in open(os.path.join(CFG, 'symbol_addrs.txt')):
        m = re.match(r'(\S+)\s*=\s*0x([0-9A-Fa-f]+);.*type:(\w+)', line)
        if m: syms[m.group(1)] = (int(m.group(2), 16), 'func' if m.group(3) == 'func' else 'data')
    return syms


def resolve(old, syms):
    if old in syms: return syms[old]
    m = re.fullmatch(r'D_([0-9A-Fa-f]{8})', old)
    if m: return int(m.group(1), 16), 'data'
    m = re.fullmatch(r'func_([0-9A-Fa-f]{8})', old)
    if m: return int(m.group(1), 16), 'func'
    return None


def eol(path):
    return '\r\n' if b'\r\n' in open(path, 'rb').read(4096) else '\n'


def source_files():
    return [p for d in ('src', 'include') for p in glob.glob(os.path.join(ROOT, d, '**', '*'), recursive=True)
            if os.path.isfile(p) and p.endswith(('.c', '.cpp', '.h', '.inc'))]


def main():
    args = sys.argv[1:]
    dry = '--dry-run' in args; merge = '--merge-used' in args
    args = [a for a in args if a not in ('--dry-run', '--merge-used')]
    pairs = []
    if args[:1] == ['--map']:
        for line in open(args[1]):
            line = line.split('#')[0].split()
            if line: pairs.append((line[0], line[1]))
    elif args and len(args) % 2 == 0:
        pairs = list(zip(args[::2], args[1::2]))
    else:
        print(__doc__); sys.exit(2)

    syms = load_symbols()
    files = source_files()
    text = {p: open(p, encoding='utf-8', errors='surrogateescape').read() for p in files}
    used = set()
    for t in text.values():   # identifiers in code; names that only appear in comments are fine
        code = re.sub(r'//[^\n]*|/\*.*?\*/', ' ', t, flags=re.S)
        used.update(re.findall(r'[A-Za-z_][A-Za-z0-9_$]*', code))

    errors = []; plan = []
    olds = {o for o, n in pairs}; news = [n for o, n in pairs]
    for old, new in pairs:
        r = resolve(old, syms)
        if r is None: errors.append(f'{old}: unknown symbol'); continue
        if not IDENT.match(new): errors.append(f'{new}: not a valid identifier'); continue
        alias = new in syms and syms[new][0] == r[0]   # merging into the name the address already has elsewhere
        if new in syms and new not in olds and not alias: errors.append(f'{new}: already a symbol (0x{syms[new][0]:06X})'); continue
        if new in used and new not in olds and not alias and not merge: errors.append(f'{new}: already used as an identifier in the sources'); continue
        if news.count(new) > 1: errors.append(f'{new}: given twice'); continue
        plan.append((old, new, r[0], r[1]))
    if errors:
        for e in errors: print('error:', e)
        sys.exit(1)

    sub = dict((o, n) for o, n, a, k in plan)
    word = re.compile(r'(?<![A-Za-z0-9_$])(' + '|'.join(map(re.escape, sorted(sub, key=len, reverse=True))) + r')(?![A-Za-z0-9_$])')
    changed = 0
    for p, t in text.items():
        u = word.sub(lambda m: sub[m.group(1)], t)
        if u != t:
            changed += 1
            if not dry: open(p, 'w', encoding='utf-8', errors='surrogateescape').write(u)

    moves = []
    for old, new, a, k in plan:
        for p in glob.glob(os.path.join(ROOT, 'src', '*', old + '.c')) + glob.glob(os.path.join(ROOT, 'src', '*', old + '.cpp')):
            q = os.path.join(os.path.dirname(p), new + os.path.splitext(p)[1])
            if os.path.exists(q): print(f'error: {os.path.relpath(q, ROOT)} already exists'); sys.exit(1)
            moves.append((p, q))
    relmove = {os.path.relpath(p, ROOT): os.path.relpath(q, ROOT) for p, q in moves}

    # config files
    fp = os.path.join(CFG, 'functions.csv'); rows = list(csv.reader(open(fp, newline='')))
    for r in rows[1:]:
        if r[0] in sub: r[0] = sub[r[0]]
    sp = os.path.join(CFG, 'symbol_addrs.txt'); lines = open(sp).read().split('\n')
    have = set()
    for i, l in enumerate(lines):
        m = re.match(r'(\S+)(\s*=.*)', l)
        if m and m.group(1) in sub: lines[i] = sub[m.group(1)] + m.group(2); have.add(m.group(1))
    if lines and lines[-1] == '': lines.pop()
    for old, new, a, k in plan:
        if old not in have and new not in syms:
            lines.append(f'{new} = 0x{a:06X}; // type:{"func" if k == "func" else "data"}')
    mp = os.path.join(CFG, 'matched.csv'); mrows = list(csv.reader(open(mp, newline='')))
    for r in mrows[1:]:
        if r[0] in sub: r[0] = sub[r[0]]
        if r[4] in relmove: r[4] = relmove[r[4]]

    for old, new, a, k in plan: print(f'{old} -> {new}  ({k} 0x{a:06X})')
    for p, q in moves: print(f'  move {os.path.relpath(p, ROOT)} -> {os.path.relpath(q, ROOT)}')
    print(f'{len(plan)} symbol(s), {changed} file(s) edited, {len(moves)} file(s) renamed' + (' (dry run)' if dry else ''))
    if dry: return
    fe, me = eol(fp), eol(mp)   # keep each file's line endings (read before the files are truncated)
    csv.writer(open(fp, 'w', newline=''), lineterminator=fe).writerows(rows)
    open(sp, 'w').write('\n'.join(lines) + '\n')
    csv.writer(open(mp, 'w', newline=''), lineterminator=me).writerows(mrows)
    for p, q in moves: os.rename(p, q)


if __name__ == '__main__':
    main()
