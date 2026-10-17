#include "common.h"

typedef int u128_348B08 __attribute__((mode(TI)));
typedef struct { u128_348B08 v0; u128_348B08 v10; u8 p20[0xC]; s32 w2C; f32 f30; s32 w34; s32 w38; s32 w3C; } V_348B08;
typedef struct {
    u8 p0[0x10]; u128_348B08 pos; u8 b20; u8 p21[0x47]; V_348B08 *w68;
} M_348B08;
extern s32 D_001DF3C0;
extern void func_00418738(M_348B08 *, s32, s32);

void func_00348B08(M_348B08 *m) {
    V_348B08 *v;
    s32 t;
    v = m->w68;
    t = (D_001DF3C0 + v->w34) % ((v->w38 + v->w3C) * 2);
    if (t < v->w38) {
        v->w2C = 0;
        v->f30 = (f32)t / (f32)v->w38;
        if (m->b20 != 1) func_00418738(m, 1, -1);
    } else {
        t -= v->w38;
        if (t < v->w3C) {
            v->w2C = 0;
            v->f30 = 1.0f;
            if (m->b20 != 2) {
                m->pos = v->v0;
                func_00418738(m, 2, -1);
            }
        } else {
            t -= v->w3C;
            if (t < v->w38) {
                v->w2C = 1;
                v->f30 = (f32)t / (f32)v->w38;
                if (m->b20 != 1) func_00418738(m, 1, -1);
            } else {
                v->f30 = 0.0f;
                v->w2C = 1;
                if (m->b20 != 2) {
                    m->pos = v->v10;
                    func_00418738(m, 2, -1);
                }
            }
        }
    }
}
