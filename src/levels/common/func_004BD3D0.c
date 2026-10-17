#include "common.h"

extern s32 func_004BD328(s32, s32);
extern u8 D_001426E0[];

s32 func_004BD3D0(s32 a, s32 bit) {
    s32 i = func_004BD328(a, bit);
    if (i >= 0) {
        D_001426E0[i] &= 1 << bit;
        return D_001426E0[i] != 0;
    }
    return 0;
}
