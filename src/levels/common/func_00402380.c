#include "common.h"

extern void func_0040BCB8();
extern s32 D_001D4BB0;
extern s32 D_001E10E8;
extern void func_004C21C0();

extern s32 D_001D4BB0;
extern s32 D_001E10E8;
extern u8 D_002EF0E0[];
extern u8 D_002EF150[];
extern void func_0040BCB8();
extern void func_004C21C0();
s32 func_00402380(s32 a, s32 b) {
    u8 *p;
    s32 h = D_001D4BB0 >> 8;
    if (b == 0x14) {
        func_0040BCB8(D_001E10E8, D_002EF0E0, 0x70);
        D_001D4BB0 = D_001D4BB0 + 0x100;
    } else {
        func_0040BCB8(D_001E10E8, D_002EF150, 0x70);
        D_001D4BB0 = D_001D4BB0 + 0x400;
    }
    p = (u8 *)D_001E10E8;
    *(s32 *)(p + 0x64) = a;
    *(s16 *)(p + 0x24) = h;
    D_001E10E8 = D_001E10E8 + 0x70;
    func_004C21C0();
    return h;
}
