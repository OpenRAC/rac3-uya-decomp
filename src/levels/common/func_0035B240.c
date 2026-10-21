#include "common.h"

/* localdecomp:start func_0035B240 */
typedef int u128_35B240 __attribute__((mode(TI)));
typedef struct {
    u128_35B240 v0;
    f32 f10;
    s32 w14;
    s32 w18;
    f32 f1C;
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
} V_35B240;
typedef struct {
    u8 p0[0x10]; u128_35B240 pos; u8 b20; u8 p21[0xF];
    u8 b30; u8 p31; s16 h32; u16 h34; u8 p36[0x32]; V_35B240 *w68; u8 p6C[0x2C]; s32 w98;
} M_35B240;
extern M_35B240 *func_00435E70(s32, s32);
extern f32 func_00440978(void);
extern f32 func_0040BF38(V_35B240 *);
extern void func_004C7010(V_35B240 *, u128_35B240 *, f32, f32, f32);
extern s32 func_004C4A18(M_35B240 *, s32, f32, f32, f32);
extern void func_004A6DF8(M_35B240 *, s32);
extern s32 D_001A6290[];

M_35B240 *func_0035B240(s32 a0, u128_35B240 *a1, u128_35B240 *a2, f32 f12, s32 a3, f32 f13, s32 t0) {
    M_35B240 *m;
    V_35B240 *p;
    u128_35B240 t;
    m = func_00435E70(6225, 128);
    if (m != 0) {
        m->b20 = 0;
        m->b30 = m->h32 = 0xFF;
        p = m->w68;
        m->pos = *a1;
        t = *a2;
        p->w20 = a3;
        p->w18 = a0;
        p->v0 = t;
        p->f10 = func_00440978();
        p->f1C = f12;
        p->w24 = t0;
        p->w14 = 0;
        p->w28 = 0;
        if (D_001A6290[0] != 0) {
            func_004C7010(p, a1, func_0040BF38(p), 35.0f, 1.3962634f);
        }
        p->w2C = func_004C4A18(m, 0, f13, 1.0f, 1.0f);
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        func_004A6DF8(m, 1);
    }
    return m;
}
/* localdecomp:end func_0035B240 */
