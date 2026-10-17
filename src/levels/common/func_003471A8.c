#include "common.h"
extern s32 D_001DF3C0[];
s32 func_003471A8(s32 a0, s32 a1, s32 a2, s32 *a3) {
    s32 t = D_001DF3C0[0];
    s32 v = t + a0 - a1;
    s32 w;
    if (a0 <= 0 || a2 <= 0) {
        return 0;
    }
    w = -a0;
    if (a3 != 0) {
        w = *a3;
    }
    if (v % a0 < a2 && w + a2 < t) {
        if (a3 != 0) {
            *a3 = t;
        }
        return 1;
    }
    return 0;
}
