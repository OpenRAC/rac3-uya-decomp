#include "common.h"
s32 func_003B4710(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 r = 0;
    if (*(s32 *)(p + 68) != 0) {
        r = *(s32 *)(p + 72) != 0;
    }
    return r;
}
