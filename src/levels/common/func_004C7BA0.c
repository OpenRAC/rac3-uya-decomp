#include "common.h"

/* localdecomp:start func_004C7BA0 */
extern int D_001E10E8[];

extern int D_001E10E8[];
extern u32 *D_001E10E8_g;
extern u8 D_001DB090;
void func_004C7BA0(void) {
    ((u32 *)D_001E10E8[0])[0] = 0x30000003;
    ((u32 *)D_001E10E8[0])[1] = (u32)&D_001DB090;
    ((u32 *)D_001E10E8[0])[2] = 0;
    ((u32 *)D_001E10E8[0])[3] = 0x50000003;
    D_001E10E8_g = (u32 *)D_001E10E8[0] + 4;
}
/* localdecomp:end func_004C7BA0 */
