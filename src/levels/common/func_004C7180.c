#include "common.h"

/* localdecomp:start func_004C7180 */
s32 func_004C7180(s32 *a0, s32 a1) {
    s32 ret = -1;
    s32 i;
    for (i = 0; i < 64; i++) {
        if (a0[i] == 0) {
            a0[i] = a1;
            ret = i;
            a0[137] = 1;
            a0[136]++;
            a0[i + 64] = 0;
            break;
        }
    }
    return ret;
}
/* localdecomp:end func_004C7180 */
