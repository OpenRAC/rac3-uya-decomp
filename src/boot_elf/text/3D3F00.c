#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern s32 func_003D3F00();
extern s32 func_003D5880(void);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
s32 func_003D3F00(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);
extern s32 func_003D4F50(void *, s32, void *, s32, f32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_003D3F00);

ASM_FUNC("asm/boot_elf/handwritten", func_003D4F50);

ASM_FUNC("asm/boot_elf/handwritten", func_003D5880);

LINKER_REMNANT("asm/boot_elf/remnants", func_003D58B0);

ASM_FUNC("asm/boot_elf/handwritten", func_003D58B8);
