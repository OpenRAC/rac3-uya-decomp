#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
    u8 p8[8];
} T_4C1638;

typedef struct {
    u8 p0[4];
    s32 val;
    u8 p8[4];
    s32 idx;
} E_4C1638;

typedef struct {
    u8 p0[4];
    s32 w4;
    u8 p8[0x78];
    s32 sel;
    u8 p84[0xBC];
    E_4C1638 ent[1];
} G_4C1638;

extern G_4C1638 D_00244740;
extern T_4C1638 D_002F1C60[];
extern u8 D_001E10B8[8];
extern u8 D_001E1070[8];
extern s32 D_001E0FFC;
extern s32 D_001E1000;

extern s32 func_004181A0(s32);
extern void func_00512FE8(s32, s32);
extern void func_004BDC90(void);
extern s32 func_0044F480(void);
extern void func_004BB0F0(u8 *, s32);
extern void func_00512ED8(s32, f32 *, f32 *, f32 *, f32 *);
extern s32 func_00512480(s32, f32, f32);
extern void func_005130C8(s32, u32);
extern void func_004C11E8(s32);
extern void func_00512AB0(s32, s32, s32);
extern s32 func_00512D70(s32, s32);

void func_004C1638(void) {
    G_4C1638 *g;
    s32 idx;
    s32 val;
    s32 en;
    s32 on;
    s32 n;
    u32 col;
    f32 sc;
    f32 x;
    f32 y;

    g = &D_00244740;
    col = 0x80707070;
    sc = 0.563f;
    idx = g->ent[g->sel].idx;
    func_00512FE8(0x48000B, func_004181A0(D_002F1C60[idx].w0));
    func_00512FE8(0x48000C, func_004181A0(D_002F1C60[idx].w4));
    func_004BDC90();
    n = func_0044F480();
    func_004BB0F0(D_001E10B8, n);
    func_00512ED8(0x480011, &x, &y, &y, &y);
    func_00512480(0x48001B, x - 0.015f, 0.64f);
    val = g->ent[g->sel].val;
    en = func_0044F480() >= val;
    if (val == 255) {
        en = 0;
    }
    func_004BB0F0(D_001E1070, val);
    func_00512ED8(0x48000E, &y, &y, &x, &y);
    func_00512480(0x48001A, x + 0.012f, sc);
    func_00512ED8(0x48001A, &y, &y, &x, &y);
    func_00512480(0x48000F, x + 0.01f, sc);
    if (en) {
        col = 0x8066CCFF;
    }
    func_005130C8(0x48001A, col);
    func_005130C8(0x48000F, col);
    n = g->w4;
    if (n < 15) {
        D_001E0FFC = n;
        func_004C11E8(0);
        func_00512AB0(0x48000C, 1, 0);
    } else {
        D_001E1000 = 0;
        func_00512AB0(0x48000C, 1, 1);
    }
    if (val == 0) {
        func_00512D70(0x480012, 1);
        func_00512FE8(0x480012, func_004181A0(268));
    } else {
        func_00512D70(0x480012, 0);
    }
    on = val != 0;
    func_00512D70(0x480011, on);
    func_00512D70(0x48001B, on);
    func_00512D70(0x48000E, on);
    func_00512D70(0x48001A, on);
    func_00512D70(0x48000F, on);
    if (val == 255) {
        func_00512D70(0x480011, 0);
        func_00512D70(0x48001B, 0);
        func_00512D70(0x48000E, 0);
        func_00512D70(0x48001A, 0);
        func_00512D70(0x48000F, 0);
    }
    if (val != 0) {
        func_00512D70(0x480012, en);
    }
}
