#include "common.h"
extern f32 func_0040C490(f32 a, f32 b);
extern f32 func_0040CF10(f32 a, f32 b);
s32 func_004114B0(u8 *a0, f32 s) {
    u8 *p;
    p = *(u8 **)(a0 + 140);
    if (p != 0) {
        return s * func_0040CF10(func_0040C490(*(f32 *)(p + 16) - *(f32 *)(a0 + 48), *(f32 *)(p + 20) - *(f32 *)(a0 + 52)), *(f32 *)(a0 + 64)) > 0.0f;
    }
    return 0;
}
