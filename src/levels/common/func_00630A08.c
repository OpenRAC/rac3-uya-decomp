#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern void func_0058F7B8(Vec4 *out, void *a, void *b);
extern f32 func_0058F980(f32 x, f32 y);
extern f32 func_005B56F8(f32 *out, void *a, void *b, f32 f0, f32 f1, f32 f2, f32 f3);
extern void func_00630988(void *self, f32 a, f32 b, f32 c);

void func_00630A08(u8 *self, void *arg, f32 a, f32 b, f32 c) {
    Vec4 v;
    f32 out;
    f32 angle;
    f32 zero = 0.0f;
    func_0058F7B8(&v, self + 4032, self + 96);
    angle = func_0058F980(v.f[0], v.f[1]);
    out = zero;
    *(f32 *)(self + 4056) = func_005B56F8(&out, self + 4052, arg, angle, a, b, c);
    func_00630988(self, zero, zero, out);
}
