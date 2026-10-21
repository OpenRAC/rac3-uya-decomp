#include "common.h"

/* localdecomp:start func_004C21C0 */
extern u32 *D_001E10E8;
extern u8 D_001DA2F0[];
void func_004C21C0(void) {
    D_001E10E8[0] = 0x30000003;
    D_001E10E8[1] = (u32)D_001DA2F0;
    D_001E10E8[2] = 0;
    D_001E10E8[3] = 0x50000003;
    D_001E10E8 += 4;
}
/* localdecomp:end func_004C21C0 */
