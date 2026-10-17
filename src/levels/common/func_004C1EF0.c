#include "common.h"

extern u32 *D_001E10E8_003A3E40;
extern void func_0040BD58(u32 *, s32, s32);
void func_004C1EF0(u32 a0, s32 a1, u32 a2) {
    D_001E10E8_003A3E40[0] = a2 | 0x10000000;
    D_001E10E8_003A3E40[1] = 0;
    D_001E10E8_003A3E40[2] = 0x1000404;
    D_001E10E8_003A3E40[3] = a0 | (a2 << 16) | 0x6C000000;
    D_001E10E8_003A3E40 += 4;
    func_0040BD58(D_001E10E8_003A3E40, a1, a2 << 4);
    D_001E10E8_003A3E40 = (u32 *)((u8 *)D_001E10E8_003A3E40 + (a2 << 4));
}
