#include "common.h"

/* localdecomp:start func_003662F8 */
typedef int Q_3662F8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3662F8;
extern s32 func_00366290(void *, f32 *);
extern void func_004434F8(void *, void *, void *, void *);
extern f32 func_0040C018(void *, void *);
extern f32 func_0040C3F8(f32);
extern f32 func_0040C3C8(f32);
extern void func_0040C0F0(void *, void *, f32);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
s32 func_003662F8(V4_3662F8 *a, V4_3662F8 *b, V4_3662F8 *c, V4_3662F8 *d) {
    V4_3662F8 t0, v, w;
    f32 q;
    f32 d0, r, fa, fb, fc;
    s32 res;
    Q_3662F8 x, y;
    if (!func_00366290(&t0, &q)) {
        return 0;
    }
    q = q + -0.07f;
    func_004434F8(&w, a, b, &t0);
    d0 = func_0040C018(&w, &t0);
    if (q < d0) {
        return 0;
    }
    res = 0;
    r = func_0040C3C8(func_0040C3F8(d0 / q)) * q;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(v) : "j"(x));
    func_0040C0F0(&v, &v, 1.0f);
    fa = func_0040BEF8(&v, a);
    fc = func_0040BEF8(&v, b);
    fb = func_0040BEF8(&v, &w);
    if (fa < fb - r) {
        func_0040BE90(c, &v, -r);
        res = 1;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*c));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(w));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*c) : "j"(x));
    }
    if (1) {
        if (fb + r < fc) {
            func_0040BE90(d, &v, r);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*d));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(w));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(x));
            if ((res ^ 1) & 1) {
                *c = *d;
            }
            res |= 2;
        }
    }
    return res;
}
/* localdecomp:end func_003662F8 */
