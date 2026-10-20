#include "common.h"

typedef struct {
    u8 p0[0x10];
    u8 x10[0x10];
    u8 x20;
    u8 p21[0xF];
    union {
        unsigned long q;
        u8 b[8];
    } x30;
    u8 p38[0x80 - 0x38];
} T_503428;
typedef struct {
    u8 p0[0x80];
    u8 x80[0x18];
    f32 x98;
    u8 p9C[0x1228 - 0x9C];
    s32 x1228;
    u8 p122C[0x1430 - 0x122C];
    T_503428 *x1430;
    u8 p1434[0x16B0 - 0x1434];
    s32 x16B0;
    u8 p16B4[0x25C4 - 0x16B4];
    s32 x25C4;
} G_503428;
typedef struct {
    u8 p0[0x1B0];
    u16 x1B0;
    u8 p1B2[2];
    u32 x1B4;
    u32 x1B8;
} H_503428;
typedef struct {
    u8 p0[0x1A0];
    s32 x1A0;
    s32 x1A4;
} P_503428;
typedef struct {
    u8 p0[0x18];
    f32 x18;
    u8 p1C[0x380 - 0x1C];
    u8 x380[1];
} B_503428;
extern f32 func_0040BFB0(void *, void *);
extern T_503428 *func_004E5BB8(f32, f32, f32, f32, void *, s32, s32);
extern G_503428 D_001A4BE0;
typedef struct {
    unsigned long b0 : 5;
    unsigned long b5 : 1;
    unsigned long b6 : 2;
} __attribute__((packed)) F_503428;
extern F_503428 D_00142A60[];
extern P_503428 *D_001D52FC;
extern H_503428 D_001A7C10;
extern u32 D_001D4C38;
extern s32 D_001D545C;
extern B_503428 D_001E2AC0;

void func_00503428(void) {
    T_503428 *t;
    if (D_001A4BE0.x1228 < 0 || (D_00142A60[D_001A4BE0.x1228].b5 & 1) == 0 || D_001A4BE0.x16B0 == 1) {
        D_001A4BE0.x1430 = 0;
        return;
    }
    if (D_001A4BE0.x25C4 == 49) {
        D_001A4BE0.x1430 = 0;
        return;
    }
    t = D_001A4BE0.x1430;
    if (t) {
        if (30.0f < func_0040BFB0(D_001A4BE0.x80, t->x10)) D_001A4BE0.x1430 = 0;
        if ((D_001D52FC->x1A0 & 3) != 3) D_001A4BE0.x1430 = 0;
        t = D_001A4BE0.x1430;
        if (t == 0) return;
        if ((t->x30.q & 0x100200000000L) == 0x100000000000L && t->x20 != 254 && t->x20 != 253 && t->x30.b[1] != 0) return;
        D_001A4BE0.x1430 = 0;
        if (D_001A7C10.x1B0 < 0xFFFF) D_001A7C10.x1B0++;
        if (D_001D4C38 > D_001A7C10.x1B4) D_001A7C10.x1B4 = D_001D4C38;
        D_001A7C10.x1B8 = (D_001A7C10.x1B8 | (1 << D_001D545C)) | 0x80000000;
    } else {
        if ((D_001D52FC->x1A0 & 3) != 3) return;
        if ((D_001D52FC->x1A4 & 3) == 0) return;
        D_001A4BE0.x1430 = func_004E5BB8(25.0f, D_001E2AC0.x18, 0.610865235f, 1.22173047f, D_001E2AC0.x380, 5, 1);
        if (D_001A4BE0.x1430 == 0) {
            D_001A4BE0.x1430 = func_004E5BB8(25.0f, D_001A4BE0.x98, 0.610865235f, 1.22173047f, &D_001A4BE0, 5, 1);
        }
    }
}
