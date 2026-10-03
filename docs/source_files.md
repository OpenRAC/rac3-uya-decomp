# Source files

frontbin's `.text` is written as one C file per original source file, in `src/frontbin/`, instead of the single `src/text.c` the project started with. This page explains the layout, where the file boundaries come from, and how to change them.

## Layout

- `tools/src_files.txt` lists the files in link order, each with the address of its first function. A function belongs to the file whose range contains its address.
- Each file holds its functions in address order, written exactly as before:
  - C between `/* localdecomp:start func_X */` and `/* localdecomp:end func_X */`, with the block's own externs, typedefs and prototypes in front of the function;
  - `INCLUDE_ASM`, `ASM_FUNC`, `LINKER_REMNANT`, `INCLUDE_RODATA` and `TEXT_PADDING` lines for everything else.
- At the top of each file, between the `declarations from other files` markers, are the declarations from earlier files that this file's functions use. Nothing else from other files is visible: each file compiles on its own, like the original translation units.

Files are named after their first function's address (`src/frontbin/3E1CC8.c`) until we know what they really were. Renaming one is a one-line change in `tools/src_files.txt` plus `python tools/gen_objdiff_units.py`.

## Declarations from other files

`python tools/split_text.py --refresh` recomputes that section for every file: each statement from an earlier file (in link order) that declares a name the file uses, plus whatever those statements need in turn (a typedef's struct, a macro's expansion). localdecomp runs it for the file it saves into. `pr_check.py` reports a file whose section is out of date.

`try_func.py`, `try_in_context.py`, the permuter and localdecomp compile a function with its file's declarations, the declarations of the earlier functions in the same file, and anything from earlier files the new code needs that the file doesn't declare yet.

Before the split, every build part was given every declaration from every earlier part, up to 2,700 lines and 110 KB in front of the last parts. Now the whole tree has about 460 lines of cross-file declarations, at most 30 in one file.

## How a file is built

`tools/build_text.py` compiles each file with the flags `tools/text_parts.txt` gives its functions:

- If all functions in the file use the same flags, the file is compiled as it is, once.
- If some functions only match with other flags (marked `# single-function override` in `text_parts.txt`), the file is compiled in slices, one per run of equal flags. Each slice gets the file's prelude and the declarations of the file's earlier functions, then its own functions.

Every file ends up as one object, `build/src/frontbin/<file>.o` (a sliced file's per-slice objects are in `build/src/frontbin/slices/`, so `build/src/frontbin/` and `build/objdiff/target/frontbin/` hold exactly one `.o` per source file). They are linked into `build/src/text.c.o`, so the linker script is unchanged. objdiff has one unit per file (`frontbin/src/<file>`).

Most overrides are about the assembler. Retail was assembled by Ps2EeAs. Some functions only match with it, but it can't read the `INCLUDE_ASM` stubs, so a file that still has stubs uses `bin/ee-as.exe` and its Ps2EeAs functions become slices. As the stubs disappear, a file can switch to `@ps2as` as a whole and lose its slices.

## Where the boundaries come from (2026-10-03)

The original file names and boundaries aren't in the ELF, so the current 65 files are a best estimate from four kinds of evidence:

1. **Address mode.** `-mno-split-addresses` was set per source file. For each of the 1,037 C functions, every combination of S/N mode and assembler was tried: 297 functions only match in S mode, 116 only in N mode, 624 in either. A boundary was placed between every run of three or more S-only functions and the next run of N-only ones (and the other way round). One- and two-function islands inside a run of the other mode were kept as per-function overrides: they are more likely a declaration artifact than a separate file.
2. **Small data.** Each file's small-data variables sit together in `.lit`, in link order. Two functions that use the same file-local variable must be in the same file, and a file's variables can't come after the next file's. That rules out a cut in 1,084 of the 1,866 gaps between functions. 23 clusters of gaps where both sides use small data and nothing overlaps were taken as boundaries.
3. **Linker fill.** The `0xCD` fill at 0x39B1A0 is the one alignment gap between input files inside `.text`.
4. **Hand-written assembly.** A run of three or more `ASM_FUNC` functions (with only linker remnants between them) is its own file, since the original was a `.s` file.

Where evidence 1 places a boundary between two functions somewhere in a gap, the cut uses evidence 2 when it can, otherwise the position right after a linker remnant, otherwise just before the next run.

These boundaries are only the best estimate so far. Moving one changes nothing in the output as long as every function keeps its flags. If you find better evidence (a function that is clearly part of another group, shared code with `boot_elf.elf` that marks a file, a real file name), edit `tools/src_files.txt`, move the blocks, run `python tools/split_text.py --refresh` and `python tools/gen_objdiff_units.py`, and check `make`.

## Migration notes

The split was done with `python tools/split_text.py --from src/text.c`. Merging functions that used to be compiled apart into one file exposed four prototype conflicts. Each was solved the usual way, with a per-function alias (`func_00399748_003997F0`, `func_0039C158_0039C170`, `func_003AC0D8_003ACED0`, `func_003BF5D0_003BF5E0`), plus `extern void func_0039C158();` where only its address is taken.

A branch that still edits `src/text.c` can be carried over: put its `text.c` back temporarily and rerun the split with the same `tools/src_files.txt`:

1. Check out the branch's `src/text.c` (and its `tools/text_parts.txt` lines for the functions it adds) into a checkout of current `main`.
2. `python tools/split_text.py --from src/text.c`, then delete `src/text.c`.
3. `python tools/split_text.py --refresh`.
4. Put the branch's flag lines for its new functions into `tools/text_parts.txt` as single-function overrides, then check with `python tools/pr_check.py` and `make`.

The pull requests open at the time of the split were merged into `text.c` first and split together with it, so none of them needs this.
