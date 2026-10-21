#include "common.h"

/* localdecomp:start func_00307FD0 */
typedef int Q_307FD0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_307FD0;
extern void func_0040BE90(void *, void *, f32);
void func_00307FD0(V_307FD0 *out, V_307FD0 *a, V_307FD0 *b, f32 t) {
    V_307FD0 d;
    Q_307FD0 x, y;
    if (t == 0.0f) {
        *(Q_307FD0 *)out = *(Q_307FD0 *)a;
    } else if (t == 1.0f) {
        *(Q_307FD0 *)out = *(Q_307FD0 *)b;
    } else {
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*b));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
        func_0040BE90(&d, &d, t);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
    }
}
/* localdecomp:end func_00307FD0 */
