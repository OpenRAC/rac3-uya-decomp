#include "common.h"

extern s32 func_0044F528(s32);

s32 func_0044F4C8(void) {
    s32 i;
    s32 sum = 0;
    for (i = 0; i < 37; i++) {
        sum += func_0044F528(i);
    }
    if (sum < 0) {
        sum = 0;
    }
    if (sum > 40) {
        sum = 40;
    }
    return sum;
}
