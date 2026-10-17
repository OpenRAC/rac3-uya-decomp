#include "common.h"

typedef int u128_3D1BE8 __attribute__((mode(TI)));
typedef struct { u8 p0[0xAA]; s16 hAA; } O_3D1BE8;
typedef struct { u8 p0[0x19E0]; O_3D1BE8 *p19E0; u8 p19E4[0x25C0 - 0x19E4]; s32 w25C0; } G_3D1BE8;
typedef struct {
    u8 p0[0x10]; u128_3D1BE8 pos; u8 p20[0x11]; u8 b31; u8 p32[0x3D]; u8 b6F; u8 p70[0x88]; f32 fF8;
} M_3D1BE8;
typedef struct {
    u8 p0[0x140]; s32 w140; u8 p144[0x1C]; u8 x160[0x68]; f32 f1C8; u8 p1CC[0x14]; u8 x1E0[0x60]; f32 f240; u8 p244[0x30]; f32 f274; f32 f278;
} P_3D1BE8;
extern G_3D1BE8 D_001A4BE0;
extern f32 D_001DEF30;
extern f32 D_001DEF34;
extern f32 D_001DEF3C;
extern f32 D_001DEF40;
extern u8 D_001E2800[];
extern f32 func_0040E798(f32, f32);
extern void func_0044C818(M_3D1BE8 *, void *, s32, f32, f32);
extern f32 func_0040D8A0(void *, void *);
extern void func_004452A8(M_3D1BE8 *);

void func_003D1BE8(M_3D1BE8 *m, P_3D1BE8 *p) {
    if (p->w140 == D_001A4BE0.w25C0 && D_001A4BE0.p19E0 != 0 && D_001A4BE0.p19E0->hAA == 6679) {
        p->f1C8 = func_0040E798(p->f274, m->fF8);
        func_0044C818(m, p->x160, 0, D_001DEF30 + D_001DEF30, D_001DEF34 + D_001DEF34);
        p->f240 = p->f278;
        func_0044C818(m, p->x1E0, 2, D_001DEF3C + D_001DEF3C, D_001DEF40 + D_001DEF40);
    } else {
        p->f1C8 = func_0040E798(p->f274, m->fF8);
        func_0044C818(m, p->x160, 0, D_001DEF30, D_001DEF34);
        p->f240 = p->f278;
        func_0044C818(m, p->x1E0, 2, D_001DEF3C, D_001DEF40);
    }
    if (m->b31 != 0) {
        if (func_0040D8A0(D_001E2800, &m->pos) < 576.0f) {
            func_004452A8(m);
            m->b6F = 22;
        }
    }
}
