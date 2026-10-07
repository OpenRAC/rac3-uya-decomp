# Using decomp-permuter

For functions where every instruction is right but gcc picks another register or another order, and hand rewrites stop helping, run [decomp-permuter](https://github.com/simonlindholm/decomp-permuter). It randomly rewrites the C (reorders statements, adds temporaries, changes types, flips branches) and keeps anything that scores closer to retail. A score of 0 means byte-identical.

## Setup (Linux or WSL)

```sh
git clone https://github.com/simonlindholm/decomp-permuter ../decomp-permuter
pip install pycparser toml Levenshtein
sudo apt install binutils-mips-linux-gnu      # mips-linux-gnu-objdump, used for scoring
# wibo runs the SN Windows toolchain on Linux
export UYA_TOOLCHAIN=/path/to/eegcc_2.95.3_sn_v1.36
export UYA_RUNNER=/path/to/wibo
```

## Per function

1. Write your closest attempt as a snippet, the same format `tools/try_func.py` takes (externs, typedefs, the function).
2. `python3 tools/permuter_setup.py scratch/func_XXXXXXXX.c`
   This writes `nonmatchings/func_XXXXXXXX/` (gitignored) with:
   - `base.c`: your snippet after the declarations its source file puts in front of it, preprocessed;
   - `target.o`: the retail `.s` assembled, with bare `$gp` offsets turned into named relocations so both sides score alike;
   - `compile.sh`: the function's real flags from `tools/text_parts.txt` / `tools/localdecomp_flags.txt`, including `@ps2as`;
   - `prelude.c`: `.extern` size hints, which the permuter's C parser can't read.
3. `python3 ../decomp-permuter/permuter.py nonmatchings/func_XXXXXXXX -j$(nproc) --stop-on-zero`
4. Improvements are written to `nonmatchings/func_XXXXXXXX/output-<score>-<n>/source.c`. Copy the function out of the best one, check it with `tools/try_func.py`, then paste it into its source file as usual.

Pass `--mode S|N` or `--as ps2as` to `permuter_setup.py` to try another address mode or assembler than the range's default.

Speed: about 25 candidates a second on two cores for a small function.

## When it doesn't help

The permuter only moves a function if some C rewrite reaches retail. If nothing improves after about 20,000 iterations, the gap is probably not a source-shape problem. Check the other explanations first: hand-written code, inline asm in the original, a different flag or assembler for that range. `docs/full_match_roadmap.md` lists the known cases.

## Aligned-diff scoring (recommended)

decomp-permuter's built-in score weights objdump differences in its own way and often disagrees with how close a function really is (one near miss scored 180 at 5 real diffs). `tools/permuter_scorer.py` scores a candidate the way `try_func.py` and the matching agents measure it: instructions aligned against retail, relocations resolved, branch targets compared through the alignment. Score = 10 x aligned diffs, 0 = match.

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

`permuter_setup.py` also records the typedef attributes (`mode(TI)`, `aligned(16)`) that the parser can't read in `attrs.json`, and `compile.sh` puts them back before compiling each candidate. Before this, 128-bit and vector types silently became plain `int` in permuter runs (a draft at 5 real diffs scored 25 diffs' worth), and j-form VU0 drafts couldn't be permuted at all. The flags in `compile.sh` come from `tools/text_parts.txt`, so they include `-mvu0-use-vf0-vf2` since 2026-10-07 (a function with a line in `tools/localdecomp_flags.txt` gets that line instead, so put the flag there too); to drop a flag, edit `compile.sh` by hand (`permuter_setup.py` has no option for it).
