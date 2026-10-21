#include "common.h"

/* localdecomp:start func_004D6400 */
extern void *func_0045E438(s32);
extern s32 func_00440848(s32);
extern s32 func_00440848();
extern void func_0040C2D0(void *, void *, void *);

typedef int Q_3BA5B8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x10]; Q_3BA5B8 q10; u8 pad20[0x12]; s16 h32; } B_3BA5B8;
typedef struct {
    B_3BA5B8 *b;
    s32 w4;
    f32 f8;
    u8 bC, bD, bE, bF;
    union { Q_3BA5B8 q; f32 f[4]; } q10;
} Sub_3BA5B8;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u16 hA;
    f32 fC;
    Q_3BA5B8 q10;
    Sub_3BA5B8 s20;
} S_3BA5B8;
extern void *func_0045E438(s32);
extern s32 func_00440848();
extern u8 *D_0022127C[];
extern void func_0040C2D0(void *, void *, void *);
S_3BA5B8 *func_004D6400(Q_3BA5B8 *pos, B_3BA5B8 *b, s32 a2, f32 f0, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f1, f32 f2, u8 a8, s32 a9) {
    S_3BA5B8 *p = func_0045E438(0x59);
    Sub_3BA5B8 *s;
    Q_3BA5B8 t;
    s32 v;
    if (p) {
        p->w4 = a2;
        p->fC = f0;
        p->b1 = 0;
        p->b9 = 0x44;
        p->b3 = 0x48;
        p->b8 = func_00440848(0xFF);
        p->b2 = D_0022127C[0][a4];
        p->hA = a5;
        s = &p->s20;
        s->b = b;
        s->w4 = a3;
        s->f8 = f1;
        s->bC = a6;
        s->bD = a8;
        s->q10.q = *pos;
        s->q10.f[3] = f2;
        if (a4 == 0) s->bE = 1;
        s->bF = a9;
        if (b) {
            p->q10 = b->q10;
            func_0040C2D0(&t, &s->q10.q, (u8 *)b + 0xC0);
            __asm__ __volatile__(
                "lqc2 $vf1, %0\n"
                "lqc2 $vf2, %1\n"
                "vadd.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, %0\n"
                : "+m"(p->q10) : "m"(t));
            if (a7 > 0) v = a7 >> 5;
            else v = b->h32 >> 5;
            p->b9 = v * 16 + 4;
        } else {
            p->q10 = *pos;
        }
    }
    return p;
}
/* localdecomp:end func_004D6400 */
