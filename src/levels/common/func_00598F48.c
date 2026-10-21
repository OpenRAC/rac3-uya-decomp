#include "common.h"

/* localdecomp:start func_00598F48 */
extern s32 D_0024CBD8;
extern s32 D_0025F78C[];
s32 func_00598F48(u32 a, s32 *out) {
    if (a > 0x40000) {
        *out = 0;
        return -1;
    }
    *out = D_0025F78C[0] + D_0024CBD8 - a;
    return 0;
}
/* localdecomp:end func_00598F48 */
