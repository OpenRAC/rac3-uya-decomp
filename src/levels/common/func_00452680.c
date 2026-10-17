#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
extern f32 D_001E9620[];
extern s32 func_00409388(Vec4 *a0, Vec4 *a1, s32 a2, s32 a3, s32 t0);
f32 func_00452680(u128_t *pos) {
    Vec4 a;
    Vec4 b;
    b.q = *pos; a.q = *pos; b.f[2] += 64.01f; a.f[2] -= 0.5f;
    if (func_00409388(&b, &a, 18, 0, 0) != 0) {
        return D_001E9620[2];
    }
    return b.f[2];
}
