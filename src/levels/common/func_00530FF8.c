#include "common.h"
s32 func_00530FF8(s32 a0) {
    s32 p = *(s32 *)(*(s32 *)(*(s32 *)(a0 + 104) + 1744) + 728);
    s32 r = 0;
    if (p != 0) {
        r = *(u8 *)(p + 6676) != 0;
    }
    return r;
}
