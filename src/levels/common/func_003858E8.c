#include "common.h"

/* localdecomp:start func_003858E8 */
extern s32 func_00447CA0(s32);
extern f32 *func_00440728(s32);

s32 func_003858E8(s32 a0) {
    f32 *p;

    if (func_00447CA0(a0)) return 0;
    p = func_00440728(a0);
    if (p == 0) return 0;
    if (*p > 0.0f) return 0;
    return 1;
}
/* localdecomp:end func_003858E8 */
