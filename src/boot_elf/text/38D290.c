#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void func_0038D290(s32 a, s32 b, f32 x);
extern void func_0038D350();
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D290);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D2DC);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D2E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D324);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D328);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D34C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D350);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D37C);

ASM_FUNC("asm/boot_elf/handwritten", func_0038D380);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D3A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0038D3BC);
