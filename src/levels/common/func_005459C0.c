#include "common.h"
s32 func_005459C0(s32 a0) {
    s32 p = *(s32 *)(*(s32 *)(*(s32 *)(a0 + 104) + 900) + 728);
    s32 r = 0;
    if (p != 0) {
        r = *(u8 *)(p + 6676) != 0;
    }
    return r;
}
