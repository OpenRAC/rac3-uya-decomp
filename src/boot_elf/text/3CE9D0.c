#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
typedef struct { u8 pad[0x10]; u8 *base; s16 h14; s16 h16; s16 h18; s16 h1A; s16 h1C; s16 h1E; } E_3C9078;
extern void func_003CEF58(E_3C9078 *, s32, u8 *);
extern void func_003CE9D0(void);
extern s32 func_003CEA78(u8 *, u8 *, s32);
extern void func_003CEB70(s32, u8 *, u8 *, u8 *);
/* --- end of declarations from other files --- */

ASM_FUNC("asm/boot_elf/handwritten", func_003CE9D0);

ASM_FUNC("asm/boot_elf/handwritten", func_003CEA78);

ASM_FUNC("asm/boot_elf/handwritten", func_003CEB70);

ASM_FUNC("asm/boot_elf/handwritten", func_003CEC70);

ASM_FUNC("asm/boot_elf/handwritten", func_003CEF58);
