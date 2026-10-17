#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern u8 D_001A4D70[];

extern void func_0040C2F8(Vec4 *out, void *a, void *b);
extern f32 func_0040C490(f32 x, f32 y);
extern f32 func_004455F0(f32 *out, void *a, void *b, f32 f0, f32 f1, f32 f2, f32 f3);
extern void func_004EAEC0(f32 a, f32 b, f32 c);

void func_004EAF40(void *arg, f32 a, f32 b, f32 c) {
    Vec4 v;
    f32 out;
    f32 angle;
    u8 *base = D_001A4D70;
    f32 zero = 0.0f;
    func_0040C2F8(&v, base, base - 336);
    angle = func_0040C490(v.f[0], v.f[1]);
    out = zero;
    *(f32 *)(base + 24) = func_004455F0(&out, base + 20, arg, angle, a, b, c);
    func_004EAEC0(zero, zero, out);
}
