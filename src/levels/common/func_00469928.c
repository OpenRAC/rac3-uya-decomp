#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_469928;
typedef int Q_469928 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
    f32 r, g, b, a;
} S2_469928;
typedef struct {
    s32 f0;
    s32 f4;
    u8 f8;
    u8 f9;
    u8 fA;
    u8 fB;
    f32 fC;
    V_469928 pos;
    S2_469928 v;
} S_469928;

extern Q_469928 D_001EAAA0;
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern s32 func_00445B88(f32, f32, f32, f32);

/* localdecomp:start func_00469928 */
void func_00469928(S_469928 *p) {
    S2_469928 *q;
    Q_469928 tmp;

    if (p == 0) return;
    q = &p->v;
    q->a += 0.0f;
    p->fC += -100.0f;
    {
        Q_469928 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->v));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(tmp) : "j"(x));
    }
    if (p->v.x != 0.0f || q->y != 0.0f || q->z != 0.0f) {
        if (func_003F8448(&p->pos, &tmp, 2, p, 0)) {
            *(Q_469928 *)&p->pos = D_001EAAA0;
            __asm__("sq $0, %0" : "=m"(*(Q_469928 *)q));
            p->fC = p->fC + p->fC;
        } else {
            *(Q_469928 *)&p->pos = tmp;
            if (q->w != 0.0f) q->z = q->z + q->w;
            else q->z = q->z + -0.0063f;
        }
    }
    if (q->a <= 0.0f || func_0040BAC0(&p->fA) != 0 || p->fC < 0.0f ||
        ((f32 *)&tmp)[0] < 0.01f || ((f32 *)&tmp)[1] < 0.01f || ((f32 *)&tmp)[2] < 0.01f) {
        func_0045E580(p);
        return;
    }
    q->r += -0.01f;
    if (q->r < 0.0f) q->r = 0.0f;
    q->g += -0.03001f;
    if (q->g < 0.0f) q->g = 0.0f;
    q->b += -0.05f;
    if (q->b < 0.0f) q->b = 0.0f;
    q->a += 0.0f;
    if (q->a < 0.0f) q->a = 0.0f;
    p->f4 = func_00445B88(q->r, q->g, q->b, q->a);
    p->f8--;
}
/* localdecomp:end func_00469928 */
