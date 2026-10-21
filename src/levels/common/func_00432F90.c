#include "common.h"

/* localdecomp:start func_00432F90 */
extern u8 D_001426E0[];

s32 func_00432F90(s32 a0) {
    return D_001426E0[(a0 >> 3) + 195] & (1 << (a0 & 7));
}
/* localdecomp:end func_00432F90 */
