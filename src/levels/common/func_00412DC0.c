#include "common.h"

/* localdecomp:start func_00412DC0 */
extern void func_00412DC0(void);
extern u32 *D_001E10E8;

extern u32 *D_001E10E8;
extern s32 D_001D4CF8_0038DB98;
void func_00412DC0(void) {
    D_001E10E8[0] = 0x30000009;
    D_001E10E8[1] = (D_001D4CF8_0038DB98 + 0xC0) & 0xFFFFFFF;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0x50000009;
    D_001E10E8 += 4;
}
/* localdecomp:end func_00412DC0 */
