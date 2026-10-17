#include "common.h"

extern void func_004C20A8(s32, s32, s32, s32);

typedef struct { u8 pad[0x150]; s16 w; s16 h; } S_1CFEC0_3A3FB0;
extern S_1CFEC0_3A3FB0 D_001CFEC0_003A3FB0;
extern u32 *D_001E10E8_003A3FB0;
void func_004C20A8(s32 x0, s32 x1, s32 y0, s32 y1) {
    s32 w = D_001CFEC0_003A3FB0.w - 1;
    s32 h = D_001CFEC0_003A3FB0.h - 1;
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (w < x1) x1 = w;
    if (h < y1) y1 = h;
    D_001E10E8_003A3FB0[0] = 0x10000002;
    D_001E10E8_003A3FB0[1] = 0;
    D_001E10E8_003A3FB0[2] = 0;
    D_001E10E8_003A3FB0[3] = 0x50000002;
    D_001E10E8_003A3FB0[4] = 0x8001;
    D_001E10E8_003A3FB0[5] = 0x10000000;
    D_001E10E8_003A3FB0[6] = 0xE;
    D_001E10E8_003A3FB0[7] = 0;
    *(unsigned long *)(D_001E10E8_003A3FB0 + 8) = (unsigned long)x0 | ((unsigned long)x1 << 16) | ((unsigned long)y0 << 32) | ((unsigned long)y1 << 48);
    D_001E10E8_003A3FB0[10] = 0x40;
    D_001E10E8_003A3FB0[11] = 0;
    D_001E10E8_003A3FB0 += 12;
}
