#include "common.h"

/* localdecomp:start func_00432810 */
extern s32 func_00432810();

s32 func_00432768_003997F0(void *, s32);

s32 func_00432810(s32 *arg0) {
    s32 ret = 0;
    s32 v = arg0[1];
    s32 key = arg0[0];

    if (v != 0) {
        ret = func_00432768_003997F0(arg0 + 2, key) == v;
    }
    return ret;
}
/* localdecomp:end func_00432810 */
