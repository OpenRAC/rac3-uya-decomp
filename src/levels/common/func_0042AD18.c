#include "common.h"

extern u8 D_001426E0[];

s32 func_0042AD18(s32 bit) {
    s32 i = bit / 8;
    s32 b = bit % 8;
    s32 r;
    if ((u32)b < 8) { r = (D_001426E0[0x40 + i] >> b) & 1; } else { r = 0; }
    return r;
}
