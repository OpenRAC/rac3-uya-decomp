#include "common.h"

/* localdecomp:start func_004BFEA0 */
typedef struct {
    u8 p0[4];
    s32 val;
    s32 idx;
    u8 pC[4];
} E_4BFEA0;

typedef struct {
    u8 p0[4];
    s32 w4;
    u8 p8[0x78];
    s32 sel;
    u8 p84[0xBC];
    E_4BFEA0 ent[1];
} G_4BFEA0;

typedef struct {
    s32 w0;
    u8 p4[0x74];
    s32 w78;
} H_4BFEA0;

typedef struct {
    s32 a[5];
} T_4BFEA0;

extern G_4BFEA0 D_00244740;
extern H_4BFEA0 D_00142660;
extern T_4BFEA0 D_001DAE68;
extern u8 D_001E10B8[8];
extern u8 D_001E1070[8];
extern u8 D_002F27D8[];
extern s32 D_001E0FFC;
extern s32 D_001E1000;

extern s32 func_004176B0(s32);
extern s32 func_004181A0(s32);
extern s32 func_00512FE8(s32, s32);
extern void func_004BB0F0(u8 *, s32);
extern void func_00512ED8(s32, f32 *, f32 *, f32 *, f32 *);
extern s32 func_00512480(s32, f32, f32);
extern void func_004BD430(u8 *, s32, u32);
extern void func_004BFC98(s32);
extern void func_00512AB0(s32, s32, s32);
extern void func_00512D70(s32, s32);

void func_004BFEA0(void) {
    G_4BFEA0 *g;
    T_4BFEA0 t;
    s32 idx;
    s32 val;
    s32 lt;
    s32 on;
    s32 n;
    u32 col;
    f32 sc;
    f32 x;
    f32 y;

    g = &D_00244740;
    idx = g->ent[g->sel].idx;
    if (idx == 0) {
        idx = D_00142660.w78;
    }
    t = D_001DAE68;
    col = 0x80707070;
    sc = 0.563f;
    func_00512FE8(0x48000B, func_004181A0(func_004176B0(idx)));
    func_00512FE8(0x48000C, func_004181A0(t.a[idx]));
    func_004BB0F0(D_001E10B8, D_00142660.w0);
    func_00512ED8(0x480011, &x, &y, &y, &y);
    func_00512480(0x48001B, x - 0.015f, 0.64f);
    val = g->ent[g->sel].val;
    lt = val < D_00142660.w0;
    func_004BB0F0(D_001E1070, val);
    func_00512ED8(0x48000E, &y, &y, &x, &y);
    func_00512480(0x48001A, x + 0.012f, sc);
    func_00512ED8(0x48001A, &y, &y, &x, &y);
    func_00512480(0x48000F, x + 0.01f, sc);
    if (lt) {
        col = 0x8066CCFF;
    }
    func_004BD430(D_002F27D8, 0x48001A, col);
    func_004BD430(D_002F27D8, 0x48000F, col);
    n = g->w4;
    if (n < 15) {
        D_001E0FFC = n;
        func_004BFC98(0);
        func_00512AB0(0x48000C, 1, 0);
    } else {
        D_001E1000 = 0;
        func_00512AB0(0x48000C, 1, 1);
    }
    if (val == 0) {
        func_00512FE8(0x48000B, func_004181A0(1196));
    }
    on = val != 0;
    func_00512D70(0x480011, on);
    func_00512D70(0x48001B, on);
    func_00512D70(0x48000E, on);
    func_00512D70(0x48001A, on);
    func_00512D70(0x48000F, on);
    func_00512D70(0x480012, on);
    if (val != 0) {
        func_00512D70(0x480012, lt);
    }
}
/* localdecomp:end func_004BFEA0 */
