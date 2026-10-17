#include "common.h"

s32 func_00415FA0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (p[332] == 0) {
        *(s16 *)(p + 334) = 0;
        p[332] = 1;
        return 1;
    }
    return 0;
}
