/* Veldin's level overlay, levels/singleplayer/1_veldin/overlay.elf (see
   tools/targets.py and docs/veldin.md).

   frontbin's layout at other addresses: one PT_LOAD from file offset 0x1000.
   Every section sits at its retail file offset (AT(...)); the gaps between
   them are zeros. Sections are named after splat's segments
   (veldin.splat.yaml). */

INPUT(targets/veldin/symbol_addrs_resolved.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes. */
    .header 0x0 : AT(0x0)
    {
        build/veldin/asm/veldin/header.s.o(.data);
    }

    /* .lit, then .bss, which the file stores as zeros (as frontbin's does). */
    .lit 0x1D5680 : AT(0x1000)
    {
        build/veldin/asm/veldin/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* .data, whole: its jump tables are spread among the other data, so it
       isn't split around them as frontbin's is (switch functions stay
       INCLUDE_ASM for now, see tools/targets.py). */
    .data 0x2A4480 : AT(0xCFE00)
    {
        build/veldin/asm/veldin/data/data.data.s.o(.data);
    }

    .lvl_vtbl 0x2F6880 : AT(0x122200)
    {
        build/veldin/asm/veldin/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x2F7700 : AT(0x123080)
    {
        build/veldin/asm/veldin/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x2F7800 : AT(0x123180)
    {
        build/veldin/asm/veldin/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: src/veldin/ (tools/build_text.py --target veldin). */
    .text 0x2F7880 : AT(0x123200)
    {
        build/veldin/src/text.c.o(.text);
    }

    /* .shstrtab and the section header table (file 0x3495F8..0x3497A4), raw
       bytes. Its address is arbitrary; objcopy places it by file offset. */
    .trailer 0x2000000 : AT(0x3495F8)
    {
        build/veldin/asm/veldin/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
