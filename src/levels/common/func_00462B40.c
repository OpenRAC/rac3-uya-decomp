#include "common.h"

/* localdecomp:start func_00462B40 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_462B40;
typedef int Q_462B40 __attribute__((mode(TI)));
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    u8 pad8;
    u8 b9;
    u8 padA[2];
    s32 wC;
    V_462B40 v10;
    V_462B40 v20;
    V_462B40 v30;
} S_462B40;
extern S_462B40 *func_0045E438(s32 a);
extern s32 func_00440848(s32 a);
extern u8 *D_00221164[];
S_462B40 *func_00462B40(V_462B40 *a, V_462B40 *b) {
    S_462B40 *p = func_0045E438(19);
    if (p != 0) {
        s32 v = func_00440848(6) * 6 + 64 | 0x78404000;
        p->b9 = 34;
        p->b3 = 72;
        p->b1 = 3;
        p->w4 = v;
        p->wC = v;
        p->b2 = *D_00221164[0];
        p->v10 = *a;
        p->v30 = *b;
        {
            Q_462B40 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->v30));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(p->v20) : "j"(x));
        }
        {
            Q_462B40 x, y;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->v20));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->v30));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(p->v20) : "j"(x));
        }
        p->v30.w = 6.0f;
        p->v10.w = 0.09f;
        p->v20.w = 0.5f;
    }
    return p;
}
/* localdecomp:end func_00462B40 */
