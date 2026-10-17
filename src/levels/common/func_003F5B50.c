#include "common.h"
s32 func_003F5B50(u8 *a0) {
    s32 r = 1;
    if (*(s16 *)(a0 + 170) == 3262) {
        u8 *p = *(u8 **)(a0 + 104);
        if (*(s32 *)(p + 64) != 0 || *(s32 *)(p + 184) >= 3) r = 0;
    }
    return r;
}
