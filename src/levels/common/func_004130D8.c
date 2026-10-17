#include "common.h"

extern u32 *D_001E10E8;
extern u8 D_001D0070[];
void func_004130D8(void) {
    D_001E10E8[0] = 0x30000026;
    D_001E10E8[1] = (u32)D_001D0070;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0x50000026;
    D_001E10E8 += 4;
}
