#include "common.h"

/* localdecomp:start func_00435A50 */
s32 func_00435A50(u8 *p, s32 a, s32 b, s32 i) {
    for (; i < 0x60; i++) {
        if (p[i * 2] - 1 == a && p[i * 2 + 1] == b) return i;
    }
    return -1;
}
/* localdecomp:end func_00435A50 */
