#include "common.h"

/* localdecomp:start func_004365E0 */
f32 func_004365E0(u8 *a0) {
    f32 t = *(f32 *)(a0 + 36);
    u8 *a = *(u8 **)(a0 + 56);
    u8 *b;
    if (t == 0.0f) {
        return *(s16 *)(a + 4) * 0.0625f;
    }
    if (a0[34] != a0[35] || a0[32] > a0[33]) {
        return *(s16 *)(a + 4) * 0.0625f + t;
    }
    b = *(u8 **)(a0 + 60);
    return (*(s16 *)(a + 4) * (1.0f - t) + *(s16 *)(b + 4) * t) * 0.0625f;
}
/* localdecomp:end func_004365E0 */
