#include "common.h"

typedef struct {
    u8 pad0[28];
    f32 f28;
    u8 pad1[104];
    f32 f136;
    u8 pad2[28];
    s32 i168;
    u8 pad3[4];
    u8 v176[16];
} V_003B9F08;

typedef struct {
    u8 pad0[32];
    u8 state;
    u8 b33;
    u8 pad1[15];
    u8 b49;
    u8 pad2[2];
    u16 h52;
    u8 pad3[50];
    V_003B9F08 *vars;
    u8 pad4[62];
    s16 oclass;
    u8 pad5[84];
} M_003B9F08;

extern M_003B9F08 *D_001E009C;
extern s16 *D_0021DEA0[];
extern s32 D_001E00D8;
extern s32 func_00408B50(void);
extern void func_0040BEC0(f32 *, M_003B9F08 *, f32);
extern s32 func_0040D0C0(f32 *, f32);
extern void func_00408090(M_003B9F08 *, void *, s32, s32, s32, s32, f32, f32, f32);

void func_003B9F08(M_003B9F08 *o) {
    f32 vec[4];
    s32 flag;
    s16 *list;
    M_003B9F08 *m;
    V_003B9F08 *v;

    if (o->b33 == 255) {
        return;
    }
    flag = func_00408B50();
    list = D_0021DEA0[o->b33];
    while (o->b33 != 255 && o->b33 <= D_001E00D8 && list != 0 && (list[-1] >= 0 || list == D_0021DEA0[o->b33])) {
        m = &D_001E009C[*list & 0x7FFF];
        if (m == 0) {
            return;
        }
        v = m->vars;
        if (m->b49 != 0) {
            func_0040BEC0(vec, m, 0.0009765625f);
            vec[3] *= 1.1f;
            if (func_0040D0C0(vec, (f32)v->i168) != -1 && !(m->h52 & 1) && m->oclass == 7303 && m->state == 1) {
                if (flag != 0) {
                    v->f28 -= 0.1f;
                    if (v->f28 <= -8.0f) {
                        v->f28 += 8.0f;
                    }
                }
                func_00408090(m, v->v176, 2, 0x605696FF, 192, 23, v->f136, v->f136 * 7.0f, v->f28);
            }
        }
        list++;
    }
}
