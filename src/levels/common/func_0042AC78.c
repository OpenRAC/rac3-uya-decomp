#include "common.h"

extern s32 func_004344A0();

extern u8 D_001426E0_0039A9E0[];
extern s32 func_004344A0();
s32 func_0042AC78(s32 bit) {
    s32 b = bit % 8;
    s32 i = bit / 8;
    s32 r;
    if ((u32)b < 8) { r = (D_001426E0_0039A9E0[0x40 + i] >> b) & 1; } else { r = 0; }
    if ((u32)b < 8) { D_001426E0_0039A9E0[0x40 + i] |= 1 << b; }
    func_004344A0();
    return r;
}
