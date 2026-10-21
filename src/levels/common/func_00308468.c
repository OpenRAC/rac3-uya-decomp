#include "common.h"

typedef int Q_308468 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_308468;
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040C0F0(void *, void *, f32);

/* localdecomp:start func_00308468 */
void func_00308468(u8 *obj, V4_308468 *a, void *out, f32 scale) {
    V4_308468 v[2];
    V4_308468 pad[11];
    V4_308468 d0, e0;
    s32 i = 1;
    f32 ang = 0.0f;
    V4_308468 *p = v;
    Q_308468 x, y, r, r2;

    do {
        i--;
        ang = func_0040CEC8(ang, 0.5711987f);
        p->w = 0;
        p->y = 0;
        p->x = func_0040C3C8(ang) * scale;
        p->z = -func_0040C3E0(ang) * scale;
        func_0040C2D0(p, p, obj + 0xC0);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*p));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*p) : "j"(r));
        p++;
    } while (i >= 0);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v[0]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(d0) : "j"(r));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v[1]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r2) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(e0) : "j"(r2));
    func_0040BF20(out, &d0, &e0);
    func_0040C0F0(out, out, 1.0f);
}
/* localdecomp:end func_00308468 */
