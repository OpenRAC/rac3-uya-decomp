#include "common.h"

typedef int Q_465740 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_465740;
typedef struct {
    s32 *f0;
    f32 f4;
    f32 f8;
    s32 fC;
    V_465740 v10;
} P_465740;

extern V_465740 D_001E2A40;
extern f32 func_0040BF38(V_465740 *);
extern void func_0040C0F0(V_465740 *, V_465740 *, f32);
extern void func_0040BE90(V_465740 *, V_465740 *, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3E0(f32);
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern s32 func_00444338(s32, f32, s32);

/* localdecomp:start func_00465740 */
void func_00465740(u8 *a)
{
    P_465740 *p;
    V_465740 t;
    Q_465740 x, y, r, y2, x2, r2;
    f32 c;
    f32 f1;
    s32 *q;

    p = (P_465740 *)(a + 0x20);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E2A40));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_465740 *)(a + 0x30)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(r));
    if (func_0040BF38(&t) > 1.0f) {
        func_0040C0F0(&t, &t, 0.25f);
    } else {
        func_0040BE90(&t, &t, 0.25f);
    }
    __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(p->v10));
    __asm__("lqc2 %0, %1" : "=j"(y2) : "m"(t));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r2) : "j"(x2), "j"(y2));
    __asm__("sqc2 %1, %0" : "=m"(*(V_465740 *)(a + 0x10)) : "j"(r2));
    p->f4 = func_0040CEC8(p->f4, p->v10.w);
    c = func_0040C3E0(p->f4);
    q = p->f0;
    if ((func_0040BAC0(a + 0xA) && (c < p->f8 || c < -0.9f)) || *p->f0 == 0) {
        *p->f0 = 0;
        func_0045E580(a);
        return;
    }
    f1 = p->f8;
    if (f1 < c) {
        *(s32 *)(a + 4) = func_00444338(0, (c - f1) / (1.0f - f1), p->fC);
    } else {
        *(s32 *)(a + 4) = 0;
    }
}
/* localdecomp:end func_00465740 */
