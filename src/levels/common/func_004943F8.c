#include "common.h"

/* localdecomp:start func_004943F8 */
f32 func_004943F8(s32 a0, f32 a, f32 b, f32 c) {
    if (a0 == 0) {
        return a - b * 0.5f + c * 0.5f;
    }
    if (a0 == 2) {
        return a + b * 0.5f - c * 0.5f;
    }
    return a;
}
/* localdecomp:end func_004943F8 */
