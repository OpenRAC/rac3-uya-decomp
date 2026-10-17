#include "common.h"
s32 func_005D9940(s32 *a0, s32 a1, s32 a2) {
    s32 r = 0;
    s32 v = a0[0];
    if ((v ^ 2) == 0) goto set;
    if ((v ^ 1) != 0) goto out;
set:
    a0[3] = a1;
    r = 1;
    a0[4] = a2;
out:
    return r;
}
