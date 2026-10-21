#include "common.h"

/* localdecomp:start func_00445E80 */
s32 func_00445E80(u8 *p) {
    s32 *q;
    if (p == 0 || (q = *(s32 **)(p + 0x68)) == 0 || !(*(u16 *)(p + 0x34) & 0x20)) {
        return 0;
    }
    return q[5];
}
/* localdecomp:end func_00445E80 */
