#include "common.h"

/* localdecomp:start func_004EA9A8 */
extern u8 D_001A4BE0[];
extern f32 func_0040BF38(void *);
f32 func_004EA9A8(void) {
    u8 *p = D_001A4BE0;
    f32 a = __builtin_fabsf(*(f32 *)(p + 8800));
    f32 b = __builtin_fabsf(*(f32 *)(p + 8804));
    f32 m;
    f32 r;

    if (b < a) m = a; else m = b;
    r = (m + func_0040BF38(p + 8800)) * 0.5f;
    if (1.0f < r) r = 1.0f;
    return r;
}
/* localdecomp:end func_004EA9A8 */
