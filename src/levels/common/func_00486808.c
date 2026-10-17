#include "common.h"

extern s32 D_001D8A98;

s32 func_00486808(s32 a0) {
    s32 ret = 0;
    if (D_001D8A98 == 0) {
        D_001D8A98 = a0;
        ret = 1;
    }
    return ret;
}
