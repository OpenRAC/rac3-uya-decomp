#include "common.h"

typedef int u128_004EA5B0 __attribute__((mode(TI)));

typedef struct {
    u8 p0[0x18];
    f32 f18;
    u8 p1C[0x380 - 0x1C];
    u128_004EA5B0 q380;
} G_004EA5B0;

typedef struct {
    u8 p0[0x190];
    u128_004EA5B0 q190;
    f32 f1A0;
    f32 f1A4;
    u8 p1A8[0x143C - 0x1A8];
    f32 f143C;
} S_004EA5B0;

extern G_004EA5B0 D_001E2AC0[];
extern S_004EA5B0 D_001A4BE0[];
extern void func_004EAFF8(s32, f32, f32, f32);

void func_004EA5B0(void) {
    G_004EA5B0 *g = D_001E2AC0;
    S_004EA5B0 *s = D_001A4BE0;
    s->f1A0 = g->f18;
    s->q190 = g->q380;
    s->f1A4 = s->f143C;
    func_004EAFF8(0, 0.042f, 0.25f, 0.31997705f);
    s->f143C = s->f1A4;
}
