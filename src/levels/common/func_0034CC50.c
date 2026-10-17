#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
extern f32 D_001A4C60[];
extern f32 D_001DD4F8;
extern s32 func_003CCB88(Vec4 *, Vec4 *, s32, u8 *, s32);
s32 func_0034CC50(u8 *a0) {
    Vec4 v;
    f32 y = D_001A4C60[0];
    v.q = ((Vec4 *)(a0 + 16))->q;
    if (y < ((Vec4 *)(a0 + 16))->f[0]) {
        v.f[0] = y - D_001DD4F8;
    } else {
        v.f[0] = y + D_001DD4F8;
    }
    return func_003CCB88(&v, (Vec4 *)(a0 + 16), 2, a0, 0) != 0;
}
