#include "common.h"

extern s32 func_0041D880(s32, s32);
s32 func_004908F0(u8 *p, s32 a, s32 b) {
    s32 r = func_0041D880(a, b);
    *(s32 *)(p + 8) = r;
    return r != 0;
}
