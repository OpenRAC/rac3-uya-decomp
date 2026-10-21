#include "common.h"

/* localdecomp:start func_005140D0 */
extern s32 func_005140D0(s32, s32, s32);
extern s32 func_005139B0(s32, s32);

s32 func_005139B0(s32, s32);
s32 func_005140D0(s32 a, s32 b, s32 c) {
    s32 x = func_005139B0(a, b) != 0;
    s32 y = func_005139B0(a, c) != 0;
    return x & y;
}
/* localdecomp:end func_005140D0 */
