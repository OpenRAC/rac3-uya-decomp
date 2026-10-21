#include "common.h"

/* localdecomp:start func_00447650 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_447650;
typedef int Q_447650 __attribute__((mode(TI)));
extern void func_0040BE90(void *a, void *b, f32 c);
void func_00447650(V_447650 *src, V_447650 *dst) {
    V_447650 q, r;
    V_447650 *qv = &q;
    V_447650 *rv = &r;
    f32 *qp = &q.x;
    f32 *rp = (f32 *)rv;
    f32 *dp = (f32 *)dst;
    s32 i;
    *(Q_447650 *)qv = *(Q_447650 *)src;
    for (i = 2; i >= 0; i--) {
        f32 f = *dp;
        if (f < 0.0f) {
            f32 t, u;
            {
                Q_447650 x, y;
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*qv));
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*dst));
                __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(r) : "j"(x));
            }
            t = (*qp - 0.1f) / *rp;
            __asm__("abs.s %0, %1" : "=f"(u) : "f"(t));
            func_0040BE90(rv, rv, u);
            {
                Q_447650 x, y;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*qv));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(r));
                __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(*dst) : "j"(x));
            }
        }
        dp++;
        rp++;
        qp++;
    }
}
/* localdecomp:end func_00447650 */
