#include "common.h"
typedef int u128_003A3948 __attribute__((mode(TI)));
typedef union { u128_003A3948 q; f32 f[4]; } Vec4_003A3948;
extern f32 D_001E9220[];
extern s32 func_003D1188(Vec4_003A3948 *, Vec4_003A3948 *, s32, s32, s32);
f32 func_003A3948(Vec4_003A3948 *a0, s32 a1, s32 a2, f32 h) {
    Vec4_003A3948 c;
    Vec4_003A3948 b;
    f32 r;
    b = *a0;
    c = *a0;
    b.f[2] += h;
    c.f[2] = 0.01f;
    if (func_003D1188(&b, &c, a1, a2, 0) == 0) {
        r = 0.0f;
    } else {
        r = D_001E9220[2];
    }
    return r;
}
