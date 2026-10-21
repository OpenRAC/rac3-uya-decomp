#include "common.h"

/* localdecomp:start func_004335E8 */
extern u8 *D_001D67C8;
extern s32 func_004CAA60(u8 *, s32);

s32 func_004335E8(s32 a0) {
    u8 *p = D_001D67C8;
    if (p != 0) {
        return func_004CAA60(p + 0x1FCA8, a0);
    }
    return 0;
}
/* localdecomp:end func_004335E8 */
