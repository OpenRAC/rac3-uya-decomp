#include "common.h"

/* localdecomp:start func_004F3770 */
typedef struct {
    u8 pad0[0x88];
    f32 f88;
    u8 pad8C[0x118 - 0x8C];
    f32 f118;
    u8 pad11C[0x1DC - 0x11C];
    s16 h1DC;
    s16 h1DE;
    u8 pad1E0[0x338 - 0x1E0];
    f32 f338;
    f32 f33C;
    u8 pad340[0x350 - 0x340];
    f32 f350;
    f32 f354;
    u8 pad358[0x360 - 0x358];
    s32 f360;
    u8 pad364[0x368 - 0x364];
    s16 h368;
    u8 pad36A[2];
    s16 h36C;
    u8 pad36E[0x46E - 0x36E];
    u8 b46E;
    u8 pad46F[0x1470 - 0x46F];
    s16 h1470;
    u8 pad1472[0x1476 - 0x1472];
    u8 b1476;
    u8 pad1477;
    u8 b1478;
    u8 b1479;
    u8 pad147A[2];
    u8 b147C;
    u8 b147D;
    u8 pad147E;
    u8 b147F;
    u8 pad1480[0x25C4 - 0x1480];
    s32 f25C4;
    u8 pad25C8[4];
    s32 f25CC;
    u8 pad25D0[0x25E4 - 0x25D0];
    u8 b25E4;
    u8 pad25E5[0x25EA - 0x25E5];
    u8 b25EA;
    u8 pad25EB[0x25EE - 0x25EB];
    u8 b25EE;
    u8 pad25EF[0x2848 - 0x25EF];
    f32 f2848;
    u8 pad284C[4];
    s32 f2850;
} G_004F3770;

extern G_004F3770 D_001A4BE0;
extern s32 D_00142668[];
extern u8 D_00142CAD[];
extern void func_0041C4A8(void *, s32);
extern void func_004EBF80(s32);
extern void func_004F3740(void);
extern void func_00508950(s32, s32);

void func_004F3770(void) {
    s16 st = D_001A4BE0.h1470;
    u8 keep = D_001A4BE0.b147F;
    f32 d;
    s32 t;

    func_0041C4A8(&D_001A4BE0.h1470, 16);
    D_001A4BE0.b147F = keep;
    D_001A4BE0.h1470 = st;
    D_001A4BE0.b25EA = 0;
    D_001A4BE0.h368 = 0;
    if (D_001A4BE0.b25EE != 0) {
        return;
    }
    t = *(volatile s32 *)&D_001A4BE0.f360;
    t = -1;
    if (st == t) {
        return;
    }
    if ((st == 2 || st == 0x11 || st == 0x12) && D_001A4BE0.h1DE == 0 &&
        (D_001A4BE0.h36C == 0 || D_001A4BE0.f33C < 2.5f)) {
        D_001A4BE0.b1479 = 1;
        if (D_001A4BE0.b25E4 == 0 && D_00142CAD[0] != 0) {
            D_001A4BE0.h368 = 1;
        }
    }
    if (st == 0x11 && D_001A4BE0.h1DC == 0 && D_001A4BE0.h36C == 0 && D_001A4BE0.f25CC != 7) {
        func_004EBF80(D_00142668[0] / 8);
        D_001A4BE0.h1DC = 90;
        func_00508950(0xB1, 1);
    }
    if (st == 0xE) {
        D_001A4BE0.b1476 = 1;
        D_001A4BE0.f2848 = 0.2f;
        D_001A4BE0.f350 = D_001A4BE0.f338 + 0.2f;
    }
    if (st == 0) {
        d = D_001A4BE0.f350 - D_001A4BE0.f338;
        D_001A4BE0.f2848 = d;
        if (d < 0.85f && d > 0.25f) {
            D_001A4BE0.b25EA = 1;
        }
        D_001A4BE0.b1476 = 1;
    }
    if (st == 3) {
        D_001A4BE0.b1478 = 1;
    }
    if (st == 0xB) {
        D_001A4BE0.b147D = 1;
    }
    if (st == 8 || st == 0x12) {
        D_001A4BE0.b147C = 1;
    }
    if (st == 0xC) {
        D_001A4BE0.b147C = 1;
    }
    if (D_001A4BE0.b1478 != 0 && D_001A4BE0.f25C4 != 0x6A && D_001A4BE0.f25C4 != 0x7D &&
        fabsf(D_001A4BE0.f354 - (D_001A4BE0.f88 + 0.25f)) < 1.0f &&
        D_001A4BE0.f354 - D_001A4BE0.f88 > 0.0f &&
        (D_001A4BE0.f25C4 != 0x6B || D_001A4BE0.b46E != 0) &&
        (D_001A4BE0.f118 < 0.0f || D_001A4BE0.f25C4 == 0x80)) {
        func_004F3740();
        if (D_001A4BE0.f2850 == 0) {
            func_00508950(0x7D, 1);
        } else {
            func_00508950(0x6A, 1);
        }
        return;
    }
    if (D_001A4BE0.b147D != 0 && D_001A4BE0.f25C4 != 0x7D && D_001A4BE0.f25C4 != 0x79 &&
        fabsf(D_001A4BE0.f354 - (D_001A4BE0.f88 + 0.25f)) < 1.0f &&
        D_001A4BE0.f354 - D_001A4BE0.f88 > 0.0f &&
        (D_001A4BE0.f118 < 0.0f || D_001A4BE0.f25C4 == 0x80)) {
        func_004F3740();
        func_00508950(0x7D, 1);
    }
}
/* localdecomp:end func_004F3770 */
