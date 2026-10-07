#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0038DF00(s32, s32, f32);
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_0038DF00);

ASM_FUNC("asm/boot_elf/handwritten", func_0038DF48);

LINKER_REMNANT("asm/boot_elf/remnants", func_0038E040);

ASM_FUNC("asm/boot_elf/handwritten", func_0038E048);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038E140);
