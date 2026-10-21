#include "common.h"

/* localdecomp:start func_0046CF70 */
typedef int Q_0046CF70 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0046CF70;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    s32 wC;
    Q_0046CF70 v10;
    V4_0046CF70 v20;
    Q_0046CF70 v30;
} Node_0046CF70;
extern u8 *D_00221280[];
extern Node_0046CF70 *func_0045E438(s32);
extern void func_0040C0F0(void *, void *, f32);
Node_0046CF70 *func_0046CF70(Q_0046CF70 *a0, Q_0046CF70 *a1, s32 a2, f32 f12) {
    Node_0046CF70 *p;
    f32 *q;
    V4_0046CF70 tmp;
    Q_0046CF70 x, y, r;
    p = func_0045E438(0x5A);
    if (p != 0) {
        q = (f32 *)&p->v30;
        p->w4 = 0x7FFFFFFF;
        p->wC = 0x7FFFFFFF;
        p->b9 = 0x22;
        p->b3 = 0x48;
        p->b1 = 3;
        p->b2 = *D_00221280[0];
        p->v30 = *a1;
        q[3] = f12;
        p->v10 = *a0;
        func_0040C0F0(&tmp, q, 0.9f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_0046CF70 *)a0));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(tmp));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(p->v20) : "j"(r));
        p->hA = a2;
        ((f32 *)&p->v10)[3] = 0.05f;
        ((f32 *)&p->v20)[3] = 2.0f;
        p->b8 = *(u8 *)&p->hA - 15;
    }
    return p;
}
/* localdecomp:end func_0046CF70 */
