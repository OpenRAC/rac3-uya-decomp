#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A0A20(u8 *, u32);
extern void func_003A05A8();
extern void func_003A0518(void);
void func_003A0A20(u8 *, u32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_003A0440);

ASM_FUNC("asm/boot_elf/handwritten", func_003A0480);

ASM_FUNC("asm/boot_elf/handwritten", func_003A0518);

/* 0x39B2DC is 4 bytes past an 8-byte boundary: GCC pads every C function to 8,
   so this can't be a C function (it's likely leftover bytes after the previous one). */

ASM_FUNC("asm/boot_elf/handwritten", func_003A059C);

ASM_FUNC("asm/boot_elf/handwritten", func_003A05A8);

ASM_FUNC("asm/boot_elf/handwritten", func_003A07A8);

ASM_FUNC("asm/boot_elf/handwritten", func_003A08E8);

ASM_FUNC("asm/boot_elf/handwritten", func_003A0A20);

ASM_FUNC("asm/boot_elf/handwritten", func_003A0CF0);

ASM_FUNC("asm/boot_elf/handwritten", func_003A0D10);

ASM_FUNC("asm/boot_elf/handwritten", func_003A0E88);
