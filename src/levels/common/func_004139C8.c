#include "common.h"

typedef int u128_4139C8 __attribute__((mode(TI)));

extern u8 *D_00248680[];
extern u8 *D_001DCD4C;

void func_004139C8(u8 *a0, u128_4139C8 *a1) {
    s32 *p = *(s32 **)(a0 + 104);
    f32 f;
    if (p[1] == -1) {
        *a1 = *(u128_4139C8 *)(D_00248680[0] + p[0] * 128 + 48);
    } else {
        *a1 = *(u128_4139C8 *)(D_001DCD4C + p[1] * 256 + 16);
    }
    f = *(f32 *)(a0 + 24);
    if (((f32 *)a1)[2] < f) {
        ((f32 *)a1)[2] = f;
    }
}
