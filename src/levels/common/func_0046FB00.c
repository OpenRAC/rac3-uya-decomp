#include "common.h"

/* localdecomp:start func_0046FB00 */
typedef int Q_46FB00 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_46FB00;
typedef struct {
    u8 pad0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    V4_46FB00 v10;
    struct {
        u8 pad[0x10];
        s32 w10;
        s32 w14;
        s32 w18;
    } q20;
} P_46FB00;
typedef struct {
    u8 pad0[0x10];
    V4_46FB00 v10;
    u8 pad20[0xA0];
    f32 mC0;
} O_46FB00;
extern u8 *D_002212D0[];
extern P_46FB00 *func_0045E438(s32);
extern s32 func_00440848(s32);
extern s32 func_00440878(s32, s32);
extern f32 func_004408C0(f32, f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_004C41E8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
P_46FB00 *func_0046FB00(O_46FB00 *a, V4_46FB00 *b, s32 c, s32 d, s32 e, f32 f) {
    P_46FB00 *p;
    struct { u8 pad[0x10]; s32 w10; s32 w14; s32 w18; } *q;
    V4_46FB00 v;
    Q_46FB00 q1, q2, q3;
    s32 r;
    s32 s;
    p = func_0045E438(0x6E);
    if (p != 0) {
        p->b3 = c;
        p->b1 = 0;
        p->b9 = 0x44;
        q = &p->q20;
        p->b8 = func_00440848(0xFF);
        p->b2 = D_002212D0[0][0];
        r = func_00440878(d, e);
        p->hA = r;
        q->w18 = (s16)r;
        p->fC = f * 3.0f * 210000.0f;
        if (b->w == -1.0f) {
            __asm__("sq $0,%0" : "=m"(v));
            v.w = 1.0f;
            v.x = -0.3f;
            func_0040C2D0(&v, &v, (u8 *)a + 0xC0);
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(v));
            __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(a->v10));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(q3) : "j"(q1), "j"(q2));
            __asm__("sqc2 %1, %0" : "=m"(p->v10) : "j"(q3));
        } else {
            *(Q_46FB00 *)&p->v10 = *(Q_46FB00 *)b;
        }
        p->v10.x += func_004408C0(-0.015f, 0.015f);
        p->v10.y += func_004408C0(-0.015f, 0.015f);
        p->v10.z += func_004408C0(-0.015f, 0.015f);
        func_004C41E8(&a->v10, &v);
        func_0040BE90(q, &v, func_004408C0(0.01f, 0.015f));
        q->w10 = func_00440878(80, 200);
        s = func_00440878(96, 128);
        q->w14 = s + (s << 8) + (s << 16);
        p->w4 = q->w14 | (q->w10 << 24);
    }
    return p;
}
/* localdecomp:end func_0046FB00 */
