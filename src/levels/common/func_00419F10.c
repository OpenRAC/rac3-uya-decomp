#include "common.h"

/* localdecomp:start func_00419F10 */
extern u32 D_001D68B0;
u32 func_00419F10(void) {
    u32 v = D_001D68B0;
    u32 r = 0;
    if (v <= 0x1CFFFF) r = (0x1D0000 - v) >> 2;
    return r;
}
/* localdecomp:end func_00419F10 */
