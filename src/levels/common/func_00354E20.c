#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } Vec4;
extern f32 func_00354CC8(u8 *, Vec4 *);
extern s32 func_004054C8(f32, f32, f32);
s32 func_00354E20(u8 *a0, Vec4 *a1) {
    s32 r = 0;
    Vec4 v;
    v = *a1;
    if (func_00354CC8(a0, &v) < 3.0f) {
        r = func_004054C8(*(f32 *)(a0 + 24) + 1.0f, a1->f[2], 1.5f) != 0;
    }
    return r;
}
