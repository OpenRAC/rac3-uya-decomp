#include "common.h"

/* localdecomp:start func_00472BE8 */
s32 func_00472BE8(s32 *p, s32 a, s32 b, s32 wrap) {
    if (wrap) {
        a = (a + b + *p) % *p;
    } else {
        a += b;
        if (b < 0) {
            if (a < 0) {
                a = 0;
            }
        } else {
            if (a > *p - 1) {
                a = *p - 1;
            }
        }
    }
    return a;
}
/* localdecomp:end func_00472BE8 */
