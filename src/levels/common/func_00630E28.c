#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern f32 func_0058F8B8(f32 x);
extern f32 func_0058F8D0(f32 x);
extern void func_0058F7B8(Vec4 *out, Vec4 *a, void *b);
extern void func_005B2950(Vec4 *out, f32 a, f32 b, f32 c);

void func_00630E28(u8 *self, f32 angle) {
    Vec4 v;
    Vec4 t;
    f32 r;
    f32 sel;
    f32 zero;
    sel = *(f32 *)(self + 184);
    if (angle <= 3.1415927f) {
        sel = angle;
    }
    r = *(f32 *)(self + 4020);
    if (*(u8 *)(self + 6662) != 0) {
        zero = 0.0f;
        t.f[0] = func_0058F8B8(zero) * r;
        t.f[1] = func_0058F8D0(zero) * r;
        t.f[2] = zero;
        func_0058F7B8(&t, &t, self + 32);
        v = t;
    } else {
        func_005B2950(&v, r, sel, *(f32 *)(self + 692));
    }
    *(u128_t *)(self + 288) = v.q;
}
