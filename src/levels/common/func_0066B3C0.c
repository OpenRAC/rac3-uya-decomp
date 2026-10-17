#include "common.h"
extern s32 func_0061B038(s32);
extern s32 func_0065FCD0(s32, s32, s32, s32);
s32 func_0066B3C0(s32 x, s32 a, s32 b, s32 c) {
    s32 p = func_0061B038(x);
    s32 r;
    if (p == 0) {
        r = 0;
    } else {
        r = func_0065FCD0(p, a, b, c);
    }
    return r;
}
