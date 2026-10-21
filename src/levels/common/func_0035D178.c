#include "common.h"

/* localdecomp:start func_0035D178 */
typedef int u128_35D178 __attribute__((mode(TI)));
typedef struct { u8 p0[0x24]; f32 f24; } C_35D178;
typedef struct { u128_35D178 v0; u8 p10[0x10]; s32 w20; s32 w24; s32 w28; s32 w2C; s32 w30; } V_35D178;
typedef struct {
    u8 p0[0x10]; u128_35D178 pos; u8 b20; u8 p21[3]; C_35D178 *w24; u8 p28[4]; f32 f2C;
    u8 b30; u8 b31; s16 h32; u8 p34[0x34]; V_35D178 *w68; u8 p6C[0x84]; f32 fF0; f32 fF4; f32 fF8; s32 wFC;
} M_35D178;
extern M_35D178 *func_00435E70(s32, s32);
extern f32 func_004408C0(f32, f32);
extern void func_00439610(M_35D178 *);
extern s32 func_004C4A18(M_35D178 *, s32, f32, f32, f32);
extern void func_0035D848(M_35D178 *);

M_35D178 *func_0035D178(u128_35D178 *a, u128_35D178 *b) {
    M_35D178 *m;
    V_35D178 *v;
    m = func_00435E70(6227, 128);
    if (m != 0) {
        m->b30 = 0xFF;
        m->h32 = 0x1FF;
        m->b31 = 1;
        m->b20 = 0;
        v = m->w68;
        m->pos = *a;
        v->v0 = *b;
        v->w24 = 0;
        v->w20 = 30;
        v->w28 = 300;
        m->fF0 = func_004408C0(-3.1415927f, 3.1415927f);
        m->fF4 = func_004408C0(-3.1415927f, 3.1415927f);
        m->fF8 = func_004408C0(-3.1415927f, 3.1415927f);
        m->wFC = 0;
        m->f2C = m->w24->f24 * 1.2f;
        func_00439610(m);
        v->w2C = func_004C4A18(m, 0, 1.0f, 1.0f, 1.0f);
        v->w30 = 70;
        func_0035D848(m);
    }
    return m;
}
/* localdecomp:end func_0035D178 */
