#include "common.h"

extern u8 D_001426E0[];
extern s32 func_0044F4C8(void);

s32 func_0044F428(s32 n) {
    s32 max = func_0044F4C8();
    s32 v = D_001426E0[69] + n;
    if (max < v) {
        return 0;
    }
    D_001426E0[69] = v;
    return 1;
}
