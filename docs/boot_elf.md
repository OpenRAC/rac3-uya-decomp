# boot_elf.elf

`boot_elf.elf` is the game's main executable. The repo builds it byte for byte
the same way as `frontbin.elf`: `make check-boot_elf` (or `make`, which builds
both) ends with

```
MATCH: build/boot_elf/boot_elf.bin sha1 487975305f8a263c750dfede50391b575ed07835 (0x35EE64 bytes)
```

Every tool that works on frontbin works on boot_elf with `--target boot_elf`
(or `UYA_TARGET=boot_elf`). Where each target's files live is in
`tools/targets.py`.

## Setup

1. Put your own `boot_elf.elf` in the repo root (it is in the root of the
   unpacked disc, next to `files` and `levels`). Its sha1 must be
   `487975305f8a263c750dfede50391b575ed07835`. It is gitignored; never add it.
2. `python tools/setup_asm.py --target boot_elf` writes `asm/boot_elf/` (also
   gitignored). It is the same process as frontbin's: splat, the assembler
   fix-ups, hand-written functions and linker remnants moved to
   `asm/boot_elf/handwritten` and `asm/boot_elf/remnants`, trailing padding
   cut, the data blob split around its jump tables.
3. `make check-boot_elf` on Windows, `python3 tools/build.py --target boot_elf`
   on Linux and macOS.
4. CI and localdecomp's Full check copy `C:\decomp-refs\asm`, so copy
   `asm\boot_elf` into `C:\decomp-refs\asm\boot_elf` and `boot_elf.elf` into
   `C:\decomp-refs`.

## Layout

The file is a straight memory image: every section sits at its own file
offset, and the gaps (both `.bss` regions included) are zeros. $gp is
`0x1DC8B0`, the same as frontbin.

| Section | Address | Size | Built from |
|---|---|---|---|
| header, `.reginfo` | file 0x0 | 0x2000 | `asm/boot_elf/header.s` |
| `.vutext` | 0x100080 | | `asm/boot_elf/data/vutext.data.s` (VU microcode, kept as data) |
| `core.text` | 0x116F80 | 0x264A0 | `src/boot_elf/core/*.c` (13 files) |
| `core.data`, `core.rdata`, `core.lit` | 0x13D480, 0x150080, 0x1D4D80 | | `asm/boot_elf/data/core_*.data.s` |
| `.lit`, `.data` | 0x1D5680, 0x31BE80 | | `asm/boot_elf/data/lit.data.s`, `data_a`/`data_b` around the front end's jump tables |
| `lvl.vtbl`, `lvl.camvtbl`, `lvl.sndvtbl` | 0x381000.. | | `asm/boot_elf/data/lvl_*.data.s` |
| `.text` | 0x381180 | 0x71438 | `src/boot_elf/text/*.c` (65 files) |
| `patch.data`, `legal.data`, `mc1.data` (2) | 0x3F2600, 0x1800000, .. | | `asm/boot_elf/data/*.data.s` |
| `.shstrtab`, section headers | file 0x35EA98 | | `asm/boot_elf/trailer.s` |

The tables that frontbin keeps in `tools/` are in `targets/boot_elf/`:
`src_files.txt`, `text_parts.txt`, `divs_nops.txt`, `sq_ra_funcs.txt`,
`localdecomp_flags.txt`, `symbol_addrs.txt` and `symbol_addrs_resolved.txt`.
The linker script is `linker_scripts/boot_elf.ld`, the splat config
`boot_elf.splat.yaml`.

Function names are `func_<address>` in both executables, so the same name can
mean two unrelated functions (`func_00381180` exists in both). Anything keyed
by function name is per target.

## The two code sections

**`.text` (the front end).** It is frontbin's code linked at other addresses:
1812 of frontbin's 1853 functions are the same instructions once address
immediates are masked (96% of the bytes), and only 21 frontbin functions
differ. Its source files start where frontbin's do (65 files), and every
function has the flags its frontbin twin has. `tools/seed_boot_elf.py` copied
frontbin's matched C into it (1359 functions); see below.

**`core.text` (the engine core).** New code, including Sony's libraries. Its
13 source files are a first cut (runs of hand-written code and runs that need
another flag set). Things to know:

- 63 core functions start on a 4-byte boundary, not 8. Each object's `.text`
  is 8-aligned, so a source file can only start at an 8-aligned function; the
  file boundaries were moved to respect that.
- Some core code switches `$gp` (`lw $gp, %lo(sym)($v0)`).
  `tools/fix_reg_names.py` no longer rewrites a load into `$gp`.
- `core.rdata` is not split: the core's jump tables sit between each source
  file's strings and constants, so splitting it means giving every piece to
  its file. That is needed before a core function with a `switch` can become
  C. Until then those stay INCLUDE_ASM.

## Seeding from frontbin

```
python tools/seed_boot_elf.py                                    (Windows)
python3 tools/seed_boot_elf.py --toolchain ~/sn --runner ~/bin/wibo   (Linux/macOS)
```

It pairs frontbin's functions with their boot_elf twins, builds a frontbin to
boot_elf address table from the paired assembly (3709 addresses, plus
neighbour shifts for addresses the assembly never shows), renames every
`D_`/`func_` in each matched frontbin block, inserts it in place of the
twin's INCLUDE_ASM, refreshes the declarations and symbols, then builds and
compares every seeded function with retail. Whatever doesn't match goes back
to INCLUDE_ASM until the build prints MATCH. Functions already C in boot_elf
are left alone, so **rerun it whenever frontbin gains matches**. It needs both
ELFs and both asm trees.

The first run seeded 1359 of 1386 candidates. 27 went back to INCLUDE_ASM:
`func_0039DB38` (its typedef `Pad_39DB38` belongs to a function that differs
in boot_elf) and 26 that compile but differ. They are worth a look: the
frontbin C is a good starting point.

`tools/bootstrap_boot_elf.py` is the one-time script that made the first
tree (pairing, file split, flags, `divs_nops`/`sq_ra_funcs` carried over). It
is kept as a record; don't rerun it on a tree with work in it.

## localdecomp

The dropdown at the top of the function list picks the executable. Each one
has its own list, progress bar, editor cache (`.localdecomp_work/boot_elf/`)
and Save target; Full check builds and compares everything and shows the
numbers for the executable that is picked.

## Progress report

`objdiff.json` has one unit per source file, `boot_elf/core/<file>` and
`boot_elf/text/<file>` (`python tools/gen_objdiff_units.py` writes them for
every target), in the progress categories `boot_elf`, `boot_elf_core` and
`boot_elf_frontend`. They replace the old reference-only `exes/boot_elf`
code unit; `exes/boot_elf (data)` stays.
