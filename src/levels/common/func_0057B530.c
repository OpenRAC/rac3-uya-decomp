#include "common.h"
typedef struct { u8 p0[0x20]; u8 b20; } H_57B530;
typedef struct { u8 p0[0x10]; f32 f10; u8 p14[0xC]; H_57B530 *f20; u8 b24; u8 b25; u8 p26[0xA]; f32 f30, f34; u8 p38[8]; } E_57B530;
typedef struct { E_57B530 e[14]; s32 n; } T_57B530;
extern T_57B530 D_00257A00;
extern s32 D_00242A94;
extern s32 D_00240480, D_00240484, D_00240490, D_00240494;
extern void func_00585250(f32 *, void *);
extern void func_0057AF98(void *, f32, f32);
void func_0057B530(s32 a) {
    f32 v[2];
    s32 i;
    E_57B530 *p;
    if (D_00257A00.n == 0) return;
    for (i = 0; i < D_00257A00.n; i++) {
        p = &D_00257A00.e[i];
        if (p->b25 != a || p->f20 == 0 || p->f20->b20 == 0xFE || p->f20->b20 == 0xFD) continue;
        if (p->b24 != 0) {
            func_00585250(v, p);
            v[0] = (v[0] - (f32)D_00240490) * 0.0625f;
            v[1] = (v[1] - (f32)D_00240494) * 0.0625f;
        } else {
            v[0] = (f32)D_00240480 * p->f30;
            v[1] = (f32)D_00240484 * p->f34;
        }
        if (D_00242A94 != 0) p->f10 *= 0.75f;
        func_0057AF98(p, v[0], v[1]);
    }
    if (D_00242A94 == 0) D_00257A00.n = 0;
}
