# Tools

Every script in `tools/`, plus localdecomp and the Makefile, and what each is for. Run the Python tools from anywhere: they find the repo root themselves. Install their dependencies once with `pip install -r tools/requirements.txt`.

**Three executables.** The repo builds `frontbin.elf`, `boot_elf.elf` and `i5bootn.elf`. Every tool works on frontbin unless you pass `--target boot_elf` / `--target i5bootn` (or set `UYA_TARGET`): `setup_asm.py`, `build.py`, `build_text.py`, `try_func.py`, `try_in_context.py`, `triage.py`, `pr_check.py`, `split_text.py`, `gen_divs_nops.py`, `migrate_asm_sources.py`, `split_remnant_prefix.py`, `trailing_padding.py`, `check_match.py`, `permuter_setup.py` and `gen_asm_func.py`. `setup_asm.py`, `build.py`, `pr_check.py`, `triage.py`, `split_text.py`, `gen_divs_nops.py` and `migrate_asm_sources.py` also take `--target all` (once per target that is set up; fails if any run fails). `tools/targets.py` lists each target's ELF, sections, source folders and tables (frontbin's are in `tools/`, the others' in `targets/<target>/`). See [`docs/targets.md`](https://github.com/vetusmagnus/ratchet-uya-decomp/blob/main/docs/targets.md), which also covers adding a target.

## Which tool do I need?

| I want to... | Use |
|---|---|
| Pick a function to work on | [`triage.py`](#triagepy) |
| Match a function in a browser | [localdecomp](#localdecomp) |
| Match a function on the command line | [`try_func.py`](#try_funcpy) |
| Check a function exactly as the full build compiles it | [`try_in_context.py`](#try_in_contextpy) |
| Get unstuck on a register or ordering near miss | [`permuter_setup.py`](#permuter_setuppy) with [`permuter_scorer.py`](#permuter_scorerpy) |
| Draft inline asm for a VU0/MMI leaf | [`gen_asm_func.py`](#gen_asm_funcpy) |
| Check my changes before a PR | [`pr_check.py`](#pr_checkpy), then [`make`](#make-and-buildpy) |
| Build on Linux or macOS | [`build.py`](#make-and-buildpy) |
| Reproduce the CI and decomp.dev numbers | [`make objdiff`](#make-and-buildpy), or localdecomp's **Full check** |

The rest of this page goes tool by tool, grouped by when you'd use them.

---

## Matching a function

### localdecomp

`localdecomp/server.py` is a local decomp.me-style web page. Start it from the repo root and open the printed URL:

```
python localdecomp/server.py
```

- **Function list:** every function with its status: perfect, partial, not started. Hand-written functions and linker remnants show as perfect because they are final assembly; opening one explains that there is no C to write for it.
- **Editor and Build:**
  - Compiles your C with the flags of the function's address range (see [`text_parts.txt`](#text_partstxt-and-localdecomp_flagstxt)).
  - Puts the same declarations in front of it that the full build does: its file's declarations from other files and its file's earlier declarations.
  - Shows a side-by-side diff. A score of 0 is a match.
- **Save:** writes the function into its source file in `src/frontbin/` between `/* localdecomp:start */` and `/* localdecomp:end */` markers, replacing its `INCLUDE_ASM` line. Saving is refused for functions that can't be C: `ASM_FUNC`/`LINKER_REMNANT` entries, and functions that don't start on an 8-byte boundary.
- **Full check:** runs the same steps as CI (full build, MATCH, objdiff report) and compares the result with your last push. Push is only enabled after a passing check.

Useful options:

| Option | Meaning |
|---|---|
| `--toolbin` | folder with `ee-gcc2953.exe` |
| `--port` | web port (default 8477) |
| `--no-git-sync` | don't auto-commit perfect matches |
| `--refs` | folder with `level-targets-split\`, `exe-targets\` and `frontbin_data.o`, as used by CI (default `C:\decomp-refs`). Not in a fresh clone: see [Setup](Setup), "Full localdecomp build" |
| `--objdiff-cli` | path to `objdiff-cli` |

A score of 0 in localdecomp is necessary, not sufficient. The full build (`make`) still has to print MATCH.

### try_func.py

The command-line equivalent of localdecomp's Build. Give it a self-contained snippet (externs, typedefs, the function) and it compiles it with the function's real flags and diffs against retail:

```
python tools/try_func.py scratch/func_0039BEC0.c
python tools/try_func.py scratch/func_0039BEC0.c --all-modes     # split/no-split x ee-as/Ps2EeAs
python tools/try_func.py scratch/f.c func_0039BEC0 --mode S --as ps2as
```

- Relocations are filled in with real addresses, so a wrong symbol or two swapped stores show up as differences.
- The source-file context is included by default. `--no-context` compiles your file alone.
- `--flags "..."` appends extra compiler flags to the range's flags, for experiments. It can't remove one; to try a function without `-fopt-stack`, append `--flags=-fno-opt-stack`. Write it with `=` when the value starts with `-` (`--flags=-mvu0-use-vf0-vf2`).
- `try_func.py` doesn't show compiler warnings, so a callee with no prototype silently becomes `int f()` (floats passed as doubles, `$v0` kept busy). `--flags=-Werror-implicit-function-declaration` turns those into errors that name the callee. Check every draft this way, especially one that needs its own override slice: a slice doesn't see the definitions in its file's other slices.
- Its `flags:` line prints the range's flags even when `--mode` / `--as` are given; the overrides are applied anyway.
- `--early-extern-size SYMBOL=SIZE` (repeatable) is an experiment for Ps2EeAs `$gp` selection; the full build doesn't do this, so a function that only matches with it is not done. See [Matching patterns](Matching-Patterns#early-extern-sizes-for-ps2eeas).
- On Linux, pass `--toolchain` and `--runner` (the path to wibo), or set `UYA_TOOLCHAIN` and `UYA_RUNNER`.

Output is `func_X: MATCH` or `func_X: N diff` plus a side-by-side listing.

### try_in_context.py

Puts your snippet into a copy of the function's source file in place of the function, builds that file (or the slice holding the function) the way the real build does, and diffs it. Then it compiles the rest of the file and every later file that would receive the block's declarations through `split_text.py --refresh`, and reports any `conflicting types` error there. That is the usual reason a function that matches in `try_func.py` stops `make`: a later block or file declares the same name differently. Run it on every function before you insert it (`--no-file-check` skips the second part).

It doesn't catch everything. Several times a callee prototype that `split_text.py --refresh` later copied into a file defining that callee differently (for example as `(void)`) passed it and failed `pr_check.py`; run `pr_check.py` after adding an `extern` for a function that isn't a per-function alias, or use a K&R declaration or an alias. It also ignores `tools/localdecomp_flags.txt`, so an `@ps2as` candidate can only be checked in place once its `text_parts.txt` override exists.

```
python tools/try_in_context.py scratch/func_003AED08.c
```

### permuter_setup.py

Sets up [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) for one function. The permuter randomly rewrites your C and keeps anything closer to retail. Use it for near misses where every instruction is right but gcc picks another register or order.

```
python3 tools/permuter_setup.py scratch/func_0037DF98.c
python3 ../decomp-permuter/permuter.py nonmatchings/func_0037DF98 -j4 --stop-on-zero
```

It writes `nonmatchings/<func>/` (gitignored), with the function's real flags (now including `-mvu0-use-vf0-vf2`), its source-file context and the retail target. `--mode S|N` and `--as ps2as` override the address mode or assembler; there is no option to drop a flag, so edit `compile.sh` by hand for that. The permuter runs on Linux or WSL only. Full instructions: `docs/permuter.md`.

The permuter's C parser can't read `__attribute__`, so `permuter_setup.py` records the typedef attributes (`mode(TI)`, `aligned(16)`) in `attrs.json` and `compile.sh` puts them back before each compile. Before 2026-10-07 they were silently dropped: 128-bit and vector types became plain `int`, and j-form VU0 drafts couldn't be permuted (a draft at 5 real diffs scored 25 diffs' worth).

Always check what a permuter output does before building on it. In k1's boot_elf run about half of the aligned scorer's "improvements" changed the code's meaning (passing 0 instead of an argument, shrinking a type to `u16`, dropping a store); g4 hit the same twice. The useful ones are often hints to rewrite by hand. Forms it found that carried over: `i = 0; if (n > i) do ... while`, an early `v = const`, `do { } while (0)` wraps, a callee's return type.

### permuter_scorer.py

Scores a candidate object the way `try_func.py` and the matching agents measure functions: instructions aligned against retail with difflib, relocated fields resolved, branch targets compared through the alignment. The score is 10 x aligned diffs; 0 is a match (confirm with `try_func.py`). decomp-permuter's own score often disagrees with this (one near miss scored 180 at 5 real diffs, another 3010 at 2).

To use it inside the permuter, apply `tools/decomp-permuter-aligned-scorer.patch` once in your decomp-permuter checkout (a 20-line hook in `src/scorer.py` that does nothing unless the variables below are set), then:

```
export PERMUTER_ALIGNED_SCORER=$PWD/tools/permuter_scorer.py
export PERMUTER_ALIGNED_FUNC=func_003B7B50
export UYA_TARGET=frontbin           # or boot_elf / i5bootn
python3 ../decomp-permuter/permuter.py nonmatchings/func_003B7B50 -j2 --stop-on-zero
```

On its own it scores one object: `python3 tools/permuter_scorer.py candidate.o func_003B7B50`. With it, g4's permuter runs contributed to 4 of its 5 matches in the second final pass. See `docs/permuter.md`.

### regalloc.py

Shows how gcc's global register allocator treats a C snippet: for each variable its reference count, live length, priority and assigned register, in allocation order. Use it for register-allocation near misses, where every instruction is right but a variable ends up in another register (for example an argument kept in `$t3` while `$a0` holds something else). See [Matching patterns](Matching-Patterns#register-allocation-near-misses).

```
python tools/regalloc.py scratch/func_0039BEC0.c
python tools/regalloc.py scratch/f.c --flags "-O2 -G8 -mno-split-addresses"
```

It compiles with `-dlg` and does not run the assembler, so it does not model which globals use `$gp` (the allocation itself is unaffected).

Limits:
- It compiles the snippet without the file's declarations, so its numbers can differ from the in-context build, and a block that uses an earlier block's typedefs needs them pasted in.
- It takes `--flags`, not `--mode`/`--as`. Its default flags are `-O2 -G8 -fopt-stack -mno-check-zero-division`; add `-mvu0-use-vf0-vf2` (on every frontbin and boot_elf range since 2026-10-07, and it changes loop hoisting) and `-mno-split-addresses` where the range has them.

### gen_asm_func.py

Drafts an inline-asm C function from retail assembly, for leaf functions that were inline asm in the original (VU0 vector math, 128-bit MMI code). It decodes the raw `.word` lines back into `lqc2`/`sqc2`/`lq`/`sq` and reuses the function's existing prototype.

```
python tools/gen_asm_func.py scratch func_003886B0 func_00388B40
```

Test each result with `try_func.py`, both with and without `--as ps2as`. `NOREORDER=1` wraps the block in `.set noreorder`, which is rarely what retail has. See [Matching patterns](Matching-Patterns#vu0-code-inline-asm).

---

## Planning and checking

### triage.py

Sorts every remaining `INCLUDE_ASM` function into one bucket:

| Bucket | Meaning |
|---|---|
| `plain` | ordinary C |
| `sibcall` | ends in a sibling call (`j func_` after the epilogue): not our compiler; in practice Sony's library compilers (2.9-ee-991111 in i5bootn and most of boot_elf's engine core; boot_elf's newlib region looks like 2.96); not matchable until that compiler is in the toolchain |
| `switch` | jump tables |
| `vu0` | VU0 inline asm |
| `mmi` | 128-bit EE instructions |
| `float-nop` | an unexplained float load then `nop` |
| `handwritten`, `remnant` | not decompilation targets (see [`migrate_asm_sources.py`](#migrate_asm_sourcespy)) |

```
python tools/triage.py                                  # summary by bucket
python tools/triage.py --tsv docs/remaining_functions.tsv   # full list with sizes
python tools/triage.py --target boot_elf --unit core        # another target, one code section
python tools/triage.py --target all                     # one summary per target
```

Start with `plain`, smallest first. `docs/remaining_functions.tsv` is its saved output for frontbin.

On 2026-10-07 (`python tools/triage.py --target all`): frontbin 72 left (41 plain, 9 switch, 11 vu0, 11 mmi; one of the plain is `func_003ECDF0`, a data blob), boot_elf 650 (434 plain, 43 sibcall, 21 switch, 41 vu0, 29 mmi, 2 sys, 80 odd), i5bootn 42 (36 plain, 3 sibcall, 1 switch, 1 mmi, 1 odd).

### pr_check.py

Catches the mistakes that break the full build, and names the line to fix:

- unbalanced localdecomp markers;
- a function that is both C and `INCLUDE_ASM`;
- variables *defined* in a source file (only `extern` is allowed);
- functions in the wrong file for their address, or a file whose declarations from other files are out of date;
- duplicate typedefs;
- missing symbol aliases;
- orphaned `INCLUDE_RODATA` lines;
- stale localdecomp scores;
- C functions whose retail code saves `$ra` with `sq`/`lq` but that are missing from `tools/sq_ra_funcs.txt` (a warning; see [Matching patterns](Matching-Patterns));
- retail files staged in git;
- every source file, and every slice of a file with mixed flags, compiles the way the build compiles it (under a minute; `--no-compile` skips it). This catches a declaration that clashes with a later block or a later file. On Linux it needs `UYA_TOOLCHAIN` and `UYA_RUNNER`, like `try_func.py`.

```
python tools/pr_check.py
python tools/pr_check.py --obj build/src/text.c.o      # also check the built object
python tools/pr_check.py --target all                   # every target
```

It also prints progress: C functions, `ASM_FUNC`, `LINKER_REMNANT`, remaining `INCLUDE_ASM`. Run it before every PR, then `make`.

---

## Building

### make and build.py

On Windows, use SN's `make.exe`:

```
& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe"          # build and check every target: one MATCH each
& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe" check-i5bootn   # one target (check-frontbin, check-boot_elf)
& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe" objdiff  # also build the objdiff/decomp.dev objects
& "C:\tools\eegcc_2.95.3_sn_v1.36\bin\make.exe" clean
```

On Linux or macOS, `tools/build.py` runs the same steps through wibo:

```
python3 tools/build.py --toolchain ~/sn --runner ~/bin/wibo
python3 tools/build.py --target all --toolchain ~/sn --runner ~/bin/wibo
```

Both do the same four steps:

1. Assemble the header and data.
2. Build `src/frontbin/*.c` with `build_text.py`.
3. Link.
4. Compare with `check_match.py`.

### build_text.py

Called by the build; you don't run it yourself. It compiles each file in `tools/src_files.txt` with its flags from `tools/text_parts.txt`: as it is when all its functions share flags, otherwise in slices (each with the file's own declarations, nothing from other files). Every file becomes one object in `build/src/frontbin/` (slice objects are kept apart in `build/src/frontbin/slices/`, so that folder holds exactly one `.o` per source file); they are linked into one `text.c.o`.

Its `function_context` function is what gives localdecomp, `try_func.py` and `permuter_setup.py` the same declarations as the real build.

### build_common_c.py

The opt-in build for the level-code C in `src/levels/common/` (listed in `tools/common_c.json`). It compiles each function with its frontbin donor's flags, compares it byte for byte with the retail common-level object made from your own overlays, and writes `build/objdiff/base/common.o`, the base of the `levels/common` unit. `make objdiff` runs it through `tools/common_c_base.py`, which takes the inputs from `C:\decomp-refs` (or `UYA_REFS`) and writes an empty base when they aren't there. Usage and the checks it applies: `docs/common_level_c.md`.

### split_text.py

`python tools/split_text.py --refresh` updates the "declarations from other files" section at the top of every source file (localdecomp does it for the file it saves into). `--from src/text.c` was the one-time split of the old single file. See `docs/source_files.md`.

### gen_objdiff_units.py

Rewrites the code units in `objdiff.json` for every target (one unit per source file: `frontbin/src/<file>`, `boot_elf/core/<file>`, `boot_elf/text/<file>`). Run it after adding or renaming a file.

### bootstrap_target.py

Makes a new target's source tree from its ELF, once the target is in `tools/targets.py` with its splat config and linker script: finds the functions with splat, classifies them (crt0, hand-written, remnant, compiled), estimates the source files and flags, writes `src/<target>/` and `targets/<target>/`, and runs `setup_asm.py`. i5bootn was set up with it (`python tools/bootstrap_target.py --target i5bootn`). It refuses to run once the tree has C. Steps for a new target are in `docs/targets.md`.

### elf2bin.py

`objcopy -O binary` in Python: each loadable segment's bytes at its load address. i5bootn's build uses it because SN's ee-objcopy corrupts 21 bytes of that file's section-name table (`flatten="elf2bin"` in `tools/targets.py`). It gives the same output as ee-objcopy for frontbin and boot_elf.

### seed_boot_elf.py

Copies frontbin's matched C into boot_elf's front end (`.text`), which is frontbin's code linked at other addresses. It renames every address through a frontbin to boot_elf table built from the paired assembly, builds, and puts back to INCLUDE_ASM whatever doesn't match. Rerun it whenever frontbin gains matches: `python tools/seed_boot_elf.py` on Windows (it runs `make check-boot_elf`), `python3 tools/seed_boot_elf.py --toolchain ~/sn --runner ~/bin/wibo` elsewhere. `bootstrap_boot_elf.py` is the one-time script that made boot_elf's first tree; it is kept as a record.

### asm_filter.py

Runs between gcc and the assembler in every build path (`build_text.py`, `try_func.py`, localdecomp, `permuter_setup.py`); you don't call it yourself. Retail's assembler padded every loop shorter than 6 instructions with `nop`s before the backward branch. Neither assembler we have does that: `ee-as` never pads such loops and Ps2EeAs pads them to 7. The filter adds the `nop`s to reach 6, then writes the branch as a raw `.word` so neither assembler pads it again. It handles branches gcc wrote in either `.set` mode; in reorder mode it counts the delay-slot `nop` the assembler adds after every branch (ee-as never fills a delay slot itself) and writes that `nop` out after the raw branch. Loops whose body contains a macro instruction or wider-than-4-byte alignment are left alone.

Without it, no C function containing a short loop could match. With it, loops match with no special C.

A load or store of a symbol (`lw $4, D_X`) inside such a loop counts as one word when an earlier `.extern D_X, N` with N <= 8 declares it small, since Ps2EeAs then uses `$gp` (one instruction). Before 2026-10-07 the filter gave up on those loops and Ps2EeAs padded them to 7 words (`func_003B8840`, `func_003AD288`).

The filter also rewrites the callee-saved saves of the functions listed in `sq_ra_funcs.txt` (retail's `sq` slots; see [Matching patterns](Matching-Patterns#functions-that-save-ra-with-sq)), and inserts the `nop`s before `div.s`/`sqrt.s` that `divs_nops.txt` lists.

### gen_divs_nops.py and divs_nops.txt

`tools/divs_nops.txt` has one line per function with the number of `nop`s retail has before each `div.s` and `sqrt.s`, in order (`func_0037E568 2`); `asm_filter.py` emits them as raw words. `python tools/gen_divs_nops.py` (`--target all` for every target) adds lines for functions that are still `INCLUDE_ASM` and keeps existing lines. The disassembler prints the EE's `sqrt.s` as a raw `c1` word; the script has recognised those since 2026-10-07 (before that, `func_003A26D0` and others were missing counts). Under `@ps2as`, a `div.s` right after `mtc1` needs one `nop` less than retail shows, because Ps2EeAs adds its own hazard `nop` (`func_003B5AB0`: `2 1 2` became `2 0 2`). The line travels with the function when it becomes C.

### check_match.py

The build's last step: compares the built binary with your `frontbin.elf` and prints MATCH, or the first differing offsets.

### text_parts.txt and localdecomp_flags.txt

Not scripts, but they decide how every function is compiled.

**`tools/text_parts.txt`: the per-address-range flags for the real build.**
- Each line is a start address and its flags.
- `-mno-split-addresses` selects no-split mode; `@ps2as` selects the SN Ps2EeAs assembler.
- A function that needs different flags from its range gets a single-function override line, followed by a line restoring the range's flags at the next function.
- Every frontbin and boot_elf line has `-mvu0-use-vf0-vf2` (since 2026-10-07; it was put first on the lines that didn't have it, so slice boundaries stayed; the older j-form overrides have it just before `@ps2as`). The build merges runs of lines with equal flag lists into one slice, so copy a neighbouring line's flags exactly as written when you add an override; appending the flag elsewhere, or writing the same flags in another order, changes which lines merge.

**`tools/localdecomp_flags.txt`: temporary per-function flags while you experiment.**
- Only localdecomp and `try_func.py` read it.
- Move the setting into `text_parts.txt` before your PR.

Details in [Toolchain and build](Toolchain-and-Build#text_partstxt).

---

## Source-tree maintenance

These tools change the repo. Most were used once to migrate the whole tree and are idempotent: running them again changes nothing unless there is new work.

### migrate_asm_sources.py

Moves functions that aren't decompilation targets out of `INCLUDE_ASM`:

- **Hand-written functions** (the original was assembly) go to `asm/handwritten/` as `ASM_FUNC(...)`.
- **Linker remnants** (the last word of a function the original linker stripped) go to `asm/remnants/` as `LINKER_REMNANT(...)`.

Both count as done in objdiff and decomp.dev. The script also comments out splat's `nonmatching` line, which would otherwise make objdiff flag the function as not matching.

### split_remnant_prefix.py

Finds `INCLUDE_ASM` functions that start with linker-remnant `[instruction, nop]` pairs. Splat had no symbol between the remnants and the real function after them, so it glued them together, and the result can't be matched as C.

```
python tools/split_remnant_prefix.py            # report
python tools/split_remnant_prefix.py --apply    # split them
```

`--apply` splits each one into a `LINKER_REMNANT` (the pairs) and a new `INCLUDE_ASM` function starting at the real address, for example `func_003A5870` becomes a remnant plus `func_003A5880`. The build stays byte-identical. It found and split 21 functions.

### trailing_padding.py

Finds functions followed by more `nop`s than gcc's 8-byte alignment adds. Converting such a function to C would drop those words and shift everything after it.

```
python tools/trailing_padding.py            # report
python tools/trailing_padding.py --apply    # add TEXT_PADDING(N) after each and trim its .s
```

After `--apply`, a function can be converted to C with no extra step. See `docs/trailing_padding.md`.

### migrate_jtbls.py

Moves each `switch` jump table from the data blob into the sources as an `INCLUDE_RODATA` line right after its function's `INCLUDE_ASM`. That lets a C `switch` put its table in the right place. When you convert such a function, delete its `INCLUDE_ASM` and `INCLUDE_RODATA` lines together.

### fix_reg_names.py, fix_quadword_ops.py, fix_short_loops.py

These patch splat's `.s` output so SN's `ee-as.exe` assembles it to retail bytes:

| Script | Fixes |
|---|---|
| `fix_reg_names.py` | ABI register names become numbers (`$a0` to `$4`); `%gp_rel` forms ee-as can't parse |
| `fix_quadword_ops.py` | `lq`/`sq`/`lqc2`/`sqc2`, which ee-as doesn't know, become raw `.word`s |
| `fix_short_loops.py` | Short-loop branches become raw `.word`s, so ee-as doesn't pad them with an extra `nop` |

You only need these after re-running splat.

### extract_header.py

Regenerates `asm/header.s` (the ELF header bytes) from your own `frontbin.elf`. Only needed after re-splitting.

### reconcile.py

Normalizes `undefined_funcs_auto.txt` and `undefined_syms_auto.txt`, so both symbol spellings (`D_143950` and `D_00143950`) and suffixed aliases resolve. Run it if the link reports undefined `D_` symbols after regenerating the symbol files.

### gen_level_targets.py

Generates the objdiff *target* objects for the level overlays, so decomp.dev can count their functions (at 0% until someone decompiles a level). They come from retail files, so they are never committed. CI keeps them in `C:\decomp-refs\level-targets\`.

### gen_exe_targets.py

Builds objdiff target objects for `boot_elf.elf`, `i5bootn.elf`, `ntgui.elf` and `sly2.elf`, which have no symbols. Functions are found with splat; the code bytes are copied straight from the ELF. Output goes to `C:\decomp-refs\exe-targets\` (never the repo); `--objdiff objdiff.json` rewrites their units. See [Toolchain and build](Toolchain-and-Build#other-executables).

### split_shared_levels.py

Turns those objects into common and level-specific code and data, so shared content is counted once. It writes `common.o`, `common_data.o`, `uninitialised.o` (`.bss` and zero words), one code object per level (shared functions demoted, data emptied) and one `_data.o` per level, and with `--objdiff objdiff.json` rewrites the level units and categories. See [Toolchain and build](Toolchain-and-Build#level-overlays). Output goes to `C:\decomp-refs\level-targets-split\`, never into the repo.

---

## Other files in tools/

- `requirements.txt`: Python packages for the tools (pyelftools, capstone).
- `decomp-permuter-aligned-scorer.patch`: the hook that lets decomp-permuter use [`permuter_scorer.py`](#permuter_scorerpy).
- `remaining_functions.tsv`: an older copy of `triage.py --tsv` output. `docs/remaining_functions.tsv` is the current one.
