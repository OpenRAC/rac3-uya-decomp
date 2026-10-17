#include "common.h"

extern s32 func_0061AA60(s32);

s32 func_00646218(u8 *a0) {
    s32 r;
    if (a0 == 0) {
        r = 0;
    } else {
        r = func_0061AA60(*(s32 *)(a0 + 144));
    }
    return r;
}
