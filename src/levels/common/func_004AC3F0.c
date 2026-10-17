#include "common.h"
extern s32 func_004ABE98(s32);

extern s32 func_0012C908(s32);
extern s32 D_001D6694;

typedef struct { u8 pad[0x44]; s16 h44; u8 pad2[0x15A]; s32 tbl[1]; } S_225780_3A2028;
typedef struct { u8 pad[0x28]; s32 f28; } E_3A2028;
extern S_225780_3A2028 D_001E6E00_3A2028;
extern E_3A2028 *D_001E009C_3A2028;
extern s32 D_001D6694;
extern s32 D_001D6690;
extern s32 D_001DF9C4;
extern s32 D_001DF9C8;
extern s32 D_001DFBDC;
extern void func_004C1D30();
extern void func_004C1CB0();
extern void func_00412DC0();
extern void func_00413138();
extern void func_00412CA8();
extern void func_004304B0();
extern void func_003FE8F8();
extern void func_00437500();
extern void func_004002A0();
extern void func_0045E370();
extern s32 func_004AB800();
extern void func_00412D40();
extern void func_004010D0();
extern void func_004C1E50();
extern void func_004AC210();
s32 func_004AC3F0(void) {
    E_3A2028 *t;
    E_3A2028 *e;
    s32 i;
    s32 r;
    s32 s;
    if (((s32 (*)())func_004ABE98)() == 0) return 1;
    t = D_001E009C_3A2028;
    for (i = 0; i < D_001E6E00_3A2028.h44; i++) {
        do { e = (E_3A2028 *)D_001E6E00_3A2028.tbl[i]; } while (0);
        if (e != 0 && t != e) {
            do { e->f28 = (s32)t; t = e; } while (0);
        }
    }
    D_001D6694 = 2;
    do {
        func_004C1D30();
        func_004C1CB0();
        func_00412DC0();
        func_00413138(1);
        func_00412CA8();
        func_004304B0();
        func_003FE8F8();
        func_00437500();
        func_004002A0();
        D_001DFBDC = -1;
        func_0045E370();
        r = func_004AB800();
        func_00412D40(0);
        D_001DF9C4 = 0x131;
        func_004010D0(0);
        s = D_001D6690;
        if (s != -2) {
            D_001D6694 = s;
            D_001D6690 = -2;
        }
        func_004C1E50(1);
        func_0012C908(0);
        D_001DF9C8 = D_001DF9C8 + 1;
    } while (D_001D6694 == 2);
    D_001D6694 = 0;
    func_004AC210();
    return r;
}
