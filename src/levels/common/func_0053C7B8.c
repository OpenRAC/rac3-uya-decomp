#include "common.h"
s32 func_0053C7B8(s32 a0, s32 a1, s32 a2) {
    s32 p = *(s32 *)(a0 + 144);
    if (p != 0) {
        *(s32 *)(p + 64) = a2;
        *(s32 *)(p + 60) = a1;
        *(u8 *)(p + 48) = 0;
        return 1;
    }
    return 0;
}
