#include "common.h"

typedef int u128_39FAF0 __attribute__((mode(TI)));
typedef struct { s32 x; s32 y; s32 z; s32 w; } __attribute__((aligned(16))) Q_39FAF0;
typedef struct {
    u8 p0[0x10]; Q_39FAF0 v10; f32 f20; f32 f24; s32 w28; f32 f2C; void *w30; s32 w34; f32 f38; s32 w3C;
    s32 w40; s32 w44; s32 w48; s32 w4C; s32 w50; s32 w54; s32 w58; s32 w5C; f32 f60;
} V_39FAF0;
typedef struct {
    u8 p0[0x10]; u128_39FAF0 pos; u8 b20; u8 p21[0xF]; u8 b30; u8 b31; s16 h32; u8 p34[4]; long d38;
    u8 p40[0x28]; V_39FAF0 *w68;
} M_39FAF0;
extern volatile s32 D_001DE790;
extern M_39FAF0 *func_0040C9B0(s32, s32);
extern void func_00418738(M_39FAF0 *, s32, s32);

M_39FAF0 *func_0039FAF0(M_39FAF0 *parent, Q_39FAF0 *a1, u128_39FAF0 *a2, f32 *a3, s32 t0, s32 t1, s32 t2, s32 t3,
                        s32 s0, f32 f12, f32 f13, f32 f14) {
    M_39FAF0 *m;
    V_39FAF0 *v;
    m = func_0040C9B0(6341, 128);
    if (m != 0) {
        m->b30 = 255;
        m->h32 = 255;
        m->b31 = 1;
        m->b20 = 0;
        v = m->w68;
        m->d38 = parent->d38;
        m->pos = *a2;
        *(volatile Q_39FAF0 *)&v->v10 = *a1;
        v->f20 = a3[0];
        v->f24 = a3[2];
        v->w28 = D_001DE790;
        v->f2C = f12;
        v->w30 = parent;
        v->w34 = -1;
        v->f38 = f13;
        v->w3C = s0;
        v->w40 = 0;
        v->w44 = t0;
        v->w48 = t1;
        v->w4C = t2;
        v->w50 = t3;
        v->w54 = -1;
        v->w58 = 0;
        v->w5C = 0;
        v->f60 = f14;
        func_00418738(m, 0, -1);
    }
    return m;
}
