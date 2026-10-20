#include "common.h"

extern u8 D_001E2B20[];
extern f32 D_001DF708[2];
extern s32 D_001D52F4;
extern f32 func_003F13A8(f32 *, f32, f32, f32, f32, f32);
extern void func_0040CCA0(f32 *, f32 *, f32 *, f32);
extern f32 func_0040BEF8(f32 *, f32 *);
extern f32 func_0040BF38(f32 *);
extern void func_0040BF20(f32 *, f32 *, f32 *);
extern void func_0040C0F0(f32 *, f32 *, f32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040CF10(f32, f32);

void func_003E7668(u8 *moby, f32 a, f32 b)
{
    f32 v[4];
    u8 *m;
    u8 *p;
    u8 *q;
    u8 *t;
    f32 *w;
    f32 zero;
    f32 lim;
    f32 ang;
    f32 x;
    f32 f2;

    zero = 0.0f;
    m = *(u8 **)(moby + 112);
    q = m + 480;
    p = m + 384;
    t = D_001E2B20 + *(s32 *)(moby + 148) * 1120;
    x = *(f32 *)(q + 20);
    *(f32 *)(m + 480) = func_003F13A8((f32 *)(m + 484), *(f32 *)(m + 480), a, 2.0f, 4.0f, zero);
    x = x * *(f32 *)(m + 480);
    *(f32 *)(p + 52) = x;
    if (b < -0.3f) {
        b = (b + 0.3f) * 1.4285715f;
    } else if (0.3f < b) {
        b = (b - 0.3f) * 1.4285715f;
    } else {
        b = zero;
    }
    if (b == 0.0f || (f2 = *(f32 *)(q + 8), __builtin_fabsf(b) < __builtin_fabsf(f2) && ((0.0f < b && 0.0f < f2) || (b < 0.0f && f2 < 0.0f)))) {
        lim = 0.01f;
    } else {
        lim = 0.02f;
    }
    *(f32 *)(q + 8) = func_003F13A8((f32 *)(q + 12), *(f32 *)(q + 8), b, 2.0f, 4.0f, lim);
    ang = *(f32 *)(q + 8) * 0.6981317f;
    if (a == 0.0f) {
        func_0040CCA0((f32 *)p, (f32 *)p, (f32 *)(t + 32), *(f32 *)(q + 32));
        w = (f32 *)(t + 32);
    } else {
        w = (f32 *)(t + 32);
        func_0040CCA0((f32 *)p, (f32 *)p, w, *(f32 *)(p + 52));
    }
    b = func_0040BEF8((f32 *)p, w);
    x = func_0040BF38((f32 *)p);
    func_0040BF20(v, w, (f32 *)p);
    func_0040C0F0(v, v, 1.0f);
    x = func_0040C490(x, b);
    if (__builtin_fabsf(x) < __builtin_fabsf(ang) && lim == 0.01f) {
        *(f32 *)(q + 8) = x / 0.6981317f;
    }
    if (x < ang) {
        if (ang < func_0040CEC8(x, D_001DF708[D_001D52F4])) {
            *(f32 *)(p + 56) = func_0040CF10(ang, x);
        } else {
            *(f32 *)(p + 56) = D_001DF708[D_001D52F4];
        }
    } else if (ang < x) {
        if (*(s16 *)(*(u8 **)(moby + 112) + 584) < 0) {
            *(f32 *)(p + 56) = 0.0f;
        } else if (func_0040CEC8(x, -D_001DF708[D_001D52F4]) < ang) {
            *(f32 *)(p + 56) = func_0040CF10(ang, x);
        } else {
            *(f32 *)(p + 56) = -D_001DF708[D_001D52F4];
        }
    } else {
        *(f32 *)(p + 56) = 0.0f;
    }
    if (ang < 0.0f) {
        *(s16 *)(*(u8 **)(moby + 112) + 34) = 1;
    }
    func_0040CCA0((f32 *)p, (f32 *)p, v, *(f32 *)(p + 56));
}
