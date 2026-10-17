#include "common.h"

extern u32 *D_001E10E8;
extern u8 D_001D3EF0[];

extern u32 *D_001E10E8;
extern s32 D_001D55F8;
extern s32 D_001D55FC;
extern u8 D_001D3650[];
extern u8 D_001D3EF0[];
void func_004DB630(void) {
    D_001E10E8[0] = (D_001D55F8 >> 4) | 0x30000000;
    D_001E10E8[1] = (u32)D_001D3650;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = (D_001D55F8 >> 4) | 0x50000000;
    D_001E10E8 += 4;
    D_001E10E8[0] = (D_001D55FC >> 4) | 0x30000000;
    D_001E10E8[1] = (u32)D_001D3EF0;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = (D_001D55FC >> 4) | 0x50000000;
    D_001E10E8 += 4;
}
