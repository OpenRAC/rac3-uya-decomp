#include "common.h"

extern u32 *D_001E10E8[4] __attribute__((section(".sdata")));
extern u32 *D_001E10E8_g;
extern s32 D_001D55F4[4] __attribute__((section(".sdata")));
extern u8 D_001D2A50[];
extern s32 D_001DBCE4;

void func_004DAA10(void) {
    D_001E10E8[0][0] = (D_001D55F4[0] >> 4) | 0x30000000;
    D_001E10E8[0][1] = (u32)D_001D2A50;
    D_001E10E8[0][2] = 0;
    D_001E10E8[0][3] = (D_001D55F4[0] >> 4) | 0x50000000;
    D_001DBCE4 = 0;
    D_001E10E8_g = D_001E10E8[0] + 4;
}
