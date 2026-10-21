#include "common.h"

/* localdecomp:start func_004CB6E0 */
f32 func_004CB6E0(u8 *a0) {
    f32 f = *(f32 *)(a0 + 24);
    *(s32 *)(a0 + 24) = 0;
    a0[40] = 1;
    return f;
}
/* localdecomp:end func_004CB6E0 */
