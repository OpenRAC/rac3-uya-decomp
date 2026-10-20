#include "common.h"

extern u32 * D_001E10E8;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;

void func_0041F008(s32 x0, s32 y0, s32 x1, s32 y1, unsigned long color, s32 fine) {
    unsigned long *q;

    D_001E10E8[0] = 0x10000003;
    D_001E10E8[1] = 0;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0x50000003;
    q = (unsigned long *)D_001E10E8;
    D_001E10E8 += 4;
    q[2] = 0x4400000000008001UL;
    q[3] = 0x4410;
    q[4] = 70;
    q[5] = color;
    if (fine) {
        q[6] = (unsigned long)(long)(x0 + D_001D4BD0 - 8) | ((unsigned long)(long)(y0 + D_001D4BD4 - 8) << 16) | 0xFFFFF000000000UL;
        q[7] = (unsigned long)(long)(x1 + D_001D4BD0 - 8) | ((unsigned long)(long)(y1 + D_001D4BD4 - 8) << 16) | 0xFFFFF000000000UL;
    } else {
        q[6] = (unsigned long)(long)(x0 * 16 + D_001D4BD0 - 16) | ((unsigned long)(long)(y0 * 16 + D_001D4BD4 - 16) << 16) | 0xFFFFF000000000UL;
        q[7] = (unsigned long)(long)(x1 * 16 + D_001D4BD0 - 16) | ((unsigned long)(long)(y1 * 16 + D_001D4BD4 - 16) << 16) | 0xFFFFF000000000UL;
    }
    D_001E10E8 += 12;
}
