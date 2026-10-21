#include "common.h"

/* localdecomp:start func_004622D0 */
typedef int Q_4622D0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4622D0;
typedef struct {
    f32 v0[2];
    f32 f8;
    f32 fC;
    s32 x10;
    s32 x14;
    s16 h18;
    s16 h1A;
    f32 f1C;
} Q2_4622D0;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 x4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    f32 v10[3];
    f32 f1C;
    Q2_4622D0 q;
} P_4622D0;
extern s32 D_001D673C[];
extern s32 D_001DFBC0;
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern s32 func_00444338(f32, s32, s32);
extern void func_0044DF40(void *, void *, s32);
extern void func_0040BE90(void *, void *, f32);
extern void func_004C6EC8(void *, void *);
extern f32 func_004408C0(f32, f32);
extern f32 func_0040BF38(void *);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_00440878(s32, s32);
extern void func_00462190(void *, void *, s32, s32, f32, s32, s32, s32, s32, s32);
void func_004622D0(P_4622D0 *p) {
    Q2_4622D0 *q = &p->q;
    V_4622D0 *pos;
    V_4622D0 old, d, dir, rnd;
    f32 t;
    f32 h;
    if (func_0040BAC0(&p->hA)) {
        func_0045E580(p);
        return;
    }
    pos = (V_4622D0 *)p->v10;
    h = p->hA;
    p->fC = h * q->f1C / q->h18;
    p->x4 = func_00444338(h / q->h18, q->x14, q->x10);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(((V_4622D0 *)p)[1]) : "m"(((V_4622D0 *)p)[1]), "m"(((V_4622D0 *)p)[2]));
    if (D_001D673C[0] != 0) {
        func_0044DF40(pos, &d, 0);
        func_0040BE90(&d, &d, q->fC);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(((V_4622D0 *)p)[2]) : "m"(((V_4622D0 *)p)[2]), "m"(d));
    } else {
        q->f8 -= q->fC;
    }
    old = ((V_4622D0 *)p)[1];
    if (p->f1C != 0.0f) {
        if (p->f1C == 2.0f) func_004C6EC8(pos, pos);
        p->f1C = 2.0f;
    }
    if (q->h1A != 0 && (D_001DFBC0 & 1)) {
        Q_4622D0 x, y;
        *(Q_4622D0 *)&rnd = 0;
        rnd.x = func_004408C0(-1.0f, 1.0f);
        rnd.y = func_004408C0(-1.0f, 1.0f);
        rnd.z = func_004408C0(-1.0f, 1.0f);
        dir = rnd;
        t = func_0040BF38(q);
        func_0040C0F0(&dir, &dir, t * func_004408C0(0.15f, 0.25f));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(dir));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*q));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(x));
        func_0040BE90(&dir, &dir, func_004408C0(0.75f, 0.95f));
        func_00462190(pos, &dir, p->x4, q->x14, p->fC, func_00440878(15, 30), 0, p->b2, p->b3, (s32)p->f1C);
    } else {
        func_0040BE90(q, q, 0.96f);
    }
}
/* localdecomp:end func_004622D0 */
