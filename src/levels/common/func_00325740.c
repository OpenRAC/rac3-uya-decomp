#include "common.h"

/* localdecomp:start func_00325740 */
extern u8 *func_00445F18(s32 a0);
s32 func_00325740(s32 a0, u8 *a1, s32 a2) {
    s32 x = *(s32 *)(a1 + 96);
    while (x) {
        if (x == a2) {
            return 1;
        }
        x = *(s32 *)(func_00445F18(x) + 4);
    }
    return 0;
}
/* localdecomp:end func_00325740 */
