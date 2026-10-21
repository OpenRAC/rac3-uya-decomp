#include "common.h"

extern s32 func_0012C908(s32);
extern s32 func_004D3E20();
/* The 16-byte .sdata declarations look small to gcc (no %hi/%lo split) but
   not to the assembler, which reaches them through lui, as Ps2EeAs did for
   symbols it had no size for yet; the other small ones go through $gp. */
extern u8 D_001D672C[16] __attribute__((section(".sdata")));
extern s32 D_001DF9C8[4] __attribute__((section(".sdata")));
extern s32 D_001DF9C8_g; /* D_001DF9C8 in a branch delay slot: $gp */
extern f32 D_001DB920;
extern void func_004C1E50(s32);
extern s32 D_001DFBC4[4] __attribute__((section(".sdata")));
extern void func_004304B0(void);
extern void func_0042EFF8(void);
extern void func_00402A10(s32);
extern s32 D_001D9870[4] __attribute__((section(".sdata")));
extern s32 D_001D4B48[4] __attribute__((section(".sdata")));
extern u8 D_001DB901;
extern s32 func_00428518(void);
extern void func_00400228(void);

extern u8 D_001DB900;
extern s32 D_001DFC14;
extern u8 D_001DB924;
extern void func_00432CB0(s32, s32);
extern void func_004D3710(void);
extern void func_004D3998(void);
extern void func_0045E370(void);
extern s32 func_004D33B0(s32);
extern void func_003FF920(void);
extern void func_004D3168(void);
extern void func_004C1D30(void);
extern void func_004C1CB0(void);
extern void func_00412DC0(void);
extern void func_004D4B50(void);
extern void func_00413138(s32);
extern void func_00412CA8(void);
extern void func_00412D40(s32);
extern void func_004D3CF8(void);
s32 func_004D3E20(void) {
    s32 r;
    if (D_001D672C[0] == 0) func_00432CB0(0, D_001DFBC4[0]);
    if (D_001DFBC4[0] < 0) {
        func_004D3710();
        return 1;
    }
    r = 0;
    func_004D3998();
    D_001DB900 = 0;
    D_001DB901 = 0;
    for (;;) {
        func_004C1D30();
        func_004C1CB0();
        func_00412DC0();
        if (D_001DB924 != 0) func_004D4B50();
        else func_00413138(1);
        func_00412CA8();
        func_00412D40(0);
        if (r != 0) break;
        func_00400228();
        func_0045E370();
        r = func_004D33B0(D_001DB900);
        D_001DFC14 = 0;
        func_003FF920();
        func_004D3168();
        func_004304B0();
        func_0042EFF8();
        func_004C1E50(1);
        func_0012C908(0);
        D_001DF9C8_g = D_001DF9C8[0] + 1;
        if (D_001D9870[0] == 0) D_001DB901 = func_00428518() != 0;
        D_001DB900 = D_001D4B48[0] >= 2;
    }
    func_004C1E50(1);
    func_0012C908(0);
    if (D_001DB920 > 0.0f) func_00402A10(2);
    func_004D3CF8();
    return 1;
}
