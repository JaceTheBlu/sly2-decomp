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

## Progress log

Newest first. Each entry: what changed, how it was verified, the metrics after it.

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

1. Phase 1, Sly 1 names: clone `TheOnlyZac/sly1`, match functions by similarity and regenerate
   `config/sly1_matches.csv`; apply high-confidence names with `rename.py --map`.
2. Review the ~70 other names mentioned in matching notes (comments such as "0x13E510 PloCloneLo").
3. Name the Splice wrappers from the Splice registration table.
4. Pilot phase 2 on `CLOCK`, `VECTOR`, `MATRIX3/4` to measure the real cost per class.

## Open questions / known issues

- Naming convention: new names are plain C names (`LoadSwFromBrx`) unless the signature is known, in which case
  the g++ 2.95 mangled name (`LoadSwFromBrx__FP2SWP18CBinaryInputStream`) is preferred, like existing entries.
  Moving a function to real C++ later changes its symbol to the mangled form; the config entries must then be
  updated without rewriting the sources (`rename.py` has no config-only mode yet).
- `config/functions.csv` and `symbol_addrs.txt` disagree on a few addresses (e.g. 0x1177F0 is `InitGeom__FP4GEOM`
  vs `Close__18CBinaryInputStream`; several SDK aliases). To review.
