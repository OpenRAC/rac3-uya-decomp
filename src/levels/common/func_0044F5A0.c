#include "common.h"

/* localdecomp:start func_0044F5A0 */
extern u8 D_001D54B0[];

s32 func_0044F5A0(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (D_001D54B0[i] != 0) {
            n++;
        }
    }
    if (n < 0) {
        n = 0;
    }
    if (n > 30) {
        n = 30;
    }
    return n;
}
/* localdecomp:end func_0044F5A0 */
