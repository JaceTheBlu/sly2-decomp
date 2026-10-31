#!/usr/bin/env python3
"""Give an address to every symbol the sources use by name but symbol_addrs.txt does not know.

  resolve_names.py            report
  resolve_names.py --apply    register the consistent ones (see below)

Many sources call or reference symbols by name (InitTag__4CRefi, g_clock...) that have no entry in
config/symbol_addrs.txt, so no tool checks that the name really means the address the original code uses.  For each
relocation to such a name, the original instruction (disc/SCUS_973.16) gives the real target:
  jal NAME              target field of the original jal
  %hi(NAME)/%lo(NAME)   the original lui/addiu (or load/store) pair
minus the addend the object carries (references like NAME+8).  A name is consistent when every use agrees.

--apply, for each consistent name:
  - the address is a function whose name is func_XXXXXXXX: rename it to NAME everywhere (tools/rename.py)
  - the address already has another name: add NAME as an alias line in symbol_addrs.txt
  - data: add `NAME = 0xADDR; // type:data`
Needs build/baseline.json (tools/objcheck.py baseline) and the game executable.
"""
import os, re, sys, csv, json, struct, collections, subprocess
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import matchtool as M
import objcheck as O

ROOT = M.ROOT


def orig_word(addr):
    return M.target_words(addr, 4)[0]


def s16(x): return x - 0x10000 if x & 0x8000 else x


def collect():
    tab = O.symbol_table()
    base = json.load(open(O.BASELINE))['functions']
    uses = collections.defaultdict(collections.Counter)   # name -> {address: count}
    kinds = collections.defaultdict(set)
    elf = open(M.ELF, 'rb').read()
    def word(a):
        o = a - M.TEXT_VA + M.TEXT_OFF
        return struct.unpack_from('<I', elf, o)[0]
    for k, vs in base.items():
        if not k.startswith('@'): continue
        fa = int(k[1:], 16)
        hx, rel = vs[0]
        objw = [int(hx[i:i + 8], 16) for i in range(0, len(hx), 8)]
        pending_hi = {}
        for idx, ty, name in rel:
            n = O.ident(name, tab)
            a = fa + 4 * idx
            if ty == 4:
                if n.startswith('@'): continue
                w = word(a)
                tgt = ((w & 0x3FFFFFF) << 2) | (a & 0xF0000000)
                add = (objw[idx] & 0x3FFFFFF) << 2
                uses[n][tgt - add] += 1; kinds[n].add('func')
            elif ty == 5:
                pending_hi[name] = idx
            elif ty == 6 and name in pending_hi:
                if n.startswith('@') or n.startswith('.') or n.startswith('$'): continue
                hi = pending_hi[name]
                full = ((word(fa + 4 * hi) & 0xFFFF) << 16) + s16(word(a) & 0xFFFF)
                add = ((objw[hi] & 0xFFFF) << 16) + s16(objw[idx] & 0xFFFF)
                uses[n][(full - add) & 0xFFFFFFFF] += 1; kinds[n].add('data')
    return uses, kinds


JUNK = re.compile(r'(FUN_|D_|__snD|func_|sub_|\$|_\$tmp|\.|jtbl)|.*\.\d+$|_vt\$\d[A-Z]\w{0,2}$')


def sly1_names(d):
    if not d: return set()
    t = open(os.path.join(d, 'config', 'symbol_addrs.txt')).read()
    names = set(re.findall(r'^\s*([A-Za-z_][^\s=]*)\s*=\s*0x[0-9A-Fa-f]+;', t, re.M))
    return names | {re.split(r'__(?=[FQ0-9])', n)[0] for n in names}


def main():
    sly1 = sly1_names(sys.argv[sys.argv.index('--sly1') + 1] if '--sly1' in sys.argv else None)
    uses, kinds = collect()
    by_csv = {int(r['Start'], 16): r['Name'] for r in csv.DictReader(open(os.path.join(ROOT, 'config', 'functions.csv')))}
    ok, bad = [], []
    for n, c in sorted(uses.items()):
        if n.startswith('_GLOBAL_'): continue
        if len(c) == 1: ok.append((n, next(iter(c)), sum(c.values())))
        else: bad.append((n, c))
    print(f'{len(ok)} names used consistently, {len(bad)} used for several addresses (not touched)')
    for n, c in bad: print('  several addresses:', n, ' '.join(f'0x{a:06X}x{k}' for a, k in c.most_common(4)))
    count = {n: k for n, a, k in ok}
    renames = collections.defaultdict(list); aliases = []; data = []
    for n, a, k in ok:
        if 'func' in kinds[n]:
            cur = by_csv.get(a)
            if cur is None: print('  not a function start:', n, hex(a)); continue
            known = n in sly1 or re.split(r'__(?=[FQ0-9])', n)[0] in sly1
            if re.fullmatch(r'func_[0-9A-F]{8}', cur) and known and not JUNK.match(n): renames[cur].append(n)
            elif not JUNK.match(n): aliases.append((n, a, cur))
        elif not JUNK.match(n):
            if M.TEXT_VA <= a < M.TEXT_VA + M.TEXT_SIZE:   # a function's address taken (callbacks): a function name
                if a in by_csv: aliases.append((n, a, by_csv[a]))
            else: data.append((n, a))
    final = []
    for old, names in renames.items():   # one address under several names (overloads): most used wins, rest alias
        names.sort(key=lambda x: (-count[x], x))
        final.append((old, names[0]))
        aliases += [(x, int(old[5:], 16), names[0]) for x in names[1:]]
    print(f'{len(final)} func_ renames (name known in Sly 1), {len(aliases)} aliases, {len(data)} data names')
    if '--apply' not in sys.argv:
        for old, new in final: print('   rename', old, new)
        for n, a, cur in aliases: print('   alias ', n, hex(a), '=', cur)
        for n, a in data: print('   data  ', n, hex(a))
        return
    if final:
        mp = os.path.join(ROOT, 'build', 'resolve_names.map')
        open(mp, 'w').write(''.join(f'{o} {n}\n' for o, n in final))
        r = subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'rename.py'), '--merge-used', '--map', mp])
        if r.returncode: sys.exit(r.returncode)
    # data: a D_XXXXXXXX name for the same address elsewhere becomes the real name
    used = set()
    for root, ds, fs in os.walk(os.path.join(ROOT, 'src')):
        for f in fs: used.update(re.findall(r'\bD_[0-9A-F]{8}\b', open(os.path.join(root, f), errors='ignore').read()))
    pairs = [(f'D_{a:08X}', n) for n, a in data if f'D_{a:08X}' in used]
    if pairs:
        mp = os.path.join(ROOT, 'build', 'resolve_data.map')
        open(mp, 'w').write(''.join(f'{o} {n}\n' for o, n in pairs))
        r = subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'rename.py'), '--merge-used', '--map', mp])
        if r.returncode: sys.exit(r.returncode)
    sp = os.path.join(ROOT, 'config', 'symbol_addrs.txt')
    t = open(sp).read().rstrip('\n') + '\n'
    have = set(re.findall(r'^(\S+)\s*=', t, re.M))
    for n, a, cur in aliases:
        if n not in have: t += f'{n} = 0x{a:06X}; // type:func  name used in sources for {cur}\n'; have.add(n)
    for n, a in data:
        if n not in have: t += f'{n} = 0x{a:06X}; // type:data\n'; have.add(n)
    open(sp, 'w').write(t)
    print('applied')


if __name__ == '__main__':
    main()
