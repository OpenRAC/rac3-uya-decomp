#include "common.h"

/* localdecomp:start func_004DAA10 */
extern u32 *D_001E10E8;
extern s32 D_001D55F4;
extern u8 D_001D2A50[];
extern s32 D_001DBCE4;

void func_004DAA10(void) {
    D_001E10E8[0] = (D_001D55F4 >> 4) | 0x30000000;
    D_001E10E8[1] = (u32)D_001D2A50;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = (D_001D55F4 >> 4) | 0x50000000;
    D_001DBCE4 = 0;
    D_001E10E8 = D_001E10E8 + 4;
}
/* localdecomp:end func_004DAA10 */
