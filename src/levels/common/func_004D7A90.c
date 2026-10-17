#include "common.h"
extern s32 D_001DBC60;
extern u8 D_002513B8[];
extern u8 D_001E6E00[];
extern void func_004D30D0();
extern s32 func_004D4860();
extern s32 func_004D4868();
extern void func_004D22D0();
extern void func_004D4AB8();
extern s32 func_004D4688();
extern void func_004D47B0();
extern void func_004D4C58();
extern void func_004D4890();
extern void func_004D75D8();
extern void func_004D48B0();
extern void func_004D7838();
void func_004D7A90(s32 a0) {
    s32 v4;
    s32 v5;
    u8 *g;
    if (D_002513B8[0x50] != 0) {
        func_004D30D0();
        if (func_004D4860() == 1) {
            func_004D4AB8();
        }
        if (func_004D4860() > 0 && func_004D4868() != 0) {
            func_004D22D0();
        }
        if (D_002513B8[0x51] == 0) {
            if (func_004D4860() > 0 && a0 != 0) {
                v4 = D_001DBC60;
                D_002513B8[0x51] = 1;
            } else {
                v4 = func_004D4688();
            }
            func_004D47B0(v4);
            func_004D4C58(func_004D7838);
            func_004D4890();
            func_004D75D8();
        }
    }
    g = D_001E6E00;
    v5 = *(s16 *)(g + 0x40);
    if (D_002513B8[0x51] != 0) {
        if (*(s32 *)(g + 0x34) >= 0x1F) v5 += 0x1E;
    }
    func_004D48B0(*(s32 *)(g + 0x34), v5, 7, 7);
}
