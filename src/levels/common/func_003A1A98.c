#include "common.h"
s32 func_003A1A98(u8 *a0) {
    s32 r = 0;
    if (a0[3] & 0x80) {
        r = *(s32 *)(a0 + 92) == 0;
    }
    return r;
}
