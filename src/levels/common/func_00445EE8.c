#include "common.h"

/* localdecomp:start func_00445EE8 */
s32 func_00445EE8(u8 *a0) {
    if (a0 == 0) {
        return 0;
    }
    if (*(u16 *)(a0 + 52) & 0x20) {
        return *(s32 *)(*(u8 **)(a0 + 104) + 12);
    }
    return 0;
}
/* localdecomp:end func_00445EE8 */
