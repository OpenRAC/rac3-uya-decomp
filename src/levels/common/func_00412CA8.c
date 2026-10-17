#include "common.h"

extern void func_00412CA8(void);

extern u32 *D_001E10E8;
extern s32 D_001D4CF8_0038DA80; 
extern void func_0012C820(s32);

void func_00412CA8(void) {
    if (D_001E10E8 != 0) {
        D_001E10E8[0] = 0x30000009;
        D_001E10E8[1] = (D_001D4CF8_0038DA80 + 0x30) & 0xFFFFFFF;
        D_001E10E8[2] = 0;
        D_001E10E8[3] = 0x50000009;
        D_001E10E8 += 4;
    } else {
        func_0012C820(D_001D4CF8_0038DA80 + 0x30);
    }
}
