# Using decomp-permuter

For functions where every instruction is right but gcc picks another register or another order, and hand rewrites stop helping, run [decomp-permuter](https://github.com/simonlindholm/decomp-permuter). It randomly rewrites the C (reorders statements, adds temporaries, changes types, flips branches) and keeps anything that scores closer to retail. A score of 0 means byte-identical.

There are two ways to run it:

- **From localdecomp (Windows or Linux, no WSL).** The Permuter button opens a panel that runs the search on the editor's code and shows it live. See [The Permuter panel](#the-permuter-panel).
- **From the command line**, with `tools/permuter_engine.py` (same engine as the panel) or with decomp-permuter's own `permuter.py` (Linux/WSL), described further down.

Both need a decomp-permuter checkout with this project's two patches applied once:

```sh
git clone https://github.com/simonlindholm/decomp-permuter ../Tools/decomp-permuter   # or ../decomp-permuter
cd ../Tools/decomp-permuter
git apply <repo>/tools/decomp-permuter-aligned-scorer.patch   # only for permuter.py; the engine scores by itself
git apply <repo>/tools/decomp-permuter-asm-passes.patch       # the fence and barrier passes
pip install toml          # not needed on Python 3.11+
```

## The Permuter panel

Start localdecomp as usual, pick a function, get the editor to your closest attempt, and click **Permuter** in the header. localdecomp looks for the checkout in `--permuter <path>`, `$DECOMP_PERMUTER`, then `../Tools/decomp-permuter` and `../decomp-permuter` next to the repo.

- **Workers**: processes compiling candidates in parallel (default: CPU count minus one).
- **Minutes**: time limit, 0 for no limit. A run also stops on its own at 0 diffs.
- **Fence/barrier passes**: also try the empty-asm edits below.
- **Start from editor code** starts a run from whatever is in the editor; the compile flags are the function's own (`config/frontbin/localdecomp_flags.txt`, then `config/frontbin/text_parts.txt`) and are shown in the stats line.

While it runs the panel shows:

- **Stats**: elapsed time, candidates tried, candidates per second, how many didn't compile, the base score and the best so far (aligned instruction diffs, the same number `tools/check.py` and `cmp` report).
- **Aligned diffs over time**: the best score as a step line, a sample of candidate scores as dots, and the base score as a dashed line. Dots spread far above the base mean the passes are breaking the function; dots hugging it mean it is exploring nearby.
- **Passes**: for each randomization pass, how often it was tried, how many new bests it produced, and how often its candidates didn't compile.
- **Activity**: the newest candidates, each with the worker, the pass that made it and its score. New bests are highlighted; fence and barrier passes are purple.
- **Results**: every candidate that matched or beat the base, best first. Click one to see its change against the starting code (inserted asm lines are marked). **Load into editor** replaces the function in the editor with it (the declarations above it stay); **Load & Build** also builds it so the normal diff view shows what changed.

Closing the panel doesn't stop the run; reopening it for the same function reattaches. Every result is also written to `scratch/permuter/<target>/<func>/output-<diffs>-<n>/source.c`.

Results are hints, not answers: the search accepts any C that compiles to closer code, including C that does something else (see [Checking outputs](#checking-outputs)). Rewrite the useful change by hand into the real source, then Build.

## Command line: tools/permuter_engine.py

```sh
python3 tools/permuter_engine.py scratch/func_XXXXXXXX.c -j4 --seconds 600
python3 tools/permuter_engine.py scratch/f.c func_XXXXXXXX --mode N --as ps2as --no-asm-passes
```

It prints a status line each second and the same `scratch/permuter/<func>/output-*` folders. On Linux pass the toolchain and wibo through `UYA_TOOLCHAIN` / `UYA_RUNNER` as for the other tools.

## Empty asm passes (fence and barrier)

Several near misses are decided by one choice in the scheduler or the register allocator that no C rewrite moves. Two empty inline asm statements change those choices without emitting any instruction:

| Form | What gcc does with it |
|---|---|
| `__asm__("" : "+r"(x));` register fence (`"+f"` for a float) | `x` keeps its own pseudo, so combine can't fold its value into a later instruction, and the fence adds one link to `x`'s dependency chain. That raises the priority of the instructions feeding it in sched1 and so changes local-alloc's choices. |
| `__asm__ __volatile__("");` barrier | sched1 and sched2 move nothing across it (a volatile asm uses and clobbers everything), and reorg won't fill a delay slot across it. |

`func_003B0A60` (one fence) and `func_0038E930` (a fence and a barrier) matched this way. The patch adds two passes, `perm_reg_fence` (inserts a fence after an assignment, or removes one) and `perm_sched_barrier` (inserts or removes a barrier). They default to weight 0 in decomp-permuter, so a stock project never gets inline asm; `permuter_setup.py` and the engine turn them on (`--no-asm-passes` turns them off). A function matched with either form is committed as `func_X (asm)` for review, like any other inline asm.

### Exhaustive search: tools/fence_search.py

The passes are random. `tools/fence_search.py` tries every placement instead: a fence after each simple assignment, a barrier before each statement, a `do { } while (0)` around each statement and each swap of neighbouring statements, then every pair of the best single edits with any other edit (fixes often need two).

```sh
python3 tools/fence_search.py scratch/func_XXXXXXXX.c -j4
```

It prints each new best as it finds it and writes the variants to `scratch/fence_search/<func>/`. A function of 40 statements takes a few minutes. It can't invent a variable: a fence on a value that is only an expression (a load inside a condition) needs a temporary first, which the permuter's `perm_temp_for_expr` plus `perm_reg_fence` can find.

## Flags: config/frontbin/localdecomp_flags.txt and tools/flags_probe.py

Every single-function tool (localdecomp, `check.py`, `try_in_context.py`, `permuter_setup.py`, the engine, `fence_search.py`, `sched_explain.py`) takes a function's flags from `config/frontbin/localdecomp_flags.txt` first, then `config/frontbin/text_parts.txt`. A near miss that needs its own mode or assembler (S/N, `@ps2as`) has to be listed in `localdecomp_flags.txt`, or every tool measures it with the file's default flags and reports a much worse score (`func_003B9730`: 14 diffs with N + `@ps2as`, 27 with the default).

`tools/flags_probe.py` compiles a draft in each mode and assembler, prints the aligned diffs for each, and with `--write` records the best in `localdecomp_flags.txt`:

```sh
python3 tools/flags_probe.py scratch/func_XXXXXXXX.c func_XXXXXXXX --write
```

Extra flags it doesn't try (`-fforce-mem`, dropping `-fopt-stack`) go in by hand. When a function matches and goes into its source file, move its line to `config/frontbin/text_parts.txt` as a single-function override with a restore line.

## Why did gcc schedule it that way? tools/sched_explain.py

When two instructions come out in the other order, or a register differs because of where an instruction was scheduled, this replays gcc's scheduler for the function:

```sh
python3 tools/sched_explain.py scratch/f.c func_0038E930              # every block, sched1
python3 tools/sched_explain.py scratch/f.c func_0038E930 --pass 2     # sched2, after reload
python3 tools/sched_explain.py scratch/f.c func_0038E930 --why 4 15   # the key that decided between insns 4 and 15
```

It compiles in the full-build context with SN cc1's scheduler dumps and prints, for each cycle, the ready instructions best first with the five keys gcc 2.95 ranks them by: priority (longest latency path to the block end), register weight (sched1 only; registers set minus registers dying, lower wins), class relative to the instruction scheduled last, number of dependents, and source order. Instructions are shown by RTL uid with the scheduler's short form (`r126=[r119+0x10]`). Example from `func_0038E930`: `--why 4 15` prints `reg weight: 4=0 vs 15=1 -> 4 first`, the copy of `n` beats the load because the copy frees `$a0`, and that order is what put `n*4` in `$a0`.

The usual fixes by deciding key: priority (lengthen or shorten a chain: a fence, a temporary, another operand order), reg weight (a value that dies here or not: reuse a variable, add a fence), source order (move the statement).

## Command line: decomp-permuter itself (Linux or WSL)

```sh
git clone https://github.com/simonlindholm/decomp-permuter ../decomp-permuter
pip install pycparser toml Levenshtein
sudo apt install binutils-mips-linux-gnu      # mips-linux-gnu-objdump, used for scoring
# wibo runs the SN Windows toolchain on Linux
export UYA_TOOLCHAIN=/path/to/eegcc_2.95.3_sn_v1.36
export UYA_RUNNER=/path/to/wibo
```

## Per function

1. Write your closest attempt as a snippet, the same format `tools/check.py` takes (externs, typedefs, the function).
2. `python3 tools/permuter_setup.py scratch/func_XXXXXXXX.c`
   This writes `nonmatchings/func_XXXXXXXX/` (gitignored) with:
   - `base.c`: your snippet after the declarations its source file puts in front of it, preprocessed;
   - `target.o`: the retail `.s` assembled, with bare `$gp` offsets turned into named relocations so both sides score alike;
   - `compile.sh`: the function's real flags from `config/frontbin/text_parts.txt` / `config/frontbin/localdecomp_flags.txt`, including `@ps2as`;
   - `prelude.c`: `.extern` size hints, which the permuter's C parser can't read.
3. `python3 ../decomp-permuter/permuter.py nonmatchings/func_XXXXXXXX -j$(nproc) --stop-on-zero`
4. Improvements are written to `nonmatchings/func_XXXXXXXX/output-<score>-<n>/source.c`. Copy the function out of the best one, check it with `tools/check.py`, then paste it into its source file as usual.

Pass `--mode S|N` or `--as ps2as` to `permuter_setup.py` to try another address mode or assembler than the range's default.

Speed: about 25 candidates a second on two cores for a small function.

## Checking outputs

Every output needs checking: random rewrites can change what the code does, and the aligned score accepts them (details in the aligned-scoring section below).

## When it doesn't help

The permuter only moves a function if some C rewrite reaches retail. If nothing improves after about 20,000 iterations, the gap is probably not a source-shape problem. Check the other explanations first: hand-written code, inline asm in the original, a different flag or assembler for that range. `docs/full_match_roadmap.md` lists the known cases.

## Aligned-diff scoring (recommended)

decomp-permuter's built-in score weights objdump differences in its own way and often disagrees with how close a function really is (one near miss scored 180 at 5 real diffs). `tools/permuter_scorer.py` scores a candidate the way `check.py` and the matching agents measure it: instructions aligned against retail, relocations resolved, branch targets compared through the alignment. Score = 10 x aligned diffs, 0 = match.

1. Once, in your decomp-permuter checkout: `git apply <repo>/tools/decomp-permuter-aligned-scorer.patch` (a 20-line hook in `src/scorer.py`; without the variables below it changes nothing).
2. Per run:

```sh
export PERMUTER_ALIGNED_SCORER=$PWD/tools/permuter_scorer.py
export PERMUTER_ALIGNED_FUNC=func_XXXXXXXX
export UYA_TARGET=frontbin           # or boot_elf / i5bootn
python3 ../decomp-permuter/permuter.py nonmatchings/func_XXXXXXXX -j2 --stop-on-zero
```

With it the permuter's base score equals the aligned diff count x 10. `python3 tools/permuter_scorer.py candidate.o func_XXXXXXXX` scores a single object the same way.

Every output still needs checking: random rewrites can change what the code does, and the aligned score accepts them. In k1's boot_elf run (2026-10-07) about half of the "improvements" were invalid (passing 0 instead of an argument, shrinking a type to `u16`, dropping a store); g4 rejected two of the same kind. Treat outputs as hints and rewrite the useful ones by hand. With the aligned scorer the permuter contributed to 4 of g4's 5 matches in the second final pass, and its finds carried over in several functions: `i = 0; if (n > i) do ... while`, an early `v = const`, `do { } while (0)` wraps, a callee's return type.

`permuter_setup.py` also records the typedef attributes (`mode(TI)`, `aligned(16)`) that the parser can't read in `attrs.json`, and `compile.sh` puts them back before compiling each candidate. Before this, 128-bit and vector types silently became plain `int` in permuter runs (a draft at 5 real diffs scored 25 diffs' worth), and j-form VU0 drafts couldn't be permuted at all. The flags in `compile.sh` come from `config/frontbin/text_parts.txt`, so they include `-mvu0-use-vf0-vf2` since 2026-10-07 (a function with a line in `config/frontbin/localdecomp_flags.txt` gets that line instead, so put the flag there too); to drop a flag, edit `compile.sh` by hand (`permuter_setup.py` has no option for it).
