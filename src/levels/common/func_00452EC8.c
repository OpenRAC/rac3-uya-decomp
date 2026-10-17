#include "common.h"

s32 func_00452EC8(u8 *a0) {
    u8 v = a0[190];
    if (!(v & 1)) {
        a0[190] = v | 1;
        return 1;
    }
    return 0;
}
