#include "common.h"

/* localdecomp:start func_00413138 */
extern void func_00413138(s32);
extern u32 *D_001E10E8;

extern u32 *D_001E10E8;
extern u8 D_001D9E30[];
extern u8 D_001D9E50[];
extern u8 D_001D02D0[];
extern u8 D_001D9DC0[];
void func_00413138(s32 a0) {
    D_001E10E8[0] = 0x30000002;
    if (a0 != 0) {
        D_001E10E8[1] = (u32)D_001D9E30;
    } else {
        D_001E10E8[1] = (u32)D_001D9E50;
    }
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0x50000002;
    D_001E10E8 += 4;
    D_001E10E8[0] = 0x30000029;
    D_001E10E8[1] = (u32)D_001D02D0;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0x50000029;
    D_001E10E8 += 4;
    D_001E10E8[0] = 0x30000003;
    D_001E10E8[1] = (u32)D_001D9DC0;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0x50000003;
    D_001E10E8 += 4;
}
/* localdecomp:end func_00413138 */
