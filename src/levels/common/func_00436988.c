#include "common.h"

/* localdecomp:start func_00436988 */
s32 func_00436988(u8 *a0, u8 *a1) {
    u8 *t = *(u8 **)(a0 + 36);
    s16 n = *(s16 *)(t + 46);
    u8 *p;
    if (n == 0) {
        return 0;
    }
    p = a1 + ((u32)t + (n << 4));
    return p[1] != 0xff;
}
/* localdecomp:end func_00436988 */
