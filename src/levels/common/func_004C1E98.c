#include "common.h"

extern void func_004C1E98(s32, u32);

extern u32 *D_001E10E8_003A3DE8;
void func_004C1E98(s32 a0, u32 a1) {
    D_001E10E8_003A3DE8[0] = a1 | 0x30000000;
    D_001E10E8_003A3DE8[1] = a0;
    D_001E10E8_003A3DE8[2] = 0;
    D_001E10E8_003A3DE8[3] = 0;
    D_001E10E8_003A3DE8 += 4;
}
