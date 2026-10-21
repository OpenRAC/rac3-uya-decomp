#include "common.h"

/* localdecomp:start func_004C2280 */
extern void func_004C2280(void);
extern u32 *D_001E10E8_g;

extern u32 *D_001E10E8_g;
extern u8 D_001D9DF0[];
void func_004C2280(void) {
    D_001E10E8_g[0] = 0x30000004;
    D_001E10E8_g[1] = (u32)D_001D9DF0;
    D_001E10E8_g[2] = 0;
    D_001E10E8_g[3] = 0x50000004;
    D_001E10E8_g += 4;
}
/* localdecomp:end func_004C2280 */
