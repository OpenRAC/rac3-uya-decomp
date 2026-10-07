#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003894A0(s32, s32, f32);
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/handwritten", func_003894A0);

ASM_FUNC("asm/handwritten", func_003894E8);

LINKER_REMNANT("asm/remnants", func_003895E0);

ASM_FUNC("asm/handwritten", func_003895E8);
