#include "common.h"

typedef int s128_465020 __attribute__((mode(TI)));

typedef struct {
    f32 pos[3];
    f32 f12;
    f32 f16;
    f32 f20;
    f32 f24;
    f32 f28;
} P_465020;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 x4;
    u8 b8;
    u8 b9;
    s16 h10;
    f32 f12;
    s128_465020 q16;
    P_465020 p;
} E_465020;

typedef struct {
    u8 pad0[136];
    f32 f136;
    u8 pad1[708];
    f32 f848;
    u8 pad2[8816];
    s32 x9668;
} G_465020;

extern G_465020 D_001A4BE0[];
extern u8 *D_002211A0[];
extern E_465020 *func_0045E438(s32);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440878(s32, s32);
extern f32 func_00440978(void);

E_465020 *func_00465020(s128_465020 *q, f32 *pos, s32 arg, f32 scale, f32 h) {
    E_465020 *e = func_0045E438(34);
    P_465020 *p;

    if (e != 0) {
        e->x4 = arg;
        e->b1 = 0;
        p = &e->p;
        e->b9 = 68;
        e->b3 = 68;
        p->f12 = func_004408C0(0.75f, 1.25f) * scale;
        e->f12 = 5250.0f;
        e->b8 = func_00440878(-10, 10) - 128;
        e->b2 = *D_002211A0[0];
        e->h10 = func_00440878(70, 140);
        if (h == -1.0f) {
            G_465020 *g = D_001A4BE0;
            if (g->x9668 == 48) {
                p->f16 = g->f136 + 0.4f;
            } else {
                p->f16 = g->f848;
            }
        } else {
            p->f16 = h;
        }
        p->f20 = func_00440978();
        p->f24 = func_004408C0(0.0290888231f, 0.116355292f);
        p->f28 = func_004408C0(0.00833333377f, 0.0233333334f);
        p->pos[0] = pos[0];
        p->pos[1] = pos[1];
        p->pos[2] = pos[2];
        e->q16 = *q;
    }
    return e;
}
