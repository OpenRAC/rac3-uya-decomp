#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

typedef struct {
    u8 m0[64];
    u8 m40[9716 - 64];
    u8 mode;
} S_50D870;

extern S_50D870 D_001A4BE0;
extern void func_0040C2F8(Vec4 *, Vec4 *, void *);
extern f32 func_0040BF68(Vec4 *);
extern f32 func_0040C490(f32, f32);

f32 func_0050D870(Vec4 *in)
{
    S_50D870 *s = &D_001A4BE0;
    s32 m = s->mode;
    Vec4 v;

    if (m == 0) {
        return func_0040C490(in->f[2], func_0040BF68(in));
    }
    if (m < 0) {
        return 0.0f;
    }
    if (m >= 3) {
        return 0.0f;
    }
    v.q = in->q;
    func_0040C2F8(&v, &v, s->m40);
    return func_0040C490(v.f[2], func_0040BF68(&v));
}
