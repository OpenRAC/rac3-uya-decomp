#include "common.h"

typedef int u128_361880 __attribute__((mode(TI)));
typedef struct { u8 p0[0x24]; f32 f24; } C_361880;
typedef struct { u128_361880 v0; u8 p10[0x30]; s32 w40; u8 p44[4]; s32 w48; u8 p4C[4]; s32 w50; s32 w54; s32 w58; } V_361880;
typedef struct {
    u8 p0[0x10]; u128_361880 pos; u8 b20; u8 p21[3]; C_361880 *w24; u8 p28[4]; f32 f2C;
    u8 b30; u8 b31; s16 h32; u8 p34[0x34]; V_361880 *w68; u8 p6C[0x84]; f32 fF0; f32 fF4; f32 fF8; s32 wFC;
} M_361880;
extern M_361880 *func_00435E70(s32, s32);
extern f32 func_004408C0(f32, f32);
extern void func_00439610(M_361880 *);
extern M_361880 *D_001E1178;

M_361880 *func_00361880(u128_361880 *a, u128_361880 *b, s32 c, s32 d, s32 e) {
    M_361880 *m;
    V_361880 *v;
    m = func_00435E70(6234, 128);
    if (m != 0) {
        m->b30 = 0xFF;
        m->h32 = 0x1FF;
        m->b31 = 1;
        m->b20 = 0;
        v = m->w68;
        m->pos = *a;
        v->v0 = *b;
        v->w40 = 0;
        m->fF0 = func_004408C0(-3.1415927f, 3.1415927f);
        m->fF4 = func_004408C0(-3.1415927f, 3.1415927f);
        m->fF8 = func_004408C0(-3.1415927f, 3.1415927f);
        m->wFC = 0;
        m->f2C = m->w24->f24 * 1.25f;
        v->w58 = e;
        func_00439610(m);
        D_001E1178 = m;
        v->w48 = 50;
        v->w50 = d;
        v->w54 = c;
    }
    return m;
}
