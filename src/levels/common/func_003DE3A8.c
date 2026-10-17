#include "common.h"

typedef int u128_3DE3A8 __attribute__((mode(TI)));
typedef struct { u8 p0[0x24]; f32 f24; } C_3DE3A8;
typedef struct { u128_3DE3A8 v0; u128_3DE3A8 v10; s16 h20; u8 p22[6]; s32 w28; } V_3DE3A8;
typedef struct {
    u8 p0[0x10];
    u128_3DE3A8 pos;
    u8 b20; u8 p21[2]; u8 b23;
    C_3DE3A8 *w24;
    u8 p28[4];
    f32 f2C;
    u8 b30; u8 p31;
    s16 h32;
    u16 h34;
    u8 p36[0x32];
    V_3DE3A8 *w68;
    u8 p6C[0x54];
    u128_3DE3A8 rC0;
    u128_3DE3A8 rD0; u8 pE0[0x10];
    f32 fF0, fF4, fF8;
} M_3DE3A8;
extern M_3DE3A8 *func_00435E70(s32, s32);
extern s32 func_00440878(s32, s32);
extern f32 func_00440978(void);
extern f32 func_004408C0(f32, f32);
extern void func_0040C638(void *, void *);
extern void func_004475E8(void *, void *, f32);
extern s32 func_004C4A18(M_3DE3A8 *, s32, f32, f32, f32);
extern void func_00439610(M_3DE3A8 *);
M_3DE3A8 *func_003DE3A8(u128_3DE3A8 *pos, u128_3DE3A8 *vel) {
    M_3DE3A8 *m;
    V_3DE3A8 *p;
    f32 f;
    m = func_00435E70(0x1E05, 0x80);
    if (m != 0) {
        m->b20 = 0;

        m->b30 = m->h32 = 0xFF;
        p = m->w68;
        m->pos = *pos;
        p->v0 = *vel;
        p->h20 = func_00440878(300, 500);
        m->h34 |= 0x100;
        m->fF0 = func_00440978();
        m->fF4 = func_00440978();
        m->fF8 = func_00440978();
        m->b23 = 0x40;
        func_0040C638(&m->rC0, &m->fF0);
        f = func_004408C0(0.043633234f, 0.08726647f);
        func_004475E8(&p->v10, &m->rD0, f);
        f = func_004408C0(0.25f, 0.3f);
        m->f2C = m->w24->f24 * f;
        p->w28 = func_004C4A18(m, 0, 1.0f, 1.0f, 1.0f);
        func_00439610(m);
    }
    return m;
}
