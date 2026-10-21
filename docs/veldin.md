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
   disc to `veldin.elf` (gitignored; never add it). Its sha1 must be
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

## Jump tables

Unlike frontbin's, Veldin's switch jump tables aren't one block: they sit among
the other data all through `.data` (each original source file's read-only data
between its data). So `.data` is assembled whole (`jtbl_segments` is empty in
`tools/targets.py`) and a switch function stays INCLUDE_ASM until `.data` is
split per source file.

## Relation to the shared level code

Most of Veldin's code is shared with the other levels (`src/levels/common/`,
`docs/common_level_c.md`), and Veldin is the canonical owner of all of it, so
the common sources already use Veldin's addresses. `tools/link_common_sources.py`
builds Veldin from them directly: each catalogued function is its own source
file in `targets/veldin/src_files.txt`, at its address, with the flags it was
proved with (`# common source` lines in `targets/veldin/text_parts.txt`), and the
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
otherwise). New matches in `tools/common_c.json` come in by resetting
`src/veldin/` and `targets/veldin/` and running it again.
