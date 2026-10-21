#include "common.h"

/* localdecomp:start func_004D7630 */
typedef struct { s32 f0; u8 p4[0x4C]; u8 f50; u8 f51; } S_4D7630;
typedef struct { s32 a; s32 b; } P_4D7630;
typedef struct { u8 p[0x68]; s32 f68; } T_4D7630;
extern S_4D7630 D_002513B8[];
extern T_4D7630 D_001EA9C0[];
extern P_4D7630 D_002E9E00[];
extern s32 D_002E9E08[];
extern s32 D_002E9E0C[];
extern s32 D_001DBC60;
extern u8 D_001DBC64[];
extern s32 D_0023ACF0[];
extern s32 D_001E6E00[];
extern u8 D_001DB950;
extern s32 func_004D2120();
extern void func_004D2EF0();
extern void func_004A7D88();
extern void func_004D7838();
extern void func_004D2370(s32, s32);
extern void func_004D2D70();
extern void func_004D4600(s32, s32 *, s32);
extern s32 func_004D4688();
extern void func_004D4770();
extern void func_004D4C58();
extern s32 func_004181A0(s32);
extern s32 func_0011BB58(void *, s32, s32);
extern void func_004D75D8();
s32 func_004D7630(void) {
    s32 r, a, s, tmp;
    s32 *p;
    u8 *d;
    s32 t;
    S_4D7630 *g;
    g = D_002513B8;
    g->f50 = 0;
    g->f51 = 0;
    r = func_004D2120();
    if (D_001DB950) {
        D_001DB950 = 0;
    } else {
        d = (u8 *)g + 0x10;
        if ((u32)(r - 1) < 2 || r == 4 || r == 8 || r == 0x1B || r == 0x1C || r == 9 || r == 0x1D
            || r == 5 || r == 0xD || r == 0x17 || r == 0xA || r == 0x12 || r == 0xE) {
            if (r > 0) a = D_002E9E00[r % 60].b;
            else a = D_002E9E0C[0];
        } else {
            if (r > 0) a = D_002E9E00[r % 60].a;
            else a = D_002E9E08[0];
        }
        func_0011BB58(d, func_004181A0(a), 0x40);
    }
    func_004D2370(1, 0);
    func_004D2D70(5, &D_001DBC60);
    func_004D4600(4, (s32 *)D_001DBC64, D_001DBC60);
    s = D_001EA9C0[0].f68;
    func_004D2EF0(r, &tmp, s);
    D_002513B8[0].f0 = s;
    s = s + tmp;
    D_001EA9C0[0].f68 = s;
    func_004D4770(func_004D4688());
    func_004D4C58(func_004D7838);
    { s32 i = 0; while (D_0023ACF0[i]) { D_0023ACF0[i] = 0; i++; } }
    func_004A7D88(D_001E6E00[0x15]);
    func_004D75D8();
    return 1;
}
/* localdecomp:end func_004D7630 */
