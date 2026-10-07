# Toolchain and build

How `make` turns the repo into a byte-identical `frontbin.elf`, and which files you touch when a function needs something special. `boot_elf.elf` and `i5bootn.elf` are built the same way from their own tables (`targets/<target>/`, see `docs/targets.md`); `make` builds and checks all three.

## Pipeline

1. `asm/header.s` (the retail ELF header) and the data segments `asm/data/{lit,data_a,data_b,lvl_vtbl,lvl_camvtbl,lvl_sndvtbl}.data.s` are assembled with `bin/ee-as.exe`.
2. `src/frontbin/*.c` (one file per original source file, listed in `tools/src_files.txt`) are built by `tools/build_text.py`. Each file is compiled with its flags from `tools/text_parts.txt` (in slices if some functions need other flags), giving one object per file in `build/src/frontbin/` (the per-slice objects go in `build/src/frontbin/slices/`), and the objects are joined with `ld -r` into `build/src/text.c.o`. See `docs/source_files.md`.
3. `ee-ld.exe -T linker_scripts/frontbin.ld` places every section at its retail file offset. `INPUT(symbol_addrs_resolved.txt)` supplies the address of every external symbol. The `.data` output is `data_a` + `text.c.o(.rodata)` (all switch jump tables, in function order) + `data_b`, the same layout the original linker produced.
4. `ee-objcopy -O binary` makes `build/frontbin.bin`, and `tools/check_match.py` compares its SHA-1 with the one in `frontbin.splat.yaml`. That is the `MATCH` line.

`make objdiff` also builds the objdiff inputs, one unit per source file: `build/objdiff/target/frontbin/<file>.o` (the full build) and `build/objdiff/base/frontbin/<file>.o` (the same file with every `INCLUDE_ASM` compiled away), so objdiff reports decompiled/total per file. It also builds `build/objdiff/base/common.o`, the base of the `levels/common` unit, from the common-level C in `src/levels/common/` (`tools/common_c_base.py`, which runs `tools/build_common_c.py` against the reference files in `C:\decomp-refs`; without them it writes an empty base).

`tools/build.py` runs steps 1 to 4 on Linux and macOS through wibo.

## Compiler and flags

- Compiler: SN ee-gcc 2.95.3 v1.36 (`bin/ee-gcc2953.exe`).
- Every frontbin and boot_elf range: `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division`. i5bootn uses `-O2 -G0 -fopt-stack -mno-check-zero-division` (nothing there uses `$gp`) and no VU0 flag; it builds the same at every VU0 range.
  - `-mvu0-use-vf0-vf2` (Sony's patch-set option, "Specify the range of vu0 registers to use") makes `$vf1` and `$vf2` allocatable for the `j` asm constraint that the [VU0 j-form](Matching-Patterns#vu0-j-form-one-asm-statement-per-instruction) uses. It also raises `n_non_fixed_regs`, which loop.c uses in its hoisting and strength-reduction thresholds, so it changes ordinary code too. N = 2 is the only range that fits every j-form match and the whole build; it has been on every line since 2026-10-07.
  - `-fopt-stack` (SN-only) saves `$s` registers with `sd` in 8-byte slots instead of `sq` in 16-byte ones.
  - `-mno-check-zero-division` drops the `break 7` trap after `div`.
  - `-G8` puts objects of 8 bytes or less in small data (`$gp`), which is why declarations matter ([Matching patterns](Matching-Patterns#globals-gp-vs-lui)).
- Some ranges add `-mno-split-addresses`. A few files or functions differ in other flags: `3958F0.c` adds `-fno-force-mem` (five of its functions have overrides without it), `func_00394060` adds `-fno-rerun-loop-opt`, and three boot_elf core functions drop `-mno-check-zero-division`.
- The Makefile adds `-B$(TOOLBIN)/ee-` so gcc uses `bin/ee-as.exe`, and `-Wa,...` options for the GNU assembler that the `INCLUDE_ASM` stubs need.

## text_parts.txt

One line per range: a start address, then the flags used from there up to the next line.

```
0x0037D100     -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division
0x0037D1A8     -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses   # single-function override
0x0037D200     -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as   # single-function override
0x0037DC30     -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division
```

Every source file starts with a line at its first function's address: those are the file's flags. A **single-function override** is two lines: one at the function's address with its flags, and one at the next function's address that restores the file's flags. Mark the first with `# single-function override`. The build compiles such a file in slices (see `docs/source_files.md`).

The build groups a run of lines with **equal flag lists** into one slice. Two adjacent `@ps2as` overrides therefore become one slice, and the first function's `.extern` hints then reach the second. Writing the same flags in another order makes the lists unequal and keeps the slices apart (the large-function batch used this for `func_003D2878`); per-function alias names in the later block are the other fix. The same rule is why `-mvu0-use-vf0-vf2` was put first on the lines that didn't have it: appending it would have made more neighbouring lines equal, merged their slices and exposed declaration conflicts (the first in `39FFC8.c`). Copy a neighbour's flags exactly as written when you add a line.

Pseudo-flags, expanded by `build_text.py`, localdecomp and `try_func.py`:

| Flag | Effect |
|---|---|
| `@ps2as` | Assemble with `ee/bin/Ps2EeAs.exe`. Adds `-DNO_MACRO_INC` and drops `-Wa,` options, which Ps2EeAs doesn't understand. The range (file or slice) must contain no `INCLUDE_ASM`. |
| `@newas` | Assemble with `ee/bin/as.exe` (May 2001). |

gcc uses the last `-B` on its command line, so a range's assembler choice wins over the Makefile default.

There is no compiler pseudo-flag yet. boot_elf's engine core and most of i5bootn were built with Sony's library compilers (2.9-ee-991111-01, and 2.96 for boot_elf's newlib region; see `docs/boot_elf.md` and `docs/compiler_matrix_i5bootn.md`), so about 440 core functions and the libgcc code stay assembly until a per-file pseudo-flag can pick one of those compilers, the way `@ps2as` picks an assembler.

## localdecomp_flags.txt

`tools/localdecomp_flags.txt` gives a **work-in-progress** function its own flags in localdecomp and `try_func.py` while it is still `INCLUDE_ASM` in its source file (an `@ps2as` range can't contain the asm stub, so `text_parts.txt` can't hold it yet):

```
func_0039BEC0 -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as
```

The line replaces the range's flags, so it needs `-mvu0-use-vf0-vf2` too (the two lines in the file on 2026-10-07 predate the flag). When the function matches, move its flags to a single-function override in `text_parts.txt` and delete the line. `pr_check.py` warns about leftovers.

## Symbol files

| File | Used by | Holds |
|---|---|---|
| `symbol_addrs_resolved.txt` | the linker | `NAME = 0xADDR;` for every external symbol, including per-function aliases. Add yours here. |
| `symbol_addrs.txt` | splat | Names for splat's disassembly |
| `undefined_syms_auto.txt`, `undefined_funcs_auto.txt`, `reloc_addrs.txt` | splat | Generated by splat. Don't edit by hand. |

## include/

- `common.h`: the `s8`...`f64` typedefs and `include_asm.h`.
- `include_asm.h`: the `INCLUDE_ASM` and `INCLUDE_RODATA` macros (the latter pulls an asm function's jump table from `asm/nonmatchings/text/rodata/`), the `OBJDIFF_BASE` switch that compiles stubs away, and the `NO_MACRO_INC` guard for `@ps2as` ranges.
- `macro.inc`, `labels.inc`: splat's assembler macros for the stubs.

## CI

`.github/workflows/build-and-report.yml` runs on pushes to `main`, on the maintainer's self-hosted Windows runner that has the toolchain and retail files. It builds, requires `MATCH`, and uploads an objdiff progress report. It does not run on pull requests from forks (the runner holds copyrighted files and must not run untrusted code), so reviewers build PRs locally.

## Level overlays

Level overlays are counted in progress reports through target objects made from your own unpacked overlays. They're derived from retail code, so they are never committed. Decompiling them has started with a few shared functions in `src/levels/common/`, checked by the opt-in `tools/build_common_c.py` (not part of `make`; see `docs/common_level_c.md`).

About 95% of the code in the 51 overlays is shared: the same function appears, at different addresses, in two or more of them. Reporting each overlay on its own made decomp.dev show about 100 MB of level code to decompile when only about 9.4 MB is distinct. So the report is split:

| Category | Unit(s) | What it counts |
|---|---|---|
| Common level code | `levels/common` | every function that appears in two or more overlays, once (about 4.3 MB, 7,779 functions) |
| Level-specific code | one unit per level | functions found in only one overlay (about 5.1 MB) |
| Level N: Name | the level's code unit | that level's specific code |
| Common level data | `levels/common data` | `.data`/`.lit` content found in two or more overlays, once (about 0.26 MB) |
| Level-specific data | one `(data)` unit per level | the rest of each level's non-zero data, plus its `lvl.*` vtables (about 0.49 MB) |

"Same function" means the same bytes once `j`/`jal` targets are masked. Data has no function boundaries, so it is matched by content: a 16-word window (at least 8 words non-zero) that occurs in two or more overlays is shared, with address-like words treated as wildcards because shared data holds pointers that move. This is meant for progress numbers. Its run boundaries are approximate, so it isn't a guide to where data sits in a real level build.

`.bss` (52.7 MB over all levels) and zero words inside `.data`/`.lit` (8.0 MB) have nothing to decompile, only a size. They are written to `uninitialised.o` but left out of `objdiff.json` so they don't swamp the data total. Pass `--include-zero-fill` to list them as a "Zero-filled data" category.

The pipeline runs outside the repo, in two steps:

```
python3 tools/gen_level_targets.py <levels_dir> C:\decomp-refs\level-targets
python tools/split_shared_levels.py C:\decomp-refs\level-targets C:\decomp-refs\level-targets-split --objdiff objdiff.json
```

The second step writes 105 objects (`common.o`, `common_data.o`, `uninitialised.o`, 51 code objects, 51 data objects) and rewrites the level units and categories in `objdiff.json`. Only the script and `objdiff.json` are committed. The tool refuses to write into the repo (other than `build/`). Re-run it if the overlays are regenerated or a level starts being decompiled.

## Other executables

`boot_elf.elf`, `i5bootn.elf`, `ntgui.elf` and `sly2.elf` (from the unpacked disc) are also counted. They have no symbols, so `tools/gen_exe_targets.py` finds functions the way the level generator does (every `jal` target, then splat), but builds each object straight from the ELF bytes, so the code is retail by construction. It writes `<name>.o` (code sections) and `<name>_data.o` (other allocated sections with bytes: `.data`, `.rodata`, `.lit`, `.irx`, VU microcode) to `C:\decomp-refs\exe-targets\`, and with `--objdiff objdiff.json` adds their units and categories (one per executable, all under "Other executables"):

```
python tools/gen_exe_targets.py "<game_dir>" C:\decomp-refs\exe-targets --objdiff objdiff.json
```

About 3.0 MB of code in 15,146 functions and 6.6 MB of data. The objects have no relocations and are never committed. `.bss` and `.sbss` are left out (nothing to decompile). The main executable `SCUS_973.53` is not among these files and isn't counted yet.
