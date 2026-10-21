#include "common.h"

/* localdecomp:start func_00452EC8 */
s32 func_00452EC8(u8 *a0) {
    u8 v = *(u8 *)(a0 + 190);
    if (((v ^ 1) & 1) != 0) {
        *(u8 *)(a0 + 190) = v | 1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00452EC8 */
