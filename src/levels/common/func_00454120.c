#include "common.h"

/* localdecomp:start func_00454120 */
s32 func_00454120(s32 n) {
    s32 a = 16;
    if (n % a != 0) {
        n = ((s32)((f32)n / (f32)a) + 1) * a;
    }
    return n;
}
/* localdecomp:end func_00454120 */
