#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_00332BA8;

extern s32 func_004345D0(void *, s32, s32);
extern u16 *D_0021C260[];
extern u8 *D_001DF71C;
extern u8 *D_001DF800;
extern s32 D_001DF758 __attribute__((section(".sdata")));

void func_00332BA8(u8 *arg0, Vec4_00332BA8 v) {
    u8 *s2;
    u16 *s1;
    s32 idx;
    s32 start;
    u8 *ent;
    u8 *s0;
    u8 *m;

    s2 = *(u8 **)(arg0 + 104);
    *(Vec4_00332BA8 *)(s2 + 960) = v;
    start = *(s32 *)(s2 + 912);
    if (start < 0) {
        return;
    }
    for (s1 = D_0021C260[start];
         (idx = *(s32 *)(s2 + 912), (idx & 0xFF) != 255) && D_001DF758 >= idx && s1 != 0 &&
         ((s16)s1[-1] >= 0 || s1 == D_0021C260[idx]);
         s1++) {
        ent = D_001DF71C + ((*s1 & 0x7FFF) << 8);
        if (ent == 0) {
            return;
        }
        s0 = *(u8 **)(ent + 104);
        if (func_004345D0(s2 + 960, *(s32 *)s0, 0) != 0) {
            if (*(s32 *)(s0 + 8) < 0 || func_004345D0(arg0 + 16, *(s32 *)(s0 + 8), 0) != 0) {
                m = (u8 *)((*(s32 *)(s0 + 4) << 7) + (s32)D_001DF800);
                if (__builtin_fabsf(*(f32 *)(m + 56) - *(f32 *)(arg0 + 24)) < 2.5f) {
                    *(u128_t *)(s2 + 960) = *(u128_t *)(m + 48);
                    return;
                }
            }
        }
    }
}
