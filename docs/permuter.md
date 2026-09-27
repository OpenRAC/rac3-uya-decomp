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
   - `base.c`: your snippet after the declarations `text.c` puts in front of it, preprocessed;
   - `target.o`: the retail `.s` assembled, with bare `$gp` offsets turned into named relocations so both sides score alike;
   - `compile.sh`: the function's real flags from `tools/text_parts.txt` / `tools/localdecomp_flags.txt`, including `@ps2as`;
   - `prelude.c`: `.extern` size hints, which the permuter's C parser can't read.
3. `python3 ../decomp-permuter/permuter.py nonmatchings/func_XXXXXXXX -j$(nproc) --stop-on-zero`
4. Improvements are written to `nonmatchings/func_XXXXXXXX/output-<score>-<n>/source.c`. Copy the function out of the best one, check it with `tools/try_func.py`, then paste it into `src/text.c` as usual.

Pass `--mode S|N` or `--as ps2as` to `permuter_setup.py` to try another address mode or assembler than the range's default.

Speed: about 25 candidates a second on two cores for a small function.

## When it doesn't help

The permuter only moves a function if some C rewrite reaches retail. If nothing improves after about 20,000 iterations, the gap is probably not a source-shape problem. Check the other explanations first: hand-written code, inline asm in the original, a different flag or assembler for that range. `docs/full_match_roadmap.md` lists the known cases.
