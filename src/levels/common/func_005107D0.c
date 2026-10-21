#include "common.h"

/* localdecomp:start func_005107D0 */
extern u8 D_001427AB[];
s32 func_005107D0(s32 a0) {
    s32 r;
    if (a0 == -1) a0 = 0;
    r = 0;
    if ((u32)a0 < 256) {
        r = 1;
        D_001427AB[0] = a0;
    }
    return r;
}
/* localdecomp:end func_005107D0 */
