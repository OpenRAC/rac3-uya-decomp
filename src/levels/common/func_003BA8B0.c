#include "common.h"

typedef struct {
    u8 pad0[28];
    f32 phase;
    u8 pad20[136 - 32];
    f32 size;
    u8 pad8C[168 - 140];
    s32 range;
    u8 padAC[4];
    u8 trail0[32];
    u8 trail1[32];
} Vars_003BA8B0;

typedef struct {
    u8 pad0[32];
    u8 state;
    u8 group;
    u8 pad22[49 - 34];
    u8 visible;
    u8 pad32[2];
    u16 flags;
    u8 pad36[104 - 54];
    Vars_003BA8B0 *vars;
    u8 pad6C[170 - 108];
    s16 oclass;
    u8 padAC[84];
} Moby_003BA8B0;

extern u16 *D_0021DEA0[];
extern Moby_003BA8B0 *D_001E009C;
extern s32 D_001E00D8 __attribute__((section(".sdata")));

extern void func_0040BEC0(f32 *, Moby_003BA8B0 *, f32);
extern s32 func_0040D0C0(f32 *, f32);
extern void func_00408090(Moby_003BA8B0 *, void *, s32, u32, u32, s32, f32, f32, f32);

void func_003BA8B0(Moby_003BA8B0 *self) {
    f32 sphere[4];
    u16 *p;
    Moby_003BA8B0 *m;
    Vars_003BA8B0 *v;
    f32 a;
    f32 b;

    if (self->group != 255) {
        p = D_0021DEA0[self->group];
        while (self->group != 255 && self->group <= D_001E00D8 && p != 0 &&
               (((s16 *)p)[-1] >= 0 || p == D_0021DEA0[self->group])) {
            m = &D_001E009C[*p & 0x7FFF];
            if (m == 0) break;
            v = m->vars;
            if (m->visible != 0) {
                func_0040BEC0(sphere, m, 0.0009765625f);
                sphere[3] *= 1.1f;
                if (func_0040D0C0(sphere, (f32)v->range) != -1 && !(m->flags & 1) &&
                    m->oclass == 4752 && m->state == 1) {
                    v->phase -= 0.1f;
                    if (v->phase <= -8.0f) {
                        v->phase += 8.0f;
                    }
                    a = v->size * 0.4f;
                    b = v->size * 3.0f;
                    func_00408090(m, v->trail0, 2, 0x60804020, 0xC00000, 23, a, b, v->phase);
                    func_00408090(m, v->trail1, 1, 0x60804020, 0xC00000, 23, a * 1.5f, b * 1.5f, v->phase);
                }
            }
            p++;
        }
    }
}
