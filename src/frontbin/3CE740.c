#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
s32 func_003CE740(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/handwritten", func_003CE740);

ASM_FUNC("asm/handwritten", func_003CF790);

ASM_FUNC("asm/handwritten", func_003D00C0);

LINKER_REMNANT("asm/remnants", func_003D00F0);

ASM_FUNC("asm/handwritten", func_003D00F8);
