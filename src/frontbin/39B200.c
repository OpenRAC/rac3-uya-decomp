#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
void func_0039B760(u8 *, u32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/handwritten", func_0039B200);

ASM_FUNC("asm/handwritten", func_0039B240);

/* 0x39B2DC is 4 bytes past an 8-byte boundary: GCC pads every C function to 8,
   so this can't be a C function (it's likely leftover bytes after the previous one). */
ASM_FUNC("asm/handwritten", func_0039B2DC);  /* 4-byte aligned: cannot be a compiled C function (gcc aligns to 8) */

ASM_FUNC("asm/handwritten", func_0039B2E8);

ASM_FUNC("asm/handwritten", func_0039B4E8);

ASM_FUNC("asm/handwritten", func_0039B628);

ASM_FUNC("asm/handwritten", func_0039B760);

ASM_FUNC("asm/handwritten", func_0039BA30);

ASM_FUNC("asm/handwritten", func_0039BA50);

ASM_FUNC("asm/handwritten", func_0039BBC8);
