/* i5bootn.elf (see tools/targets.py and docs/i5bootn.md).

   The bootstrap launcher. One PT_LOAD at 0x800000 from file offset 0x1000;
   every section sits at its retail file offset (AT(...)) and the gaps between
   them are zeros, which objcopy -O binary writes. Nothing uses $gp. Sections
   are named after splat's segments (i5bootn.splat.yaml). */

INPUT(targets/i5bootn/symbol_addrs_resolved.txt)

SECTIONS
{
    /* ELF header and program header (file 0x0..0x1000), raw bytes from tools/extract_header.py. */
    .header 0x0 : AT(0x0)
    {
        build/i5bootn/asm/i5bootn/header.s.o(.data);
    }

    /* .text: startup code, the loader and Sony's libkernl. src/i5bootn/ (tools/build_text.py --target i5bootn). */
    .text 0x800000 : AT(0x1000)
    {
        build/i5bootn/src/text.c.o(.text);
    }

    .data 0x805000 : AT(0x6000)
    {
        build/i5bootn/asm/i5bootn/data/data.data.s.o(.data);
    }

    /* .rodata, split around its jump-table block like frontbin's .data: the source files' .rodata (the switch tables, INCLUDE_RODATA) sits between the two halves. The rest is the payload the launcher loads. */
    .rodata 0x805A00 : AT(0x6A00)
    {
        build/i5bootn/asm/i5bootn/data/rodata_a.data.s.o(.data);
        build/i5bootn/src/text.c.o(.rodata);
        build/i5bootn/asm/i5bootn/data/rodata_b.data.s.o(.data);
    }

    /* .reginfo, .shstrtab and the section header table (file 0xC59C4..0xC5B88), raw bytes. Its address is arbitrary; objcopy places it by file offset. */
    .trailer 0x2000000 : AT(0xC59C4)
    {
        build/i5bootn/asm/i5bootn/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
