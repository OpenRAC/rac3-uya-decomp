#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9AC0[2])(s32);
extern void (*D_00226880[])(s32);
extern void (*D_00226C80[])(s32);
extern void (*D_00226E80[])(s32);
extern void (*D_00226A80[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AAB70 */
extern s32 func_003F2578();
extern u8 D_001D8190[];
void func_003AAB70(u8 *p, s32 f) {
    *(void **)(p + 4) = D_001D8190;
    if (f & 1) func_003F2578(p);
}
/* localdecomp:end func_003AAB70 */

extern void func_00116F98(s32 *a0, s32 a1, s32 *a2);

/* localdecomp:start func_003AABA0 */
extern char D_001D80B0[];
extern char D_001D80C8[];
extern void func_116F98(char *, s32, char *);
void func_003AABA0(void *unused, f32 *out, f32 t) {
    if (!out) func_116F98(D_001D80B0, 0x3D, D_001D80C8);
    out[0] = t;
    out[1] = t * 0.5f;
    out[2] = 1.0f - t;
    out[3] = (1.0f - t) * 0.5f;
}
/* localdecomp:end func_003AABA0 */

extern char D_001D8160[];
extern void func_003AAB70();

LINKER_REMNANT("asm/boot_elf/remnants", func_003AAC18);
