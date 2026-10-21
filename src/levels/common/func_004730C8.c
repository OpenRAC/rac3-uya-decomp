#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4730C8;
typedef int Q_4730C8 __attribute__((mode(TI)));

extern f32 func_00472EF8(V_4730C8 *, V_4730C8 *, V_4730C8 *, V_4730C8 *, f32);
extern f32 func_0040BFE8(void *, void *);
extern f32 func_0040BFB0(void *, void *);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_00444F70(void *, void *, void *, f32);
extern f32 func_00472E88(void *, void *, f32);

/* localdecomp:start func_004730C8 */
f32 func_004730C8(V_4730C8 *out, V_4730C8 *pt, V_4730C8 *a, V_4730C8 *b, f32 r) {
    V_4730C8 d, e, f, g, h;
    f32 t, s, u, x;
    f32 *po, *pa, *pb;
    s32 i;

    if (0.0f < r && fabsf(pt->z - a->z) < r && fabsf(pt->z - b->z) < r) {
        t = func_00472EF8(out, pt, a, b, r);
        s = func_0040BFE8(a, out);
        s = s / func_0040BFE8(a, b);
        *(Q_4730C8 *)&d = *(Q_4730C8 *)a;
        *(Q_4730C8 *)&e = *(Q_4730C8 *)b;
        func_00444F70(out, &d, &e, s);
        return t;
    }
    {
        Q_4730C8 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*b));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
    }
    *(Q_4730C8 *)&e = *(Q_4730C8 *)a;
    func_0040C0F0(&d, &d, 1.0f);
    *(Q_4730C8 *)&f = *(Q_4730C8 *)&d;
    u = -func_0040BEF8(pt, &d);
    func_0040BE90(out, &d, -(u + func_0040BEF8(&e, &f)) / func_0040BEF8(&d, &f));
    {
        Q_4730C8 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*out));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(e));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
    }
    i = 0;
    pb = &b->x;
    pa = &a->x;
    po = &out->x;
    do {
        x = *po;
        if (*pa < x && *pb < x) break;
        if (x < *pa && x < *pb) break;
        i++;
        pb++;
        pa++;
        po++;
    } while (i < 3);
    if (i < 3) {
        if (func_0040BFB0(out, a) < func_0040BFB0(out, b)) *(Q_4730C8 *)out = *(Q_4730C8 *)a;
        else *(Q_4730C8 *)out = *(Q_4730C8 *)b;
    }
    *(Q_4730C8 *)&g = *(Q_4730C8 *)pt;
    *(Q_4730C8 *)&h = *(Q_4730C8 *)out;
    return func_00472E88(&g, &h, 0.0f);
}
/* localdecomp:end func_004730C8 */
