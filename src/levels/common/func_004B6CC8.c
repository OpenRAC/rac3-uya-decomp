#include "common.h"
extern u8 D_001A30B0[];
s32 func_004B6CC8(u32 a0, s32 a1) {
    if (a0 < 0x34) {
        u8 *p = (u8 *)&D_001A30B0[0] + a0 * 0x80;
        *(s32 *)(p + 0xd8) = a1;
    }
    return 1;
}
