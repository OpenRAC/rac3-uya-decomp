# veldin (level 1's overlay)

`veldin` builds Veldin's level overlay, `levels/singleplayer/1_veldin/overlay.elf`,
byte for byte:

```
MATCH: build/veldin/veldin.bin sha1 63ac546a87a15766052360cc9e2361ebd1600da0 (0x3497A4 bytes)
```

It is the first level built as a whole program. The other 50 overlays have
the same layout and can follow the same way.

## Setup

1. Copy your own `levels\singleplayer\1_veldin\overlay.elf` from the unpacked
   disc to `baserom/veldin.elf` (gitignored; never add it). Its sha1 must be
   `63ac546a87a15766052360cc9e2361ebd1600da0`.
2. `python tools/setup_asm.py --target veldin` writes `asm/veldin/` (gitignored).
3. `make check-veldin` on Windows, `python3 tools/build.py --target veldin` on
   Linux and macOS. It isn't part of `make check` yet.

Every tool takes `--target veldin` (or `UYA_TARGET=veldin`).

## Layout

A level overlay has frontbin's layout at other addresses: one PT_LOAD from file
offset 0x1000.

| Section | Address | File offset | Size |
|---|---|---|---|
| `.lit` | 0x1D5680 | 0x1000 | 0xA120 |
| `.bss` | 0x1DF800 | (zeros on disk, part of the `lit` segment) | 0xC4C40 |
| `.data` | 0x2A4480 | 0xCFE00 | 0x52390 |
| `lvl.vtbl`, `lvl.camvtbl`, `lvl.sndvtbl` | 0x2F6880, 0x2F7700, 0x2F7800 | 0x122200.. | |
| `.text` | 0x2F7880 | 0x123200 | 0x2263F8 |

The header (0x0..0x1000) and the trailer (`.shstrtab` and the section header
table, 0x3495F8..0x3497A4) are raw blobs. The entry point is 0x3EE988.

`tools/bootstrap_target.py` made the tree: 5621 entries in 81 estimated source
files (4982 INCLUDE_ASM, 162 hand-written ASM_FUNC, 477 LINKER_REMNANT).

## Per-file data

The original linker put each source file's data at that file's place in link
order, so a source file that emits data (a `switch`'s jump table, a variable,
a float literal) needs its data linked there, not in one block as in frontbin.
`.lit` and `.data` are therefore linked from two kinds of pieces:

- the segment's retail bytes, with the labels of `asm/veldin/data/lit.data.s`
  and `data.data.s` (`build/veldin/data/lit.s`, `data.s`);
- the data sections of the source files listed in
  `config/veldin/data_split.txt`, each linked at its retail address in place
  of the bytes there.

`tools/split_data.py` (run by `make check-veldin` and `tools/build.py` after
`build_text.py`) cuts the segments around the placed sections and writes the
two output sections `linker_scripts/veldin.ld` INCLUDEs
(`build/veldin/data/lit.ld`, `data.ld`). With an empty table they are the
segments as they were.

### Where each file's data is

`.data` (0x2A4480..0x2F6880) holds four blocks, each in link order. "Early"
files are the ones linked before the entry point's file (code 0x2F7880 to
0x3EE988), "late" files the rest (0x3EE988 on):

| Block | Addresses | What |
|---|---|---|
| early files' `.data` | 0x2A4480..0x2BB8AC | variables and tables |
| late files' `.rodata` | 0x2BB8B0..0x2BE730 | jump tables and constant tables |
| early files' `.rodata` | 0x2BE730..about 0x2BF300 | jump tables and constant tables |
| late files' `.data` | about 0x2BF300..0x2F6880 | variables and tables |

All 149 jump tables are in the two `.rodata` blocks, in the order of the
functions that use them, 16-byte aligned (gcc's `.align 4`), with the files'
other read-only data between them. `0xCDCDCDCD` words are the linker's fill
before an input section that needed alignment, so they mark some file
boundaries.

`.lit` (0x1D5680..0x1DF7A0) is the small data, late files first (from
0x1D56C0), then early files (from 0x1DC300). gcc's MIPS port puts every object
of at most 8 bytes (`-G8`) into `.sdata`: small variables, small constant
arrays, even strings like `"%d"`. So a file's part of `.lit` is its small
variables and constants in definition order, and this is what Veldin's code
reads through `$gp`: `lwc1 $f13, 0x1CCC($gp)` in `func_003AF490` is the file's
`f32 D_001DE57C = 10.0f`, not a literal (10.0 is `lui`+`mtc1` when it is a
literal, and the same function builds its other constants with `lui`/`ori`, as
Ps2EeAs does). GNU as's `.lit4` literals (`li.s` with a non-zero low half,
`lwc1` from `$gp`) can be placed the same way (a row with `.lit4`), but
Veldin's code shows few signs of them: of the Veldin-only functions only
`func_004D8060` fits the pattern (each `$gp` float loaded once, in ascending
contiguous order, none `lui`-able), with a single constant at 0x1DBC74 that
could as well be a variable.

`.bss` (0x1DF800..) mixes early and late files: common symbols are allocated
by the linker, not per file. Only a file's own `.sbss`/`.bss` (static
variables) can be placed.

### Converting a function that needs its data

1. Write the function in C in its range file, as usual.
   - A `switch`: the table's address is the `jtbl_` label in the function's
     `.s`; its entries say which case is which. gcc emits the table in the
     file's `.rodata`.
   - A variable the function reaches through `$gp` (retail: defined in the
     same file): define it in the file, named after its address, with its
     retail value from `asm/veldin/data/lit.data.s`, in address order (gcc
     emits initialized variables in definition order). A variable that retail
     reaches with `lui` belongs to another file: keep it `extern`.
   - Which assembler: retail's `$gp`-or-`lui` choice is Ps2EeAs's (`@ps2as`):
     a variable defined in the file gets `$gp`, an `extern` gets `lui`. With
     GNU as (the default) an `extern` of at most 8 bytes gets `$gp` too
     (gcc writes `.extern NAME, SIZE` at the end of the file), so a function
     that mixes them needs `@ps2as`.
2. Add a row to `config/veldin/data_split.txt`: the section, the address of
   its first byte and the file:

       .rodata     0x002BF270  src/veldin/3DF888.c
       .sdata      0x001DE57C  src/veldin/3ADAC0.c

   A row places the file's whole section, so it must be exactly the retail
   bytes from that address: if two functions of one file have data that isn't
   adjacent in retail, convert what lies between too, or define it in the file
   as data (a `const` array, as frontbin's `func_003BC218` does).
3. `make check-veldin`. `tools/split_data.py` stops on a section that isn't
   aligned for its address, overlaps another row or lies outside the segments,
   and on data that some source emits without a row (the link would discard
   it). `tools/pr_check.py --target veldin` accepts variable definitions only
   in files that have a row.

The first three conversions use one each: `func_003DFF88` (a `switch`, table
at 0x2BF270), `func_003AF490` (three `f32` file variables read with `lwc1`
through `$gp`, `@ps2as`), `func_003116E8` and `func_003116F0` (`D_001DC6E8`
defined in the file and reached through `$gp`, `D_001E17B0` another file's
through `lui`; `@ps2as` for the two).

### Another level

The same steps work for any overlay with Veldin's layout: give its target
`data_split` and `data_segments` (file start, file end and address of each
data segment) in `tools/targets.py`, replace the segments' output sections in
its linker script by `INCLUDE build/<target>/data/<segment>.ld`, and add the
`split_data.py` step to its Makefile section (see Veldin's).

## Relation to the shared level code

Most of Veldin's code is shared with the other levels (`src/levels/common/`,
`docs/common_level_c.md`), and Veldin is the canonical owner of all of it, so
the common sources already use Veldin's addresses. `tools/link_common_sources.py`
builds Veldin from them directly: each catalogued function is its own source
file in `config/veldin/src_files.txt`, at its address, with the flags it was
proved with (`# common source` lines in `config/veldin/text_parts.txt`), and the
range files in `src/veldin/` hold everything between them. There is one copy of
each function, used by both `build_common_c.py` and `make check-veldin`.

    python tools/link_common_sources.py --target veldin
    python tools/split_text.py --refresh --target veldin
    make check-veldin

A function only stands alone when the next entry starts at its 8-aligned end
(objects are 8-aligned); 17 are followed by padding and stay INCLUDE_ASM. The
shared sources are standalone (`srcfiles.standalone`): `split_text --refresh`
leaves them as they are and doesn't offer their declarations to other files.
The linked functions' entries in Veldin's own `divs_nops.txt`/`sq_ra_funcs.txt`
are dropped, since the common-level tables cover them.

Run the tool on a tree with no common sources linked yet (it refuses
otherwise). New matches in `config/levels/common_c.json` come in by resetting
`src/veldin/` and `config/veldin/` and running it again.
