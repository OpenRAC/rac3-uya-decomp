#include "common.h"
s32 func_00354AF8(u8 *a0) {
    s32 r = 0;
    if ((u32)(a0[66] - 18) < 2 || a0[67] == 19 || a0[67] == 18) {
        if (a0[66] != 20) {
            r = a0[67] != 20;
        }
    }
    return r;
}
