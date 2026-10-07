/* boot_elf.elf (see tools/targets.py and docs/boot_elf.md).

   The file is a straight memory image: every section sits at its retail file
   offset (AT(...)), and everything between sections, both .bss regions included,
   is zeros, which objcopy -O binary writes for the gaps. Sections are named
   after splat's segments (boot_elf.splat.yaml). */

INPUT(targets/boot_elf/symbol_addrs_resolved.txt)

SECTIONS
{
    /* ELF header, program headers and .reginfo (file 0x0..0x2000), raw bytes from tools/extract_header.py. */
    .header 0x0 : AT(0x0)
    {
        build/boot_elf/asm/boot_elf/header.s.o(.data);
    }

    /* VU1 microcode (.vutext). Bytes, not MIPS code. */
    .vutext 0x100080 : AT(0x2000)
    {
        build/boot_elf/asm/boot_elf/data/vutext.data.s.o(.data);
    }

    /* core.text: engine core and Sony libraries, src/boot_elf/core/ (tools/build_text.py --unit core). */
    .core_text 0x116F80 : AT(0x18F00)
    {
        build/boot_elf/src/core.c.o(.text);
    }

    .core_data 0x13D480 : AT(0x3F400)
    {
        build/boot_elf/asm/boot_elf/data/core_data.data.s.o(.data);
    }

    /* core.rdata holds each core source file's read-only data, jump tables included, in link order. It is still one blob: a core switch function becoming C first needs this split by file (see tools/targets.py). */
    .core_rdata 0x150080 : AT(0x52000)
    {
        build/boot_elf/asm/boot_elf/data/core_rdata.data.s.o(.data);
    }

    .core_lit 0x1D4D80 : AT(0xD6D00)
    {
        build/boot_elf/asm/boot_elf/data/core_lit.data.s.o(.data);
    }

    /* .lit: the overlay's small data. $gp points into it (same value as frontbin, set by the startup code at 0x13AF38). */
    .lit 0x1D5680 : AT(0xD7600)
    {
        build/boot_elf/asm/boot_elf/data/lit.data.s.o(.data);
    }
    _gp = 0x001DC8B0;

    /* The overlay's .data, split around its jump-table block like frontbin's: every overlay source file's .rodata (the switch tables, INCLUDE_RODATA) sits between the two halves. */
    .data 0x31BE80 : AT(0x21DE00)
    {
        build/boot_elf/asm/boot_elf/data/data_a.data.s.o(.data);
        build/boot_elf/src/text.c.o(.rodata);
        build/boot_elf/asm/boot_elf/data/data_b.data.s.o(.data);
    }

    .lvl_vtbl 0x381000 : AT(0x282F80)
    {
        build/boot_elf/asm/boot_elf/data/lvl_vtbl.data.s.o(.data);
    }

    .lvl_camvtbl 0x381080 : AT(0x283000)
    {
        build/boot_elf/asm/boot_elf/data/lvl_camvtbl.data.s.o(.data);
    }

    .lvl_sndvtbl 0x381100 : AT(0x283080)
    {
        build/boot_elf/asm/boot_elf/data/lvl_sndvtbl.data.s.o(.data);
    }

    /* .text: the front-end overlay, frontbin's code at other addresses. src/boot_elf/text/ (tools/build_text.py --unit text). */
    .text 0x381180 : AT(0x283100)
    {
        build/boot_elf/src/text.c.o(.text);
    }

    .patch_data 0x3F2600 : AT(0x2F4580)
    {
        build/boot_elf/asm/boot_elf/data/patch_data.data.s.o(.data);
    }

    .legal_data 0x1800000 : AT(0x2F5000)
    {
        build/boot_elf/asm/boot_elf/data/legal_data.data.s.o(.data);
    }

    .mc1_data_a 0x1806380 : AT(0x2FB380)
    {
        build/boot_elf/asm/boot_elf/data/mc1_data_a.data.s.o(.data);
    }

    .mc1_data_b 0x1835780 : AT(0x32A780)
    {
        build/boot_elf/asm/boot_elf/data/mc1_data_b.data.s.o(.data);
    }

    /* .shstrtab and the section header table (file 0x35EA98..0x35EE64), raw bytes. Its address is arbitrary; objcopy places it by file offset. */
    .trailer 0x2000000 : AT(0x35EA98)
    {
        build/boot_elf/asm/boot_elf/trailer.s.o(.data);
    }

    /DISCARD/ :
    {
        *(*);
    }
}
