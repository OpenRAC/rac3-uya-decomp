#include "common.h"

/* localdecomp:start func_004EAA20 */
extern u8 D_001A4BE0[];
s32 func_004EAA20(f32 a) {
    u8 *b = D_001A4BE0;
    f32 t = *(f32 *)(b + 3096);
    if (a < t) {
        if (t - a <= *(f32 *)(b + 3100)) return 1;
    }
    return 0;
}
/* localdecomp:end func_004EAA20 */
