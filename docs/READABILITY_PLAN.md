# Plan: making the decompilation human-readable

Goal: go from code that *matches* (all 6,662 functions byte-identical to the original game) to code a human can
read, understand and change, **without ever losing a match**.

Progress against this plan is tracked in [`/CLAUDE.md`](../CLAUDE.md) (progress log) and measured by
`tools/readability.py` (history in `config/readability_history.csv`).

## 1. Starting point (measured at `be803ab`)

| Metric | Value | Note |
|---|---|---|
| Functions | 6,662 | 100% matched |
| Game functions with a real name | 339 of 6,136 (5.5%) | the rest are `func_XXXXXXXX`; Sony SDK (`src/lib/`) excluded |
| Named global data | 0 | ~2,400 distinct `D_XXXXXXXX` referenced |
| `src/hand/` | 3,469 files, 167k lines | one function per file |
| `src/auto/` | 2,081 files, 42k lines | raw m2c output (`M2C_UNK`, `s32 temp_v0`, …) |
| `src/splicewrap/` | 373 files, 6k lines | generated, clean, but call `func_` names |
| `src/lib/` | 680 files, 22k lines | Sony SDK — **out of scope** (not game code, already named) |
| `src/P2/` | 5 files, ~1k lines | the only "clean" code (`bis.cpp`, `heap.cpp`, …): this is the target style |
| Files declaring their own types | ~3,200 | `struct S`, `struct O`, `struct P`… with `char pad[…]`; 1,282 different `struct S` |
| Files with `padXX[]` fields | ~2,470 | |
| Files with `M2C_*` macros | ~1,950 | |
| Files with inline asm | ~810 (5,400 asm statements) | partly real VU0 ops, partly register-allocation tricks |
| Matching-history comments ("Claude agent, lane G19…") | ~240 files | noise, not documentation |
| Function sizes | 2,382 < 16 instr., 3,622 of 16–100, 770 of 100–500, 42 > 500 | |

Key observations:

1. **No shared headers.** Every file re-declares the classes it touches with padding. This is the main obstacle to
   readability, and the main work item.
2. **Matching is verified per function.** Renames and type changes can be checked automatically. On top of
   `tools/matchtool.py` (which needs the game executable) there is now `tools/objcheck.py`, which compares against a
   recorded baseline of the compiled code and needs no game files (see §3, phase 0).
3. **Sly 2 reuses the Sly 1 engine** (same conventions: `LO`, `ALO`, `SO`, `CRef`, `CLOCK`…). The Sly 1
   decompilation provides names and struct layouts; `tools/show.py` can already use a `config/sly1_matches.csv`
   table (not in the repository).
4. **Some matching tricks cannot be removed** (allocation-only asm operands, forced declaration order…). They stay,
   but get isolated and documented.

## 2. Principles

- **Golden rule: every commit keeps every function identical** (`tools/objcheck.py check` reports 0 problems;
  `tools/progress.py` stays at 6,662/6,662 where the game executable is available).
- Work **per class / subsystem**, not per file: define `SO` once, then migrate all its users.
- Automate everything mechanical (renames, replacing local structs, comment cleanup); spend human/agent effort on
  understanding.
- Measure readability the way matching was measured (`tools/readability.py`).

## 3. Phases

### Phase 0 — Tooling and safety nets (≈ 2 weeks)

| Task | Detail | Effort | Status |
|---|---|---|---|
| 0.1 Incremental verification | `tools/objcheck.py`: baseline of every compiled function (words + relocation targets as addresses); `check` recompiles the changed sources and compares. Stricter than `matchtool` (also catches a call to the wrong function) and needs no game executable | 1–2 d | **done** |
| 0.2 Rename tool | `tools/rename.py OLD NEW`: config files, sources, file names; aliases | 2–3 d | **done** |
| 0.3 Data symbols | `type:data` entries in `symbol_addrs.txt` so `D_` globals can be named (handled by `rename.py`) | 1–2 d | **done** |
| 0.4 History comments | `tools/clean_history.py` strips agent/lane/wave attributions; remaining manual cleanup happens in phase 3 | 1–2 d | **done** (automatic part) |
| 0.5 Readability metrics | `tools/readability.py [--record]` | 2 d | **done** |
| 0.6 Duplicates | remove `src/auto` copies of functions matched in `src/P2` | ½ d | **done** |
| 0.7 Pre-commit hook | run `objcheck.py check` before each commit | ½ d | todo |
| 0.8 (optional) Full link | link a complete ELF and compare it with the original — useful for phase 5 | 1–2 wk | todo |

### Phase 1 — Name recovery (≈ 3–5 weeks)

Sources, by yield:

1. **Sly 1**: match functions by similarity (CFG shape, constants, calls to already-named functions) against
   `TheOnlyZac/sly1`; regenerate `config/sly1_matches.csv`. Expected: 30–50% of engine functions.
2. **Splice table**: the 373 wrappers are registered under their script names (strings) → names the wrappers *and*
   the engine functions they call.
3. **Vtables**: a class name in a vtable names all its methods by slot (`InitSo`, `UpdateSo`…).
4. **Debug strings / asserts / file names**.
5. **Matching notes**: comments already mention ~70 more names ("0x13E510 PloCloneLo"); they need review.
6. **Propagation**: callers/callees of named functions, Sucker Punch conventions (`PfnFromX`, `FFooBar` for
   booleans, `CFoo`, Hungarian prefixes).
7. **Manual** for the rest, most-called first (`func_0011CCA8`: 1,497 references, `func_001A62E8`: 827…).

Globals `D_`: same approach (Sly 1 + usage), starting with the ~200 most referenced.

Exit criterion: ≥ 80% of game functions named, 100% of the 300 most-called.

Status (2026-10-31): `tools/sly1match.py` covers source 1 without the Sly 1 executable (408 pairs, 79 new names;
no mistake in its self-test). The by-name callees (461 names already written in the sources but never given an
address), the vtables and the Splice table all need the Sly 2 executable.

### Phase 2 — Shared headers and types (≈ 3–5 months, the bulk of the work)

1. **Class hierarchy**: rebuild `LO → ALO → SO → PO → …` (and `CRef`, `CLOCK`, `VECTOR`, `MATRIX3/4`…) from Sly 1,
   the vtables and the offsets observed in the ~3,200 local structs.
2. **Consolidation tool** (≈ 1–2 wk): extract every local struct, group them by accessed offsets and owning function,
   detect conflicts → a "field @ offset: name, type, evidence" database.
3. **Write `include/` per subsystem** (`lo.h`, `alo.h`, `so.h`, `jt.h`, `cm.h`, `vec.h`, `mat.h`…).
4. **Migration**: for each class, replace the local declarations with `#include`, check with objcheck, and fix the
   cases where a different declaration changed the generated code (`int`/`short`, `const`, member order, unions).
5. Suggested order: basic types (vectors, matrices, `CLOCK`, `CRef`) → `LO`/`ALO`/`SO` (used everywhere) →
   player/camera → gameplay subsystems → rendering/VU.

Main risk: a field declared `char` in one file and `int` in another can change register allocation. objcheck catches
these at once; expect 10–20% of files to need investigation.

### Phase 3 — Per-function cleanup (≈ 4–8 months, parallelisable)

For each function, once its types exist:

- `src/auto/`: replace `M2C_FIELD(p, s32*, 0x48)` with `p->m_field`, `temp_v0` with meaningful names, `s32` with the
  game's types, `goto` loops with `for/while` where it still matches.
- `src/hand/`: drop the local structs, rename `S/O/P/E` to the real classes, rename variables.
- Comments: one line of description per non-trivial function; document the remaining tricks.
- `.c` files that are really C++ methods become `.cpp` with the right mangling.

Indicative effort per function (types already available):

| Size | Count | Unit time | Total |
|---|---|---|---|
| < 16 instructions | 2,382 | 5 min | ~200 h |
| 16–100 | 3,622 | 15 min | ~900 h |
| 100–500 | 770 | 1 h | ~770 h |
| > 500 | 42 | 4 h | ~170 h |
| **Total** | **6,816 entries** | | **~2,000 h** |

### Phase 4 — Isolating the matching tricks (≈ 3–4 weeks)

- Gather the real VU0 operations (`vadd`, `vmul`, `vsqrt`, `qmtc2`…) into a header of named intrinsics
  (`include/vu0.h`): most likely what the original code did.
- Allocation-only asm operands, `register … asm("$s0")` and forced declaration orders stay, but behind an explicit
  macro (`MATCH_HACK_KEEP_IN_GPR(x)`) with a one-line comment.
- Goal: no undocumented asm outside `vu0.h`.

### Phase 5 — Original translation units (≈ 1–2 months, optional but very useful)

Group the one-function-per-file sources into the original source files (`jt.cpp`, `alo.cpp`, `cm.cpp`…), like
`src/P2/`. Boundaries come from the order in the binary, the `.rodata` constant pools and the Sly 1 names. Needs
the full link (0.8) or a `matchtool`/`objcheck` that compares several functions per file (objcheck already does).
Careful: compiling functions together can change inlining and literal order.

## 4. Overall estimate

| Phase | Effort (1 experienced person, full time) |
|---|---|
| 0 Tooling | 2–4 weeks |
| 1 Names | 3–5 weeks |
| 2 Headers / types | 3–5 months |
| 3 Per-function cleanup | 4–8 months (~2,000 h) |
| 4 Asm tricks | 3–4 weeks |
| 5 Translation units (optional) | 1–2 months |
| **Total** | **≈ 12–20 person-months** (≈ 2,000–3,300 h) |

**With AI agents**, as for the matching (see `CREDITS.md`): phases 1, 3 and 4 parallelise well (each function is
checked on its own). Phases 0 and 2 stay sequential and need human judgement on header design. Realistic order of
magnitude: **4–7 calendar months** for one person steering and reviewing several agents, 2–3 of them on phase 2,
which remains the bottleneck.

Main uncertainties:

- how many names Sly 1 yields (30% vs 60% doubles or halves phase 1);
- how many files break when switched to shared headers;
- the target level: "names + types everywhere" (≈ phases 0–3) vs "clean source organised in modules" (phases 0–5).

## 5. Milestones

| Milestone | Criterion | Indicative target |
|---|---|---|
| M1 | Tooling in place, history comments cleaned, metrics published | end of month 1 |
| M2 | 80% of functions named, top-300 most-called 100% named | month 2 |
| M3 | Basic types + `LO/ALO/SO` in headers; 50% of files without local types | month 4 |
| M4 | No `M2C_FIELD`, < 10% of files with pads | month 6 |
| M5 | No undocumented asm, every non-trivial function commented | end |
| M6 (optional) | Sources grouped by original translation unit | end + 2 months |

At every milestone: all 6,662 functions still match.
