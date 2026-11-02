#!/usr/bin/env python3
"""Find the Sly 1 counterpart of Sly 2 functions, to borrow their names.  Writes config/sly1_matches.csv.

  sly1match.py SLY1_DIR [--eval | --apply]

SLY1_DIR is a checkout of https://github.com/TheOnlyZac/sly1.  Its names, file splits and C sources are used; no
Sly 1 executable is needed.  The Sly 1 C sources are compiled once (with the Sly 1 compiler, ee-gcc 2.95.2-274,
INCLUDE_ASM stubs removed) into build/sly1_obj/.  Needs build/baseline.json (tools/objcheck.py baseline) for the
Sly 2 code and call graph.

Evidence, combined over a few rounds (each round's pairs feed the next):
  anchor    the Sly 2 function already has the Sly 1 name
  content   instruction-pattern similarity (opcodes only, no registers/immediates) between a compiled Sly 1 function
            and a Sly 2 function: mutual best, clearly ahead of the runner-up
  calls     for a paired function compiled on both sides, the ordered call lists are aligned; an unknown callee
            facing an unknown callee of compatible size is paired
  gap       between two pairs that are close in both games, the functions in between are aligned on size and calls
            (Sly 2 kept the order of functions inside a source file)
  extend    walking outwards from a pair while the neighbours agree and stay in the same Sly 1 source file
--eval hides a fifth of the anchors and reports how many are found again, per method.

Output columns: sly2_addr, sly2_name, name (Sly 1 mangled name), sly1_addr, method, score (0..1, higher is safer).
"""
import os, re, sys, csv, json, glob, random, struct, shutil, subprocess, collections, bisect
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
OBJ = os.path.join(ROOT, 'build', 'sly1_obj')
CW = float(os.environ.get('SLY1_CW', 0.3))   # weight of constant agreement in the similarity
CT, CM = float(os.environ.get('SLY1_CT', 0.8)), float(os.environ.get('SLY1_CM', 0.1))   # content: min similarity, min lead
SLY1_CC = os.path.join(ROOT, 'tools', 'compilers', 'bundle', 'ee-gcc2.95.2-274')


def base_name(n):
    """Unmangled function name: LoadSwFromBrx__FP2SW -> LoadSwFromBrx."""
    m = re.match(r'(.+?)__(?:F|\d|Q|C\d)', n)
    return m.group(1) if m and not n.startswith('__') else n


def tok(w):
    """Instruction class, without registers or immediates (sq/sd and lq/ld merged: the two compilers differ there)."""
    if w == 0: return 'nop'
    op = w >> 26
    if op == 0: return 'S%d' % (w & 0x3f)
    if op == 1: return 'R%d' % ((w >> 16) & 0x1f)
    if op in (0x10, 0x11, 0x12):
        fmt = (w >> 21) & 0x1f
        return 'C%d.%d.%d' % (op, fmt, (w & 0x3f) if fmt >= 0x10 or op == 0x12 else 0)
    if op == 0x1c: return 'M%d.%d' % (w & 0x3f, (w >> 6) & 0x1f)
    return 'O%d' % {0x1F: 0x3F, 0x1E: 0x37}.get(op, op)


def consts(ws, skip):
    """Constants written in the code (lui/ori/andi/li/slti immediates, not the relocated ones): float literals
    such as 0x3F80 (1.0f) or masks survive between the two games, unlike registers and struct offsets."""
    c = collections.Counter()
    for i, w in enumerate(ws):
        if i in skip: continue
        op, rs, imm = w >> 26, (w >> 21) & 31, w & 0xFFFF
        if op == 0xF and imm: c['U%x' % imm] += 1
        elif op in (0xC, 0xD) and imm > 1: c['O%x' % imm] += 1
        elif op == 0x9 and rs == 0 and imm not in (0, 1, 0xFFFF): c['L%x' % imm] += 1
        elif op in (0xA, 0xB) and imm > 1: c['S%x' % imm] += 1
    return c


def grams(t):
    while t and t[-1] == 'nop': t = t[:-1]
    return collections.Counter(tuple(t[i:i + 3]) for i in range(len(t) - 2)), len(t)


# ---------------------------------------------------------------- Sly 1
def build_sly1_objects(d):
    """Compile the Sly 1 C sources once; INCLUDE_ASM lines are dropped (their asm comes from the Sly 1 disc)."""
    if os.path.isdir(OBJ) and glob.glob(os.path.join(OBJ, '*.o')): return
    os.makedirs(OBJ, exist_ok=True)
    tmp = os.path.join(OBJ, 'src'); shim = os.path.join(OBJ, 'shim'); os.makedirs(shim, exist_ok=True)
    open(os.path.join(shim, 'stddef.h'), 'w').write('typedef unsigned int size_t;\ntypedef int ptrdiff_t;\n#define NULL 0\n'
                                                     '#define offsetof(t,m) ((size_t)&((t*)0)->m)\n')
    open(os.path.join(shim, 'stdarg.h'), 'w').write('typedef __builtin_va_list va_list;\n'
                                                    '#define va_start(v,l) __builtin_stdarg_start((v),l)\n'
                                                    '#define va_end __builtin_va_end\n#define va_arg __builtin_va_arg\n')
    srcs = [p for p in glob.glob(os.path.join(d, 'src', '**', '*.c*'), recursive=True) if p.endswith(('.c', '.cpp'))]
    ver = os.listdir(os.path.join(SLY1_CC, 'lib', 'gcc-lib', 'ee'))[0]
    def one(p):
        rel = os.path.relpath(p, d); q = os.path.join(tmp, rel); os.makedirs(os.path.dirname(q), exist_ok=True)
        t = re.sub(r'^\s*INCLUDE_(ASM|RODATA)\(.*$', '', open(p, errors='ignore').read(), flags=re.M)
        open(q, 'w').write(t)
        o = os.path.join(OBJ, re.sub(r'[/\\]', '_', os.path.splitext(rel)[0]) + '.o')
        cmd = [os.path.join(ROOT, 'tools', 'wibo-i686'), os.path.join(SLY1_CC, 'bin', 'ee-gcc.exe'), '-c',
               '-Iinclude', '-isystem', 'include/sdk/ee', '-isystem', 'include/gcc', '-isystem', shim,
               '-x', 'c++', f'-B{SLY1_CC}/lib/gcc-lib/ee/{ver}/', '-O2', '-G0', '-ffast-math', q, '-o', o]
        for attempt in range(3):   # wibo occasionally hangs: kill the whole process group and retry
            pr = subprocess.Popen(cmd, cwd=d, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, start_new_session=True)
            try:
                pr.wait(timeout=120); break
            except subprocess.TimeoutExpired:
                os.killpg(pr.pid, 9); pr.wait()
    with ThreadPoolExecutor(os.cpu_count() or 2) as ex: list(ex.map(one, srcs))
    shutil.rmtree(tmp, ignore_errors=True)


def load_sly1_objects():
    import objcheck as O
    out = {}
    for f in glob.glob(os.path.join(OBJ, '*.o')):
        d, secs, syms, rel = O.read_obj_full(f)
        for s in syms:
            if s['type'] != 2 or s['size'] == 0 or not secs[s['shndx']]['name'].startswith('.text'): continue
            ws = struct.unpack_from('<%dI' % (s['size'] // 4), d, secs[s['shndx']]['off'] + s['value'])
            calls = [n for o, (t, n) in sorted(rel.get(s['shndx'], {}).items()) if t == 4 and s['value'] <= o < s['value'] + s['size']]
            g, n = grams([tok(w) for w in ws])
            skip = {(o - s['value']) // 4 for o in rel.get(s['shndx'], {}) if s['value'] <= o < s['value'] + s['size']}
            out[s['name']] = dict(grams=g, n=n, ocalls=calls, consts=consts(ws, skip))
    return out


def load_sly1(d):
    funcs = {}
    for l in open(os.path.join(d, 'config', 'symbol_addrs.txt')):
        m = re.match(r'\s*([A-Za-z_][^\s=]*)\s*=\s*0x([0-9A-Fa-f]+);.*type:func', l)
        if m: funcs.setdefault(int(m.group(2), 16), m.group(1))
    addrs = sorted(funcs)
    splits = []   # source file of each function, from the splat splits (rom offset 0x1000 = vram 0x100000)
    for l in open(os.path.join(d, 'config', 'sly1.yaml')):
        m = re.match(r'\s*- \[0x([0-9A-Fa-f]+),\s*(\w+),\s*([^\]\s]+)\]', l)
        if m and m.group(2) in ('c', 'cpp', 'asm'): splits.append((int(m.group(1), 16) - 0x1000 + 0x100000, m.group(3)))
    splits.sort(); starts = [s for s, n in splits]
    out = []
    for i, a in enumerate(addrs):
        k = bisect.bisect_right(starts, a)
        if k and splits[k - 1][1].startswith('sce/'): continue   # Sony SDK: out of scope
        if re.match(r'(FUN|func|sub|LAB)_[0-9A-Fa-f]+', funcs[a]): continue   # Sly 1 has no name for it either
        nxt = addrs[i + 1] if i + 1 < len(addrs) else a + 0x100
        k = bisect.bisect_right(starts, a)
        if k < len(starts): nxt = min(nxt, starts[k])
        out.append(dict(addr=a, name=funcs[a], size=nxt - a, file=splits[k - 1][1] if k else None))
    # callees by unmangled name from the C sources (matched src/ and the non-matching reference/src/)
    known = {base_name(f['name']) for f in out}
    body = {}
    for p in glob.glob(os.path.join(d, 'src', '**', '*.c*'), recursive=True) + \
             glob.glob(os.path.join(d, 'reference', 'src', '**', '*.c*'), recursive=True):
        t = re.sub(r'//[^\n]*|/\*.*?\*/', ' ', open(p, errors='ignore').read(), flags=re.S)
        for m in re.finditer(r'^[A-Za-z_][\w \*&:<>,]*?\b([A-Za-z_]\w*(?:::\w+)?)\s*\(([^;{]*)\)\s*\{', t, re.M):
            name = m.group(1).split('::')[-1]
            depth = 0; i = m.end() - 1; j = i
            for j in range(i, len(t)):
                if t[j] == '{': depth += 1
                elif t[j] == '}':
                    depth -= 1
                    if depth == 0: break
            calls = {c for c in re.findall(r'\b([A-Za-z_]\w*)\s*\(', t[i:j]) if c in known}
            if calls or j - i > 2: body.setdefault(name, set()).update(calls)
    objs = load_sly1_objects()
    NCALLERS.clear()
    for f in out:
        f['calls'] = body.get(base_name(f['name']))   # None: no source to compare with
        o = objs.get(f['name'])
        if o:
            f.update(grams=o['grams'], n=o['n'], ocalls=o['ocalls'], consts=o['consts'])
            f['calls'] = (f['calls'] or set()) | {base_name(c) for c in o['ocalls']}
    for f in out: NCALLERS.update(f['calls'] or ())
    return out


# ---------------------------------------------------------------- Sly 2
def load_sly2():
    rows = list(csv.DictReader(open(os.path.join(ROOT, 'config', 'functions.csv'))))
    junk = [(int(r['Start'], 16), int(r['End'], 16)) for r in csv.DictReader(open(os.path.join(ROOT, 'config', 'junk.csv')))]
    alias = collections.defaultdict(set)
    for l in open(os.path.join(ROOT, 'config', 'symbol_addrs.txt')):
        m = re.match(r'(\S+)\s*=\s*0x([0-9A-Fa-f]+);.*type:func', l)
        if m: alias[int(m.group(2), 16)].add(m.group(1))
    base = json.load(open(os.path.join(ROOT, 'build', 'baseline.json')))['functions']
    lib = {int(r['addr'], 16) for r in csv.DictReader(open(os.path.join(ROOT, 'config', 'matched.csv')))
           if r['source'].startswith('src/lib/')}   # Sony SDK: already named, out of scope
    out = []
    for r in rows:
        a = int(r['Start'], 16); s = int(r['Size'])
        if r['Name'].startswith('junk_') or a in lib or any(lo <= a < hi for lo, hi in junk): continue
        fp = base.get('@%06X' % a)
        calls = [] if not fp else [int(t[1:], 16) for i, ty, t in fp[0][1] if ty == 4 and t.startswith('@')]
        f = dict(addr=a, name=r['Name'], names={r['Name']} | alias[a], size=s, calls=calls)
        if fp:
            hx = fp[0][0]; ws = [int(hx[k:k + 8], 16) for k in range(0, len(hx), 8)]
            f['grams'], f['n'] = grams([tok(w) for w in ws])
            f['consts'] = consts(ws, {r[0] for r in fp[0][1]})
        out.append(f)
    out.sort(key=lambda f: f['addr'])
    return out


# ---------------------------------------------------------------- evidence
def size_score(s2, s1):
    r = min(s2, s1) / max(s2, s1)
    if s1 <= 16 or s2 <= 16: return 1.0 if abs(s1 - s2) <= 8 else -1.0
    if r > 0.9: return 2.0
    if r > 0.75: return 1.0
    if r > 0.55: return 0.0
    return -2.0


NCALLERS = collections.Counter()   # Sly 1: how many functions call each name (filled by load_sly1)
RARE = 8


def call_score(f2, f1, names2, rare_only=False):
    """+ for each Sly 2 callee whose Sly 1 name is among f1's callees (3 for a rarely called name, 1 for a common
    one such as Decref), - when f1's callees are known and none match."""
    if f1['calls'] is None: return 0.0
    known = {base_name(names2[c]) for c in f2['calls'] if c in names2}
    if not known: return 0.0
    hits = [k for k in known if k in f1['calls']]
    if not hits: return -3.0
    sc = sum(3.0 if NCALLERS[k] <= RARE else 1.0 for k in hits)
    if rare_only: sc = sum(3.0 for k in hits if NCALLERS[k] <= RARE)
    return sc


def similarity(f2, f1):
    """Opcode-pattern similarity, blended with constant agreement when both functions have constants."""
    if 'grams' not in f1 or 'grams' not in f2: return None
    a, b = f1['grams'], f2['grams']
    s = sum((a & b).values()) / max(sum(a.values()), sum(b.values()), 1)
    c1, c2 = f1.get('consts'), f2.get('consts')
    if CW and c1 and c2 and sum(c1.values()) + sum(c2.values()) >= 4:
        cs = sum((c1 & c2).values()) / max(sum(c1.values()), sum(c2.values()))
        s = (1 - CW) * s + CW * cs
    return s


def nw(xs, ys, pair, gap=-1.5):
    """Needleman-Wunsch; pair(i, j) -> score or None (forbidden).  Returns [(i, j, score)]."""
    n, m = len(xs), len(ys); NEG = -1e9
    S = [[0.0] * (m + 1) for _ in range(n + 1)]; B = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1): S[i][0] = i * gap; B[i][0] = 1
    for j in range(1, m + 1): S[0][j] = j * gap; B[0][j] = 2
    P = {}
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            p = pair(i - 1, j - 1); P[i, j] = p
            S[i][j], B[i][j] = max((S[i - 1][j - 1] + p if p is not None else NEG, 0), (S[i - 1][j] + gap, 1), (S[i][j - 1] + gap, 2))
    i, j, out = n, m, []
    while i > 0 or j > 0:
        b = B[i][j]
        if b == 0: out.append((i - 1, j - 1, P[i, j])); i -= 1; j -= 1
        elif b == 1: i -= 1
        else: j -= 1
    return out[::-1]


class Matcher:
    def __init__(self, L2, L1, hidden=()):
        self.L2, self.L1 = L2, L1
        self.res = {}; self.used = {}
        self.by1 = {}
        for j, f in enumerate(L1): self.by1.setdefault(f['name'], j)
        cnt = collections.Counter(base_name(f['name']) for f in L1)
        for j, f in enumerate(L1):
            if cnt[base_name(f['name'])] == 1: self.by1.setdefault(base_name(f['name']), j)
        self.idx2 = {f['addr']: i for i, f in enumerate(L2)}
        cnt2 = collections.Counter(base_name(n) for f in L2 for n in f['names'])
        for i, f in enumerate(L2):
            for n in sorted(f['names']):
                if n in hidden or n.startswith('func_'): continue
                j = self.by1.get(n)
                if j is None and cnt2[base_name(n)] == 1: j = self.by1.get(base_name(n))   # overloads: exact names only
                if j is not None and j not in self.used: self.add(i, j, 'anchor', 1.0); break

    def add(self, i, j, method, score):
        if i in self.res or j in self.used: return False
        self.res[i] = (j, method, score); self.used[j] = i; return True

    def names2(self):
        return {self.L2[i]['addr']: self.L1[j]['name'] for i, (j, *_) in self.res.items()}

    def content(self):
        L2s = sorted((f['n'], i) for i, f in enumerate(self.L2) if 'grams' in f)
        ns = [n for n, i in L2s]
        best1 = {}; best2 = collections.defaultdict(list)
        for j, g in enumerate(self.L1):
            if 'grams' not in g or g['n'] < 8 or j in self.used: continue
            lo, hi = bisect.bisect_left(ns, g['n'] * 0.7), bisect.bisect_right(ns, g['n'] * 1.4)
            sc = sorted(((similarity(self.L2[i], g), i) for n, i in L2s[lo:hi] if i not in self.res), reverse=True)[:2]
            if not sc: continue
            best1[j] = sc
            best2[sc[0][1]].append((sc[0][0], j))
        n = 0
        for j, sc in best1.items():
            s, i = sc[0]; s2 = sc[1][0] if len(sc) > 1 else 0
            # the Sly 1 runner-up for this Sly 2 function must also be clearly behind (sibling functions such as
            # AddVifMscal / AddVifMscalf look alike)
            rival = max((similarity(self.L2[i], g) or 0 for k, g in enumerate(self.L1)
                         if k != j and 'grams' in g and k not in self.used and abs(g['n'] - self.L2[i]['n']) < 0.4 * g['n'] + 4),
                        default=0) if s >= CT and s - s2 >= CM else 1
            if s >= CT and s - s2 >= CM and s - rival >= CM and max(best2[i])[1] == j:
                n += self.add(i, j, 'content', round(min(0.99, 0.6 + s / 3), 2))
        return n

    def calls(self):
        names2 = self.names2(); votes = collections.defaultdict(collections.Counter)
        for i, (j, *_) in list(self.res.items()):
            c1 = self.L1[j].get('ocalls'); c2 = self.L2[i]['calls']
            if not c1 or not c2: continue
            def pair(a, b):
                x, y = c2[a], c1[b]
                if x in names2: return 4.0 if names2[x] == y else None
                if y in self.by1 and self.by1[y] in self.used: return None
                k = self.by1.get(y); ix = self.idx2.get(x)
                if k is None or ix is None: return None
                return size_score(self.L2[ix]['size'], self.L1[k]['size'])
            for a, b, p in nw(c2, c1, pair, gap=-1.0):
                x, y = c2[a], c1[b]
                if x not in names2 and p is not None and p >= 1 and y in self.by1: votes[x][y] += 1
        n = 0
        for x, c in votes.items():
            (y, v), = c.most_common(1)
            ix, k = self.idx2[x], self.by1[y]
            # one caller is not enough on its own: also want a close size, or the code itself to agree
            if len(c) == 1 and (v >= 2 or self.evidence(self.L2[ix], self.L1[k], names2)
                                or (v == 1 and size_score(self.L2[ix]['size'], self.L1[k]['size']) == 2 and self.L1[k]['size'] > 32)):
                n += self.add(ix, k, 'calls', round(min(0.95, 0.6 + 0.1 * v), 2))
        return n

    def gaps(self):
        names2 = self.names2(); n = 0
        pairs = sorted((i, j) for i, (j, *_) in self.res.items())
        for (i0, j0), (i1, j1) in zip(pairs, pairs[1:]):
            g2, g1 = i1 - i0 - 1, j1 - j0 - 1
            if g2 <= 0 or g1 <= 0 or g1 > 3 * g2 + 8 or g2 > 3 * g1 + 8 or g1 > 150: continue
            idx2 = [k for k in range(i0 + 1, i1) if k not in self.res]
            idx1 = [k for k in range(j0 + 1, j1) if k not in self.used]
            if not idx2 or not idx1: continue
            if self.L1[j0]['file'] != self.L1[j1]['file'] and g1 != g2: continue
            pair = lambda a, b: self.pair_score(self.L2[idx2[a]], self.L1[idx1[b]], names2)
            al = nw(idx2, idx1, pair)
            exact = g1 == g2 and len(idx2) == len(idx1) == len(al) and all(a == b for a, b, _ in al)
            for a, b, p in al:
                if p is None or p < (0 if exact else 1): continue
                # functions can swap places inside a source file between the two games: reject a pair when another
                # function of the same gap fits clearly better (either way round)
                alt = max([pair(a, x) or -9 for x in range(len(idx1)) if x != b] +
                          [pair(y, b) or -9 for y in range(len(idx2)) if y != a] + [-9])
                if alt > p + 0.5: continue
                ev = self.evidence(self.L2[idx2[a]], self.L1[idx1[b]], names2)
                if not exact and not ev: continue
                # an exact gap of several functions only fixes the order, which can change: want evidence too
                if exact and len(idx2) > 1 and (p < 1 or not ev): continue
                n += self.add(idx2[a], idx1[b], 'gap', round(min(0.95, (0.85 if exact else 0.55) + min(p, 5) / 50), 2))
        return n

    def pair_score(self, f2, f1, names2):
        p = size_score(f2['size'], f1['size']) + call_score(f2, f1, names2)
        s = similarity(f2, f1)
        if s is not None: p += 4 * (s - 0.5)
        return p

    def evidence(self, f2, f1, names2):
        """Something beyond size says these two are the same function."""
        s = similarity(f2, f1)
        return (s is not None and s >= 0.6) or call_score(f2, f1, names2, rare_only=True) > 0

    def extend(self):
        names2 = self.names2(); n = 0
        for i, (j, *_) in sorted(self.res.items()):
            for step in (1, -1):
                a, b = i + step, j + step
                while 0 <= a < len(self.L2) and 0 <= b < len(self.L1) and a not in self.res and b not in self.used \
                        and self.L1[b]['file'] == self.L1[j]['file']:
                    p = self.pair_score(self.L2[a], self.L1[b], names2)
                    if p < 2 or not self.evidence(self.L2[a], self.L1[b], names2): break
                    self.add(a, b, 'extend', round(0.5 + min(p, 5) / 20, 2)); n += 1
                    names2[self.L2[a]['addr']] = self.L1[b]['name']
                    a += step; b += step
        return n

    def run(self):
        for rnd in range(6):
            got = self.content() + self.calls() + self.gaps() + self.extend()
            if not got: break
        return self.res


def apply(L2, L1, res):
    """Rename the func_ functions that got a Sly 1 partner (tools/rename.py), except: addresses that already have
    another name in symbol_addrs.txt, names listed in config/sly1_rejects.txt, Sly 1 placeholder names."""
    rej = {l.split('#')[0].split()[0] for l in open(os.path.join(ROOT, 'config', 'sly1_rejects.txt'))
           if l.split('#')[0].strip()}
    alias = collections.defaultdict(set)
    for l in open(os.path.join(ROOT, 'config', 'symbol_addrs.txt')):
        m = re.match(r'(\S+)\s*=\s*0x([0-9A-Fa-f]+);.*type:func', l)
        if m: alias[int(m.group(2), 16)].add(m.group(1))
    pairs = []
    for i, (j, m, sc) in sorted(res.items()):
        f, n = L2[i], L1[j]['name']
        if not re.fullmatch(r'func_[0-9A-F]{8}', f['name']) or alias[f['addr']] - {f['name']}: continue
        if n in rej or re.match(r'Unknown\d', n): continue
        pairs.append((f['name'], n, m, sc))
    mp = os.path.join(ROOT, 'build', 'sly1_names.map')
    open(mp, 'w').write(''.join(f'{o} {n}  # {m} {sc}\n' for o, n, m, sc in pairs))
    print(f'{len(pairs)} names to apply ({mp})')
    if pairs: sys.exit(subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'rename.py'), '--map', mp]).returncode)


def main():
    if len(sys.argv) < 2: print(__doc__); sys.exit(2)
    build_sly1_objects(sys.argv[1])
    L1 = load_sly1(sys.argv[1]); L2 = load_sly2()
    if '--eval' in sys.argv:
        truth = {i: j for i, (j, m, s) in Matcher(L2, L1).res.items()}
        names = sorted(L2[i]['name'] for i in truth)
        random.seed(int(os.environ.get('SLY1_SEED', 1))); hidden = set(random.sample(names, len(names) // 5))
        res = Matcher(L2, L1, hidden).run()
        stats = collections.Counter()
        for i, j in truth.items():
            if L2[i]['name'] in hidden:
                stats[(res[i][1], res[i][0] == j) if i in res else ('not found', True)] += 1
        print(f'hidden anchors: {len(hidden)}; ' + ', '.join(f'{m} {"right" if ok else "WRONG"} {n}' if m != 'not found' else f'not found {n}'
                                                           for (m, ok), n in sorted(stats.items())))
        return
    res = Matcher(L2, L1).run()
    if '--apply' in sys.argv:
        return apply(L2, L1, res)
    rows = [(f'0x{L2[i]["addr"]:06X}', L2[i]['name'], L1[j]['name'], f'0x{L1[j]["addr"]:06X}', m, s) for i, (j, m, s) in sorted(res.items())]
    with open(os.path.join(ROOT, 'config', 'sly1_matches.csv'), 'w', newline='') as fh:
        w = csv.writer(fh, lineterminator='\n'); w.writerow(['sly2_addr', 'sly2_name', 'name', 'sly1_addr', 'method', 'score']); w.writerows(rows)
    c = collections.Counter(r[4] for r in rows)
    print(f'{len(rows)} Sly 2 functions paired with Sly 1: ' + ', '.join(f'{k} {v}' for k, v in sorted(c.items())))
    print(f'new names (Sly 2 still func_): {sum(1 for r in rows if r[1].startswith("func_"))}')


if __name__ == '__main__':
    main()
