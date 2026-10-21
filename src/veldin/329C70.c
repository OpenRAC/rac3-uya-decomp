#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

ASM_FUNC("asm/veldin/handwritten", func_00329C70);

ASM_FUNC("asm/veldin/handwritten", func_00329CC0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_00329D10);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_0032A918);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_0032A968);

LINKER_REMNANT("asm/veldin/remnants", func_0032A988);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_0032A990);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_0032A998);

/* localdecomp:start func_0032AE70 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad0[0x10]; u8 q10[16]; u8 pad20[4]; u8 *p24; u8 pad28[0xc]; u16 h34; u8 pad36[0x62]; s32 f98; u8 pad9c[0x24]; f32 m[12]; } S_A;
extern S_A *D_0023ACF0[];
extern void func_00437600_0032AE70(void *, s32, f32 *);
extern void func_00447748_0032AE70(void *, void *);
extern void func_004397B0(void *);
void func_0032AE70(u8 *a0) {
    f32 v[16];
    s32 i = 0;
    s32 j;
    f32 *q;
    if (D_0023ACF0[0] != 0) {
        do {
            D_0023ACF0[i]->h34 &= 0xffbe;
            D_0023ACF0[i]->h34 |= *(u16 *)(D_0023ACF0[i]->p24 + 0x44) & 0x1000;
            D_0023ACF0[i]->f98 = *(s32 *)(D_0023ACF0[i]->p24 + 0x10);
            *(u128_t *)D_0023ACF0[i]->q10 = *(u128_t *)(a0 + 0x10);
            func_00437600_0032AE70(a0, 0, v);
            for (j = 0, q = v; j < 3; j++) {
                *(f32 *)((u8 *)D_0023ACF0[i] + (j << 4) + 0xc0) = q[0];
                *(f32 *)((u8 *)D_0023ACF0[i] + (j << 4) + 0xc4) = q[1];
                *(f32 *)((u8 *)D_0023ACF0[i] + (j << 4) + 0xc8) = q[2];
                q += 4;
            }
            func_00447748_0032AE70(&D_0023ACF0[i]->m[0], &D_0023ACF0[i]->m[12]);
            func_004397B0(D_0023ACF0[i]);
            D_0023ACF0[i]->f98 = 0;
            i++;
        } while (D_0023ACF0[i] != 0);
    }
}
/* localdecomp:end func_0032AE70 */

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_0032AFB0);

INCLUDE_ASM("asm/veldin/nonmatchings/text", func_0032B848);

