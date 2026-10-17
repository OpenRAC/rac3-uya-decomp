#include "common.h"
s32 func_004202B0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 **p;
    u8 *q;
    s32 i;

    for (i = 0; i < *(s32 *)(v + 1128); i++) {
        p = (u8 **)(v + 784) + i;
        q = p[6];
        if (q == 0 || q[49] == 0 || (q = *(u8 **)(q + 28)) == 0 || *(s16 *)(q + 170) != 6683 || q != p[0]) {
            return i;
        }
    }
    return -1;
}
