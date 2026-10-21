#include "common.h"

/* localdecomp:start func_003F1D30 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F228;
typedef int Q_37F228 __attribute__((mode(TI)));
extern f32 func_0040BEF8(void *, void *);
extern f32 func_0040BF38(void *);
extern f32 func_0040C3F8(f32);
extern void func_0040CCA0(void *, void *, void *, f32);
extern void func_0040C0F0(s32 a, s32 b, f32 x);
void func_003F1D30(f32 *out, V_37F228 *a, V_37F228 *b, V_37F228 *c, V_37F228 *d4, V_37F228 *n) {
    V_37F228 d, p, e, w, r;
    f32 t, l, ang, h;
    {
        Q_37F228 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
    }
    t = func_0040BEF8(&d, n);
    func_0040C0F0((s32)&p, (s32)n, t);
    {
        Q_37F228 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(x));
    }
    t = func_0040BEF8(c, &e);
    l = func_0040BF38(&e);
    if (l == 0.0f) l = 0.0001f;
    h = 1.5707964f;
    ang = h - func_0040C3F8(t / l);
    func_0040C0F0((s32)&w, (s32)&e, 1.0f);
    if (func_0040BEF8(d4, &w) < 0.0f) ang = -ang;
    out[0] = ang;
    func_0040CCA0(&r, c, n, ang);
    t = func_0040BEF8(&r, &d);
    l = func_0040BF38(&d);
    if (l == 0.0f) l = 0.0001f;
    h = h - func_0040C3F8(t / l);
    func_0040C0F0((s32)&w, (s32)&d, 1.0f);
    ang = -h;
    if (func_0040BEF8(n, &w) < 0.0f) ang = h;
    out[1] = ang;
    out[2] = func_0040BF38(&d);
}
/* localdecomp:end func_003F1D30 */
