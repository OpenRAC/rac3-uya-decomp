#include "common.h"

/* localdecomp:start func_00412D40 */
extern void func_00412D40(s32);
extern u32 *D_001E10E8;

extern u32 *D_001E10E8;
extern u8 D_001D07B0[], D_001D0900[];
void func_00412D40(s32 a) {
    if (D_001E10E8 != 0) {
        D_001E10E8[0] = 0x30000015;
        if (a == 0) D_001E10E8[1] = (u32)D_001D07B0;
        else D_001E10E8[1] = (u32)D_001D0900;
        D_001E10E8[2] = 0;
        D_001E10E8[3] = 0x50000015;
        D_001E10E8 += 4;
    }
}
/* localdecomp:end func_00412D40 */
