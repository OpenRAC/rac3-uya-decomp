#include "common.h"

extern s32 *D_001E10E8;

void func_004C1FA0(s32 a) {
    D_001E10E8[0] = 0x10000000;
    D_001E10E8[1] = 0;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = a;
    D_001E10E8 += 4;
}
