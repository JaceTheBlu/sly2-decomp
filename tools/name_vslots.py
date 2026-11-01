#!/usr/bin/env python3
"""Name virtual methods from their vtable slot (needs the game executable).

  name_vslots.py [--dry-run]

Reads the class table (0x2BAAE8: 199 records {parent record, cid, end of subtree, size, factory}) and every
class's vtable (the factory stores it at +0xC; 8-byte entries {short delta, short, pfn}), see docs/CLASSES.md.
For the slots whose meaning is established, the function in a slot belongs to the lowest class whose subtree holds
every class that has it there.  When that function is still func_XXXXXXXX it is named after its role and its class:
the class name from CLASSES (below) when known, else `Cid<N>` (the class number in docs/CLASSES.md), e.g.
`InitCid48`, `OnCid57Add`.  `CidNN` names are placeholders meant to be renamed when the class is identified.
Slot 5 (Handle%sMessage) rests on a single example, so it is used only when the function calls its parent's slot 5.
"""
import os, re, sys, csv, json, struct, collections, subprocess
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import matchtool as M
import objcheck as O

ROOT = M.ROOT
TABLE, NCLASS = 0x2BAAE8, 199
CLASSES = {2: 'Lo', 3: 'Alo', 9: 'Spire', 29: 'Emitter', 111: 'Sm', 115: 'Wr', 138: 'Saa', 139: 'Loop',
           140: 'Pingpong', 141: 'Shuffle', 142: 'Eyes', 143: 'Scroller', 144: 'Circler'}
LO_SLOTS = {5: 'Handle%sMessage', 7: 'Init%s', 11: 'On%sAdd', 12: 'On%sRemove', 14: 'Load%sFromBrx',
            15: 'Post%sLoad', 16: 'Update%s', 41: 'Clone%s'}
SAA_SLOTS = {8: 'Update%s', 9: 'UComplete%s'}
SECTIONS = [(0x100000, 0x259DF0, 0x80), (0x262380, 0x2AC880, 0x162400), (0x2AC880, 0x2DD230, 0x1AC900)]

ELF = open(M.ELF, 'rb').read()


def off(a):
    for lo, hi, o in SECTIONS:
        if lo <= a < hi: return a - lo + o


def W(a): return struct.unpack_from('<I', ELF, off(a))[0]


def classes():
    out = []
    for i in range(NCLASS):
        r = [W(TABLE + 20 * i + 4 * k) for k in range(5)]
        out.append(dict(cid=i, sup=(r[0] - TABLE) // 20 if r[0] else None, size=r[3], new=r[4]))
    return out


def vtable_of(new, starts):
    """vtable address from the factory's lui/addiu $v1 pair, then its entries up to the next empty entry."""
    hi = lo = None
    for k in range(12):
        w = W(new + 4 * k)
        if w >> 26 == 0xF and (w >> 16) & 31 == 3: hi = w & 0xFFFF
        if w >> 26 == 0x9 and (w >> 16) & 31 == 3 and (w >> 21) & 31 == 3: lo = (w & 0xFFFF) - ((w & 0x8000) << 1)
    if hi is None or lo is None: return None
    vt = (hi << 16) + lo; out = []
    for k in range(400):
        if off(vt + 8 * k) is None: break
        fn = W(vt + 8 * k + 4)
        if k > 0 and (fn == 0 or fn not in starts): break
        out.append(fn)
    return out


def main():
    dry = '--dry-run' in sys.argv
    rows = list(csv.DictReader(open(os.path.join(ROOT, 'config', 'functions.csv'))))
    starts = {int(r['Start'], 16): r['Name'] for r in rows}
    cl = classes()
    vt = {c['cid']: vtable_of(c['new'], starts) for c in cl if c['new']}
    vt = {k: v for k, v in vt.items() if v}

    def ancestors(c):
        out = []
        while c is not None: out.append(c); c = cl[c]['sup']
        return out

    def family(c):
        a = ancestors(c)
        return LO_SLOTS if 2 in a else SAA_SLOTS if 138 in a else None

    def lca(cids):
        common = set(ancestors(cids[0]))
        for c in cids[1:]: common &= set(ancestors(c))
        return max(common, key=lambda c: len(ancestors(c)))

    users = collections.defaultdict(list)   # (fn, slot) -> classes that have fn in that slot
    for cid, v in vt.items():
        fam = family(cid)
        if not fam: continue
        for k in fam:
            if k < len(v): users[v[k], k].append(cid)
    # call graph for the slot-5 check
    tab = O.symbol_table()
    base = json.load(open(O.BASELINE))['functions']
    def calls(a):
        fp = base.get('@%06X' % a)
        return {int(O.ident(t, tab)[1:], 16) for i, ty, t in fp[0][1] if ty == 4 and O.ident(t, tab).startswith('@')} if fp else set()
    def parent_slot(owner, k):
        for c in ancestors(owner)[1:]:
            if c in vt and k < len(vt[c]): return vt[c][k]

    aliased = {a for n, a in tab.items() if not n.startswith('func_') and a in starts}   # already has a name
    pairs = []; seen = set()
    for (fn, k), cids in sorted(users.items()):
        owner = lca(cids)
        if family(owner) is None: continue
        if k == 5 and parent_slot(owner, 5) not in calls(fn): continue
        if not re.fullmatch(r'func_[0-9A-F]{8}', starts.get(fn, '')) or fn in seen or fn in aliased: continue
        # an inherited function shows up in every subclass: only the owner names it
        par = parent_slot(owner, k)
        if par == fn: continue
        cls = CLASSES.get(owner, 'Cid%d' % owner)
        pairs.append((starts[fn], family(owner)[k] % cls)); seen.add(fn)
    names = collections.Counter(n for o, n in pairs)
    pairs = [(o, n) for o, n in pairs if names[n] == 1]   # two functions for one role of one class: leave both
    print(f'{len(pairs)} virtual methods to name')
    mp = os.path.join(ROOT, 'build', 'vslots.map')
    open(mp, 'w').write(''.join(f'{o} {n}\n' for o, n in pairs))
    for o, n in pairs[:15]: print('  ', o, n)
    if not dry and pairs:
        sys.exit(subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'rename.py'), '--map', mp]).returncode)


if __name__ == '__main__':
    main()
