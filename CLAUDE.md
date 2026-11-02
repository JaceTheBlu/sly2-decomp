# Sly 2 decomp — readability work

The decompilation is complete (all 6,662 functions match byte for byte). The current project is making the code
human-readable without losing a single match. Plan, estimates and phases: [`docs/READABILITY_PLAN.md`](docs/READABILITY_PLAN.md).
Compiler facts and matching techniques: [`docs/MATCHING_NOTES.md`](docs/MATCHING_NOTES.md).
Conventions for editing sources: [`src/CLAUDE.md`](src/CLAUDE.md).

Write code, comments, commit messages and docs in English.

## Golden rule

Every commit keeps every compiled function identical. Check before committing:

```
python3 tools/objcheck.py check          # recompiles the sources changed since the baseline commit
python3 tools/objcheck.py check --all    # everything (~3 min on 4 cores)
```

`0 problem(s)` is the only acceptable result. objcheck compares raw object words plus every relocation target
(resolved to an address), against `build/baseline.json`. Since every function in the baseline matches the game, a
change that objcheck accepts cannot break a match. It needs the compilers but **not** the game executable.
`tools/hooks/pre-commit` runs it automatically (install: `ln -s ../../tools/hooks/pre-commit .git/hooks/pre-commit`).

Where the game executable is available (`disc/SCUS_973.16`), `python3 tools/progress.py` must still say 6,662/6,662.

## Setup (fresh container, no disc)

```
bash tools/setup_all.sh                                  # compilers, wibo, m2c (the ISO step is skipped)
python3 -m pip install --break-system-packages rabbitizer
python3 tools/objcheck.py baseline                       # on a clean tree that matches; writes build/baseline.json
```

`build/` is git-ignored: regenerate the baseline in each new container, from a commit that is known to match (any
commit of this branch so far). Do not regenerate it on a dirty tree you have not checked.

## Tools added for this work

| Tool | Use |
|---|---|
| `tools/objcheck.py baseline / check [SRC…] / check --all` | safety net described above |
| `tools/rename.py OLD NEW […]` / `--map FILE` / `--dry-run` | rename a function or global everywhere (config, sources, file names). NEW may be an existing alias at the same address |
| `tools/readability.py [--record]` | readability metrics; `--record` appends to `config/readability_history.csv` |
| `tools/clean_history.py` | strip agent/lane/wave attributions from comments (already applied) |
| `tools/sly1match.py SLY1_DIR [--eval]` | pair Sly 2 functions with Sly 1 counterparts → `config/sly1_matches.csv` |
| `tools/migrate_struct.py STRUCT HEADER [--dry-run] [FILE…]` | replace local re-declarations of a struct by the shared header (fields matched by offset) |
| `tools/dedupe_inlines.py [--dry-run] [FILE…]` | replace local copies of the include/vu0.h helpers |
| `tools/consolidate.py STRUCT` | merge all local definitions of a struct by offset (draft a canonical layout) |
| `tools/name_vslots.py [--dry-run]` | name virtual methods from their vtable slot and class (`InitCid48` until the class is named) |
| `tools/migrate_cref.py [--dry-run]` | replace local C++ CRef classes by include/cref.h |
| `tools/resolve_names.py [--sly1 DIR] [--apply]` | give addresses to names the sources use without one (needs the executable) |

## Progress log

Newest first. Each entry: what changed, how it was verified, the metrics after it.

### 2026-11-01 — CRef as a shared C++ class

- `include/cref.h` now gives C++ sources the CRef class (anonymous union `m_tag`/`m_p`/`m_g`; inline default and
  tag constructors, destructor calling Decref; copy constructor, Decref, InitTag and the operator= overloads only
  declared). C sources, and C++ sources that `#define CREF_PLAIN` first, get the bare layout: 9 sources that had
  been migrated to the bare struct handle CRef as plain data, and giving them the class changed their code
  (objcheck: 7 differences), so they define CREF_PLAIN.
- `include/vtable.h`: VTE, one g++ 2.95 vtable entry {delta, index, pfn}. 90 files whose local VTE (or `VT`, the
  same entry under another name) holds a `void *` migrated. Files whose VTE holds a typed function pointer (322)
  keep it: a shared `void *pfn` would need a cast at every virtual call, which reads worse.
- migrate_struct.py: a stand-in array over several fields (`float a[16]`) is mapped element by element when every
  index is constant; a scalar stand-in can map to an element of a canonical array (`r24` → `art[3]`); asserts on
  `FIELD_OFFSET`/`offsetof` of the stand-in are removed with it. Second pass over all shared types: 19 more files.
- Local definitions left (2026-11-02): CLOCK 20, CRef 138, DL 18, DLI 15, DLE 9, LM 6, RGBA 28, VTE 327 (typed
  function pointers), VT 106, M3 43, M4 49, VU_FLOAT 67 (C++ classes with asm constructors). What is left needs
  hand edits: wrong-struct field names after a rename, unaligned stand-ins embedded in other structs, classes with
  methods.
- `FRAME` (65 local classes) is the matchers' stand-in for STACKSCOPE: a shared `STACKSCOPE` class would give its
  inline constructor the real function's symbol (`__10STACKSCOPE`) and make it call itself, so it stays.
- `tools/migrate_cref.py`: converts local C++ CRef classes whose members/methods are all in cref.h; renames
  `.u.n/.u.g/.u.pv` to `m_tag/m_g/m_p`. 114 files; objcheck 0.
- Tried on the unknown slots of the LO vtable: their Sly 1 counterparts are not decompiled, and the Sly 2 code
  (flag bits, list handling) differs too much from Sly 1's AddLo/RemoveLo to name slots 8–10 and 13 safely.
- Tried for class names: aliases and typed declarations of the `CidNN` methods give almost nothing (one vote for
  RIPG on cid 48, one for GOMER on 56).

### 2026-11-01 — Virtual methods named by role (tools/name_vslots.py)

- `tools/name_vslots.py` (needs the executable) reads the class table and vtables, assigns each function in an
  established slot to the lowest class whose subtree holds every class that has it there, and names `func_` ones
  after the role: `Init%s`, `On%sAdd`, `Load%sFromBrx`, `Post%sLoad`, `Update%s`, `Clone%s`… with the class name
  when known, else `Cid<N>` (the cid in docs/CLASSES.md): `InitCid48`, `OnCid57Add`. `CidNN` is a placeholder to be
  renamed (`rename.py`) once the class is identified.
- Validation: the overrides call their parent's function in the same slot in 35/40 Init, 21/26 PostLoad, 6/6 OnAdd,
  10/10 OnRemove, 18/25 Load, 14/15 Clone, 14/20 Update cases. Slot 5 (Handle%sMessage) only with that parent call.
- 145 functions named. objcheck 0. sly1match.py re-run with the new anchors found nothing new.

### 2026-11-01 — Matrices: MATRIX3/MATRIX4 shared, M3/M4 stand-ins retired

- `include/mat.h`: MATRIX3/MATRIX4 are unions of the two views the code uses, `float mat[n][4]` (scalar code) and
  `vu0_qword r[n]` (VU0 code), 16-byte aligned as before.
- migrate_struct.py: 16-byte quadword fields (kind `q`), alignment attributes after the closing brace, and
  `--as LOCAL` to migrate a stand-in with another name (`M3` → `MATRIX3`, type name rewritten in the file; files
  that already use the real name are skipped).
- MATRIX3/MATRIX4 users and M3/M4 stand-ins: 123 files converted, 22 that no longer built left as they were.
- `vec.h` VECTOR gains the 4th lane `w` (many stand-ins use it; size and alignment unchanged); new
  `include/vecmat.h` with VU_FLOAT/VU_VECTOR (not in vu0.h: 222 includers define their own C++ VU_FLOAT classes).
  Users migrated (~25 files). objcheck caught 2 files whose 12-byte unaligned VECTOR stand-in is embedded in
  another struct: the real 16-byte VECTOR shifts the fields after it, so those files keep their stand-in for now
  (the embedding struct's layout must be fixed first).

### 2026-11-01 — Phase 4 started: shared VU0/scalar helpers

- `include/vu0.h`: GetX/GetY/GetZ (lanes of a quadword in a GPR), QwAdd/QwSub (vadd/vsub.xyzw), QwFromG (qmtc2.ni),
  GMax/GMin/NMin/NMax. Its quadword type is `vu0_qword` (a typedef with its own name: C forbids repeating the
  sources' `typedef … qword`; `#define`-ing the type broke gcc 2.95, which applied the mode attribute to the
  function).
- `tools/dedupe_inlines.py`: a one-line local `static inline` helper is replaced only when it is the same text as
  a vu0.h helper (positional parameter names, whitespace, inline/__inline__ and qword spellings ignored); calls
  are renamed (`Sub` → `QwSub`). Files that keep another definition of the name (C++ overloads) are skipped.
  A first version treated the `VV` wrapper type as `qword`: objcheck showed 3 code changes, now excluded.
- 149 files, ~240 local helper copies removed. objcheck 0; progress.py 6,662/6,662.
- Second pass: identifiers renamed outside string literals only (locals named `f`/`r`/`x` now merge), `$zero` =
  `$0`; added QwScaleX, QwMin/QwMax (vmini/vmax.xyz), QwToVf/GFromVf (qmtc2/qmfc2.ni), GAbs (fabsf), GSqrt
  (sqrt.s). 110 more files, 181 copies. A file that already defined its own `GAbs` (a comparison, not fabsf)
  conflicted with the new helper: its local copy is now `GAbsCmp`.
- Tried and dropped: naming classes by comparing each unknown class's own slot functions with Sly 1 classes' (sizes
  plus code similarity): SPIRE barely beat TARGET and SM/WR/ALO came out wrong.

### 2026-11-01 — Class tree and virtual slots

- `docs/CLASSES.md`: the 199 classes from the class table (parent, size, vtable, slot count) with name evidence.
  Named with confidence: LO (2), ALO (3), SPIRE (9), EMITTER (29), SM (111), WR (115), SAA family (138–144).
  `SO` is not under `ALO` in Sly 2 (the STEP family sits under cid 48, a child of LO).
- Slot meanings established (LO family: 5 Handle%sMessage, 7 Init%s, 11/12 On%sAdd/Remove, 14 Load%sFromBrx,
  15 Post%sLoad, 16 Update%s, 41 Clone%s; SAA: 8 Update%s, 9 UComplete%s): every already-named slot function fits,
  and overrides call the parent's function in the same slot (InitEmitter → InitAlo → InitLo). 13 functions named
  from them (InitLo, OnLoAdd, LoadAloFromBrx, CloneEmitter…). objcheck 0.
- Next: name more classes (vtable evidence, Sly 1 order where it is kept), then each new class names its own slots.

### 2026-10-31 — Phase 2: small shared types

- New headers: `dl.h` (DL, DLE, DLI), `util.h` (LM, RGBA), `cref.h` (CRef with an anonymous union, accepted by
  ee-gcc 2.95 in C and C++; `splicewrap.h` now includes it). Field names follow Sly 1.
- migrate_struct.py: typedef'd definitions, `struct X *` fields, field kind check (float/pointer/int), union
  members as candidates, removal of static asserts on the stand-in's size; renames are no longer held back by
  same-named fields of other structs (a wrong rename cannot build or keep the code; objcheck reports both).
- tools/consolidate.py: merges every local definition of a struct by offset, with name votes and conflicts, to
  draft a canonical layout.
- Local definitions left: CLOCK 322 → 28, DL 41 → 18, DLI 28 → 15, DLE → 9, LM 43 → 7, RGBA 45 → 28,
  CRef 349 → 203 (the rest are C++ classes with methods or unusual layouts). objcheck 0; progress.py 6,662/6,662.
- What does not automate: the big classes. Local `LO` definitions (106) are stand-ins for many different derived
  classes; `VTE` (386) and `VT` (139) carry function-pointer types that differ per file; `M3`/`M4`/`NODE`/`OBJ`/`VE`
  are names matchers invented per file. These need per-class work (see next steps).

### 2026-10-31 — Phase 2 pilot: CLOCK in a shared header

- `include/clock.h`: the Sly 2 `CLOCK` (0x60 bytes, worked out from `MarkClockTick`/`StartupClock`/`TickNow`:
  game/real/frame times and steps, nine rates `art[9]` set by `SetClockRate`, 64-bit tick built from the COUNT
  register and its wrap count). Named `g_clock` (was `D_002DDED0`), `MarkClockTick__FP5CLOCKi`,
  `StartupClock__Fv`, `TickNow__FP5CLOCK`.
- `tools/migrate_struct.py`: replaces simple local re-declarations by the header, matching fields by offset and
  renaming accesses (`.time` → `.t`). CLOCK: 251 files migrated; 21 failed to compile (static asserts on
  `sizeof(CLOCK)`, unusual accesses) and were reverted; none changed code. Local CLOCK definitions: 322 → 92.
- Verified: objcheck --all 0 problems; progress.py with the executable 6,662/6,662.
- Lesson: a canonical struct can be larger than the local stand-ins without changing code (no file used
  `sizeof`, except the ones with static asserts, which fail loudly).

### 2026-10-31 — Game executable available; by-name symbols resolved

- `disc/SCUS_973.16` provided by the owner (SHA-1 checked, git-ignored). `tools/progress.py`: 6,662/6,662.
- `tools/resolve_names.py` reads the original `jal` / `%hi`+`%lo` target of every relocation to a name with no
  address. 497 names are used consistently, 20 are used for several addresses (local stand-in classes `X`, `Y`,
  `O`… reused with different meanings; two copies of `__clz_tab`). Applied:
  - 111 `func_` addresses renamed (the name also exists in Sly 1), the other names registered as aliases, so every
    name written in the sources now has its address checked;
  - 46 global data names (`g_pdliFirst`, `g_heapSw`, `s_smpChase*`, vtables `_vt$4DMAS`…, SDK internals), 24 `D_`
    names replaced by them.
- Kept `func_001AE478` (STACKSCOPE constructor): renaming it to `__5FRAME` made local classes' inline
  constructors, which compile to that very symbol, call themselves. objcheck caught it.
- objcheck: a symbol is compared with its own baseline in the same source first (inline copies of a named function
  are no longer compared with the real one).
- `docs/NAMING_REVIEW.md`: 280 matcher-chosen names for `func_` addresses, 40 names that contradict the existing
  name of their address, 10 names used for several addresses. To review by hand.

- sly1match.py, second round: constants (lui/ori/li immediates) blended into the code similarity; a call in common
  counts as evidence only when few Sly 1 functions call that name (Decref is called everywhere); a gap of several
  functions needs evidence beyond order (functions swap places inside a file between the games). Self-test: no
  mistake over 8 draws (~430 re-found pairs). `--apply` renames, skipping `config/sly1_rejects.txt` (reviewed
  rejects, with reasons). 15 more names (SetCm*Clip/Fog, InitCoin, SetBifk__4CRef4BIFK…).
- Vtables found: the class table at 0x2BAAE8 (199 records of 20 bytes: super, cid, end of subtree, object size,
  factory function); each factory stores the class's vtable (8-byte entries `{short delta, pfn}`, vptr at +0xC).
  Slot 6 returns the class record (used by `FIsBasicDerivedFrom`). Only 13 classes can be identified from methods
  that already have names, and the executable has no class-name strings (no RTTI names, Splice names live in the
  game data, not the ELF), so vtable naming is postponed until more methods are named.

Metrics: 553/6,136 game functions named (9.0%), 46 globals named, 2,374 `D_` left.

### 2026-10-31 — Phase 1 started: Sly 1 names

- `tools/sly1match.py` pairs Sly 2 functions with Sly 1 ones from a `TheOnlyZac/sly1` checkout (names, splat file
  splits, and its C sources compiled with the Sly 1 compiler into `build/sly1_obj/`). Evidence: same name, opcode
  similarity, aligned call lists, order inside a Sly 1 source file. `--eval` hides 20% of the anchors: over six
  draws (~200 re-found pairs) it made no mistake. Looser settings were tried and rejected (1–3 mistakes per draw).
- Applied 79 names (`config/sly1_matches.csv` keeps method and score of each). All were read against the code;
  rejected `_$_4CRef` and `SetCmPosMat` (code does something else). Skipped 8 addresses that already have an alias
  in `symbol_addrs.txt`.
- `main` stays `func_001A7518`: gcc compiles a function named `main` differently (objcheck caught it).
- objcheck fixes: (1) relocation targets that resolve to no address were all normalised to one placeholder, so any
  two compared equal: now compared by exact name; (2) C++-linkage calls to `func_X` (`func_0011CF60__Ff`) resolve
  to the address in the name; (3) baseline names are re-resolved with today's symbol table, so a name gaining an
  address is not reported as a change. Baseline regenerated at `a2b07c1`.
- Found: 461 functions are called by name in the sources (1,511 calls, e.g. `InitTag__4CRefi` 88×,
  `FIsBasicDerivedFrom__FP5BASIC3CID` 74×) but have no address in `symbol_addrs.txt`: nothing checks those names
  today, and a full link would fail on them. With the game executable each one can be resolved from the original
  `jal` target (see next steps).

Metrics: 430/6,136 game functions named (7.0%).

### 2026-10-30 — Phase 0 (tooling) done, first names

- Added objcheck, rename, readability, clean_history, pre-commit hook.
- Comment cleanup: attributions removed from 244 files (objcheck: identical).
- Named `LoadSwFromBrx`, `PloCloneLo`, `PchzFidName`, `BeginSpliceLoad`, `g_sw`, `g_cm`, `g_sndmgr`
  (from callee notes in `src/hand/LoadSwFromBrx.cpp`).
- Removed 20 `src/auto` duplicates of functions matched in `src/P2/{bis,dmas,gifs,vifs}.cpp`; callers now use the
  real names (12 `func_` names retired). `objcheck check --all`: 0 problems.
- Found: `matchtool.py` only masks relocated fields and never checks *which* symbol a relocation targets; objcheck
  does. `src/P2/gifs.cpp` and `src/P2/vifs.cpp` each also build a non-matching copy of a function matched in
  `src/hand/` (`AddPrimPack__4GIFSiiUl`, `AddVifUnpack__4VIFS3UPKiPvi`); objcheck tracks them separately.

Metrics (`tools/readability.py`): 351/6,136 game functions named (5.7%), 3 globals named / 2,387 `D_` left;
of 5,908 game files: 3,223 local types, 2,474 pads, 1,929 `M2C_*`, 637 m2c temps, 5,734 `func_` refs,
2,402 `D_` refs, 811 inline asm, 32 history comments.

## Next steps

Phase 2 (types), in this order:
1. Remaining users of the small types: the files migrate_struct.py could not convert (CLOCK 28, CRef 203, RGBA 28…)
   need hand edits (C++ classes with inline methods, `extern … __asm__` aliases, `float a[16]`-style stand-ins).
2. Vectors/matrices: `vec.h`/`mat.h` exist; local VECTOR/MATRIX3/MATRIX4 stand-ins mostly use `qword` rows for VU
   code, which migrate_struct.py does not parse yet (add `qword` = 16-byte integer kind).
3. The class tree: the class table at 0x2BAAE8 gives every class's parent, size and vtable (see the 2026-10-31
   executable entry). Name classes (start from the 13 identified by their methods, then Sly 1 headers), write one
   header per class with the inheritance (`struct ALO : LO`), and migrate users class by class, starting with the
   most used (`tools/consolidate.py NAME` drafts each layout).
4. VTE/VT: one shared `VTE { short delta; short index; void *pfn; }` needs a cast at every virtual call; do it
   together with the class headers.

Phase 1 (names), still open:
5. `docs/NAMING_REVIEW.md`: 280 matcher-chosen names and 40 contradictions to review by hand.
6. Vtable slot names once classes are named (each class's own slots = its overrides).

## Open questions / known issues

- Naming convention: new names are plain C names (`LoadSwFromBrx`) unless the signature is known, in which case
  the g++ 2.95 mangled name (`LoadSwFromBrx__FP2SWP18CBinaryInputStream`) is preferred, like existing entries.
  Moving a function to real C++ later changes its symbol to the mangled form; the config entries must then be
  updated without rewriting the sources (`rename.py` has no config-only mode yet).
- `config/functions.csv` and `symbol_addrs.txt` disagree on a few addresses (e.g. 0x1177F0 is `InitGeom__FP4GEOM`
  vs `Close__18CBinaryInputStream`; several SDK aliases). To review.
