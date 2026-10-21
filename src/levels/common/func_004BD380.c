#include "common.h"

/* localdecomp:start func_004BD380 */
extern u8 D_001426E0[];
extern s32 func_004BD328(s32 a0);
void func_004BD380(s32 a0, s32 a1) {
    s32 i = func_004BD328(a0);
    if (i >= 0) D_001426E0[i] |= 1 << a1;
}
/* localdecomp:end func_004BD380 */
