INPUT(symbol_addrs_resolved.txt)

SECTIONS
{
    __romPos = 0;
    header_ROM_START = __romPos;
    .header 0x0 : AT(header_ROM_START)
    {
        FILL(0x00000000);
        header_DATA_START = .;
        build/asm/header.s.o(.data);
        header_DATA_END = .;
        header_DATA_SIZE = ABSOLUTE(header_DATA_END - header_DATA_START);
    }
    __romPos += SIZEOF(.header);
    header_ROM_END = __romPos;
    header_VRAM = ADDR(.header);
    header_VRAM_END = .;

    lit_ROM_START = __romPos;
    .lit 0x1D5680 : AT(lit_ROM_START)
    {
        FILL(0x00000000);
        lit_DATA_START = .;
        build/asm/data/lit.data.s.o(.data);
        lit_DATA_END = .;
        lit_DATA_SIZE = ABSOLUTE(lit_DATA_END - lit_DATA_START);
    }
    __romPos += SIZEOF(.lit);
    lit_ROM_END = __romPos;
    lit_VRAM = ADDR(.lit);
    lit_VRAM_END = .;
    _gp = lit_ROM_START + 0x7FF0;

    data_ROM_START = __romPos;
    .data 0x317E80 : AT(data_ROM_START)
    {
        FILL(0x00000000);
        data_DATA_START = .;
        build/asm/data/data.data.s.o(.data);
        data_DATA_END = .;
        data_DATA_SIZE = ABSOLUTE(data_DATA_END - data_DATA_START);
    }
    __romPos += SIZEOF(.data);
    data_ROM_END = __romPos;
    data_VRAM = ADDR(.data);
    data_VRAM_END = .;

    lvl_vtbl_ROM_START = __romPos;
    .lvl_vtbl 0x37CF80 : AT(lvl_vtbl_ROM_START)
    {
        FILL(0x00000000);
        lvl_vtbl_DATA_START = .;
        build/asm/data/lvl_vtbl.data.s.o(.data);
        lvl_vtbl_DATA_END = .;
        lvl_vtbl_DATA_SIZE = ABSOLUTE(lvl_vtbl_DATA_END - lvl_vtbl_DATA_START);
    }
    __romPos += SIZEOF(.lvl_vtbl);
    lvl_vtbl_ROM_END = __romPos;
    lvl_vtbl_VRAM = ADDR(.lvl_vtbl);
    lvl_vtbl_VRAM_END = .;

    lvl_camvtbl_ROM_START = __romPos;
    .lvl_camvtbl 0x37D000 : AT(lvl_camvtbl_ROM_START)
    {
        FILL(0x00000000);
        lvl_camvtbl_DATA_START = .;
        build/asm/data/lvl_camvtbl.data.s.o(.data);
        lvl_camvtbl_DATA_END = .;
        lvl_camvtbl_DATA_SIZE = ABSOLUTE(lvl_camvtbl_DATA_END - lvl_camvtbl_DATA_START);
    }
    __romPos += SIZEOF(.lvl_camvtbl);
    lvl_camvtbl_ROM_END = __romPos;
    lvl_camvtbl_VRAM = ADDR(.lvl_camvtbl);
    lvl_camvtbl_VRAM_END = .;

    lvl_sndvtbl_ROM_START = __romPos;
    .lvl_sndvtbl 0x37D080 : AT(lvl_sndvtbl_ROM_START)
    {
        FILL(0x00000000);
        lvl_sndvtbl_DATA_START = .;
        build/asm/data/lvl_sndvtbl.data.s.o(.data);
        lvl_sndvtbl_DATA_END = .;
        lvl_sndvtbl_DATA_SIZE = ABSOLUTE(lvl_sndvtbl_DATA_END - lvl_sndvtbl_DATA_START);
    }
    __romPos += SIZEOF(.lvl_sndvtbl);
    lvl_sndvtbl_ROM_END = __romPos;
    lvl_sndvtbl_VRAM = ADDR(.lvl_sndvtbl);
    lvl_sndvtbl_VRAM_END = .;

    text_ROM_START = __romPos;
    /* No ALIGN(16) inside .text: retail's file ends at 0x218924, which is not
       16-aligned. The padding made build/frontbin.bin 12 bytes too long. */
    .text 0x37D100 : AT(text_ROM_START)
    {
        FILL(0x00000000);
        text_TEXT_START = .;
        build/src/text.c.o(.text);
        text_TEXT_END = .;
        text_TEXT_SIZE = ABSOLUTE(text_TEXT_END - text_TEXT_START);
        text_DATA_START = .;
        build/src/text.c.o(.data);
        text_DATA_END = .;
        text_DATA_SIZE = ABSOLUTE(text_DATA_END - text_DATA_START);
        text_RODATA_START = .;
        build/src/text.c.o(.rodata);
        text_RODATA_END = .;
        text_RODATA_SIZE = ABSOLUTE(text_RODATA_END - text_RODATA_START);
    }
    text_VRAM = ADDR(.text);
    .text_bss . (NOLOAD) :
    {
        FILL(0x00000000);
        text_BSS_START = .;
        build/src/text.c.o(.bss);
        . = ALIGN(16);
        text_BSS_END = .;
        text_BSS_SIZE = ABSOLUTE(text_BSS_END - text_BSS_START);
    }
    text_bss_VRAM = ADDR(.text_bss);
    __romPos += SIZEOF(.text);
    __romPos = (__romPos + 15) & 0xFFFFFFF0;
    . = ALIGN(16);
    text_ROM_END = __romPos;
    text_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
