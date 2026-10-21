#include "common.h"

/* localdecomp:start func_00445208 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_445208;
typedef int Q_445208 __attribute__((mode(TI)));
extern f32 func_0040BF38(void *);
extern void func_00445010(f32 *a, f32 b, f32 c, f32 d, f32 e);
extern void func_0040C0F0(s32 a, s32 b, f32 x);
f32 func_00445208(V_445208 *pos, V_445208 *tgt, f32 *vel, f32 a, f32 b, f32 c) {
    V_445208 d;
    f32 l, diff, t;
    {
        Q_445208 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*tgt));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
    }
    l = func_0040BF38(&d);
    func_00445010(vel, l, a, b, c);
    func_0040C0F0((s32)&d, (s32)&d, *vel);
    {
        Q_445208 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*pos) : "j"(x));
    }
    diff = l - *vel;
    __asm__("abs.s %0, %1" : "=f"(t) : "f"(diff));
    if (t < c * 0.01f) {
        *(Q_445208 *)pos = *(Q_445208 *)tgt;
        *vel = 0.0f;
        return *vel;
    }
    return diff;
}
/* localdecomp:end func_00445208 */
