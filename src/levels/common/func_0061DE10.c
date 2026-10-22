#include "common.h"

/* localdecomp:start func_0061DE10 */
typedef int Q_61DE10 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_61DE10;
extern f32 D_0024130C;
extern void func_0058F358(void *, void *, f32);

void func_0061DE10(V4_61DE10 *out, V4_61DE10 *b, V4_61DE10 *a, s32 *t0, s32 *t1) {
    Q_61DE10 x, y, r;
    f32 s = 1.0f / ((f32)(t1[0] - t0[0]) / (D_0024130C * 1000.0f));

    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(r));
    func_0058F358(out, out, s);
}
/* localdecomp:end func_0061DE10 */
