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
| `tools/resolve_names.py [--sly1 DIR] [--apply]` | give addresses to names the sources use without one (needs the executable) |

## Progress log

Newest first. Each entry: what changed, how it was verified, the metrics after it.

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

Metrics: 538/6,136 game functions named (8.8%), 46 globals named, 2,374 `D_` left.

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

With the game executable (`disc/SCUS_973.16`; not in git, ask the owner in a new container):
1. ~~Resolve the by-name callees~~ (done, `tools/resolve_names.py`).
2. Vtables: the vtable addresses found by resolve_names (`_vt$…` references) and the Sly 1 class layouts name
   method slots.
3. Splice registration table: script names of the 373 wrappers and of the engine functions they call.

Without it:
4. Review the ~70 names mentioned in matching notes (comments such as "0x13E510 PloCloneLo").
5. Sly 1 matching beyond the current 408 pairs: Sly 2 has ~2,000 more functions in Sly 1 source files that are
   not paired; more evidence is needed (data/string references would help most, again from the executable).
6. Pilot phase 2 on `CLOCK`, `VECTOR`, `MATRIX3/4` (Sly 1 headers in `sly1/include/` give field names).

Running sly1match.py: `python3 tools/sly1match.py ~/sly1 [--eval]` (clone `https://github.com/TheOnlyZac/sly1`
first). Re-running it after names were applied reports them as anchors; keep the committed
`config/sly1_matches.csv`, which records how each name was found, unless new pairs are being added.

## Open questions / known issues

- Naming convention: new names are plain C names (`LoadSwFromBrx`) unless the signature is known, in which case
  the g++ 2.95 mangled name (`LoadSwFromBrx__FP2SWP18CBinaryInputStream`) is preferred, like existing entries.
  Moving a function to real C++ later changes its symbol to the mangled form; the config entries must then be
  updated without rewriting the sources (`rename.py` has no config-only mode yet).
- `config/functions.csv` and `symbol_addrs.txt` disagree on a few addresses (e.g. 0x1177F0 is `InitGeom__FP4GEOM`
  vs `Close__18CBinaryInputStream`; several SDK aliases). To review.
