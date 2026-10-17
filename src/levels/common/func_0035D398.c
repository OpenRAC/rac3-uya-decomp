#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
extern s32 D_001EA758[];
extern s32 func_003F1D60(Vec4 *a0, Vec4 *a1, s32 a2, u8 *a3, s32 t0);
void func_0035D398(u8 *a0) {
    Vec4 a;
    Vec4 b;
    u8 *s0;
    a.q = *(u128_t *)(a0 + 16);
    s0 = *(u8 **)(a0 + 104);
    b.q = *(u128_t *)(s0 + 768);
    a.f[2] += *(f32 *)(s0 + 120);
    b.f[2] += *(f32 *)(s0 + 120);
    if (!func_003F1D60(&a, &b, 16, a0, 0) || (D_001EA758[0] != 0 && D_001EA758[0] == *(s32 *)(s0 + 560))) {
        *(u128_t *)(s0 + 784) = *(u128_t *)(s0 + 752) = *(u128_t *)(s0 + 768);
    }
}
