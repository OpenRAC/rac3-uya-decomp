#include "common.h"

extern u8 D_001A4C60[];
extern s32 func_00423AD0(u8 *a0, s32 a1, s32 a2);
extern f32 func_003F0BB8(u8 *a0, u8 *a1);

s32 func_00350698(u8 *a0, u8 *a1) {
    s32 r;

    r = 0;
    if (func_00423AD0(D_001A4C60, *(s32 *)(a1 + 612), 0) != 0 ||
        func_003F0BB8(a0 + 16, a1 + 544) < *(f32 *)(a1 + 616)) {
        r = 1;
    }
    return r;
}
