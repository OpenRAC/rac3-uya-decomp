#include "common.h"

/* localdecomp:start func_00442300 */
typedef int Q_442300 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_442300;
extern f32 func_0040C3C8(f32);
extern void func_0040BE90(void *, void *, f32);
void func_00442300(V_442300 *out, V_442300 *a, V_442300 *b, f32 t) {
    V_442300 d;
    Q_442300 x, y;
    if (t == 0.0f) {
        *(Q_442300 *)out = *(Q_442300 *)a;
    } else if (t == 1.0f) {
        *(Q_442300 *)out = *(Q_442300 *)b;
    } else {
        f32 s = 1.0f - func_0040C3C8(t * 3.1415927f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(y));
        func_0040BE90(&d, &d, s * 0.5f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
    }
}
/* localdecomp:end func_00442300 */
