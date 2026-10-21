#include "common.h"

/* localdecomp:start func_00445F18 */
s32 func_00445F18(u8 *a0) {
    if (a0 == 0) {
        return 0;
    }
    if (*(u16 *)(a0 + 52) & 0x20) {
        return *(s32 *)(*(u8 **)(a0 + 104) + 44);
    }
    return 0;
}
/* localdecomp:end func_00445F18 */
