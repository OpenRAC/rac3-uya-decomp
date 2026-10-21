#include "common.h"

/* localdecomp:start func_00392838 */
typedef int Q_392838 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_392838;
typedef struct {
    V4_392838 v0;
    V4_392838 v10;
    V4_392838 v20;
    s32 f30;
    s32 f34;
    s32 f38;
    f32 f3C;
    s32 f40;
    s32 f44;
    u8 p48[8];
} P_392838;
typedef struct {
    u8 p0[0x18];
    f32 f18;
} A_392838;
extern P_392838 *D_001E2098;
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern f32 func_00440978(void);
extern void func_00392AB0(void *, s32, s32, f32, f32);
extern f32 func_0040CEC8(f32, f32);
void func_00392838(A_392838 *a, s32 b, f32 c, V4_392838 *d, V4_392838 *e) {
    P_392838 *arr;
    P_392838 *p;
    s32 i, j;
    f32 f;
    V4_392838 t;
    V4_392838 *q10, *q20;
    Q_392838 x, y;
    arr = D_001E2098;
    for (i = 0; i < 1; i++) {
        p = &arr[i];
        q20 = &p->v20;
        q10 = &p->v10;
        if (p->f30 == 0) {
            p->f30 = (s32)a;
            p->f34 = b;
            p->f3C = c;
            p->f38 = 0;
            *(Q_392838 *)&p->v0 = *(Q_392838 *)e;
            *(Q_392838 *)&p->v20 = *(Q_392838 *)d;
            p->v20.z = a->f18;
            func_0040C0F0(&t, e, 2.0f);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->v20));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(t) : "j"(x));
            func_0040BF20(q10, q20, &t);
            f = func_00440978();
            for (j = 0x2F; j >= 0; j--) {
                func_00392AB0(p, 2, 0, f, 0.0f);
                f = func_0040CEC8(f, 0.13368480f);
            }
            p->f40 = 0;
            p->f44 = 0;
            break;
        }
    }
}
/* localdecomp:end func_00392838 */
