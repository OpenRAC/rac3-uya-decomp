#include "common.h"

/* localdecomp:start func_00442D70 */
s32 func_00442D70(s32 *a0, s32 a1) {
    s32 v = *a0;
    s32 n = (v >> 24) - a1;
    if (n < 0) {
        n = 0;
    }
    *a0 = (v & 0xFFFFFF) | (n << 24);
    return n == 0;
}
/* localdecomp:end func_00442D70 */
