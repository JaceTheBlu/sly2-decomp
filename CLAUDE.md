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
| `tools/resolve_names.py [--sly1 DIR] [--apply]` | give addresses to names the sources use without one (needs the executable) |

## Progress log

Newest first. Each entry: what changed, how it was verified, the metrics after it.

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
