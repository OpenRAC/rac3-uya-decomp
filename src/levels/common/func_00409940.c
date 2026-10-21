#include "common.h"

/* localdecomp:start func_00409940 */
typedef int Q_409940 __attribute__((mode(TI)));
typedef struct { f32 v[4]; } __attribute__((aligned(16))) V4_409940;
extern void func_0040BE90(void *, void *, f32);
void func_00409940(V4_409940 *p, V4_409940 *q) {
    Q_409940 x, y, r;
    f32 m;
    s32 i;
    f32 *a;
    f32 *b;
    if (q->v[0] > 0.0f && q->v[1] > 0.0f && q->v[2] > 0.0f) {
        return;
    }
    m = 1.0f;
    b = p->v;
    a = q->v;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*q));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*p));
    for (i = 2; i >= 0; i--, b++, a++) {
        f32 f = *a;
        if (f <= 0.0f) {
            f32 t = 1.0f - f / (f - *b);
            if (t < m) {
                m = t;
            }
        }
    }
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(*q) : "j"(r));
    func_0040BE90(q, q, m - 0.01f);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*p));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*q));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*q) : "j"(x));
}
/* localdecomp:end func_00409940 */
