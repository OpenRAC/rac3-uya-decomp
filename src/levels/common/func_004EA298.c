#include "common.h"

/* localdecomp:start func_004EA298 */
typedef struct {
    u8 pad0[0x80];
    f32 v80[4];
    u8 pad90[0x1B8 - 0x90];
    s32 w1B8;
    u8 pad1BC[0x260 - 0x1BC];
    f32 v260[4];
    f32 f270;
    f32 f274;
    f32 f278;
    f32 f27C;
    f32 f280;
    f32 f284;
    u8 pad288[0x2A7 - 0x288];
    u8 b2A7;
    u8 pad2A8[0x360 - 0x2A8];
    s32 w360;
    u8 pad364[0x46E - 0x364];
    u8 b46E;
    u8 pad46F[0x47C - 0x46F];
    s16 h47C;
    u8 pad47E[0x488 - 0x47E];
    f32 f488;
    u8 pad48C[0x1474 - 0x48C];
    u8 b1474;
    u8 b1475;
    u8 b1476;
    u8 pad1477[0x25C4 - 0x1477];
    s32 w25C4;
    u8 pad25C8[4];
    s32 w25CC;
    u8 pad25D0[4];
    s32 w25D4;
    u8 pad25D8[8];
    s32 w25E0;
    u8 b25E4;
} S_4EA298;

extern S_4EA298 D_001A4BE0[];
extern f32 D_001A4E50[];

extern f32 func_0040BFE8(f32 *a, f32 *b);
extern void func_004450C0(f32 *a, f32 b, f32 c);
extern void func_00445168(f32 *a, f32 *b, f32 c, f32 d, f32 e, f32 f);

void func_004EA298(s32 copy) {
    S_4EA298 *d;
    f32 *p;

    switch (D_001A4BE0->b25E4) {
    case 0:
        D_001A4BE0->f278 = 0.8f;
        D_001A4BE0->f27C = 0.7f;
        D_001A4BE0->f280 = 0.45f;
        break;
    case 1:
        D_001A4BE0->f278 = 0.55f;
        D_001A4BE0->f27C = 0.45f;
        D_001A4BE0->f280 = 0.25f;
        break;
    case 3:
        D_001A4BE0->f278 = 0.8f;
        D_001A4BE0->f27C = 0.6f;
        D_001A4BE0->f280 = 0.45f;
        break;
    }
    if (D_001A4BE0->w25CC == 4) {
        if (D_001A4BE0->h47C < D_001A4BE0->w1B8 && D_001A4BE0->b46E == 0) {
            D_001A4BE0->f27C = D_001A4BE0->f488;
        }
    } else if (D_001A4BE0->w25C4 == 6) {
        D_001A4BE0->f27C = 0.5f;
    } else if (D_001A4BE0->w25C4 == 4) {
        D_001A4BE0->f278 = 0.35000002f;
    } else if ((u32)(D_001A4BE0->w25CC - 17) < 2) {
        D_001A4BE0->f278 = 0.0f;
        D_001A4BE0->f27C = 0.0f;
    } else if (D_001A4BE0->b1474 != 0 && D_001A4BE0->w360 != 0) {
        D_001A4BE0->f278 = 0.8f;
        D_001A4BE0->f27C = 0.9f;
    } else if (D_001A4BE0->w25C4 == 129) {
        D_001A4BE0->f280 = 0.8f;
    } else if (D_001A4BE0->w25C4 == 80) {
        D_001A4BE0->f280 = 0.5f;
    }
    if (copy) {
        D_001A4BE0->f270 = D_001A4BE0->f278;
        D_001A4BE0->f274 = D_001A4BE0->f27C;
        D_001A4BE0->f284 = D_001A4BE0->f280;
    }
    if (D_001A4BE0->b2A7 != 0 && D_001A4BE0->w25D4 != 18 && D_001A4BE0->w25E0 != 18
        && (D_001A4BE0->b25E4 != 0 || !(D_001A4BE0->f274 < 0.53f))
        && D_001A4BE0->w25CC != 17 && D_001A4BE0->b1476 == 0) {
        f32 f = func_0040BFE8(D_001A4BE0->v260, D_001A4BE0->v80);
        if (!(D_001A4BE0->f284 * 0.5f < f)) return;
    }
    p = D_001A4E50;
    d = (S_4EA298 *)((u8 *)p - 624);
    func_004450C0(p, d->f278, 0.02f);
    func_004450C0(p + 1, d->f27C, 0.02f);
    func_00445168(p + 5, p + 6, d->f280, 0.02f, 0.3f, 0.06666667f);
}
/* localdecomp:end func_004EA298 */
