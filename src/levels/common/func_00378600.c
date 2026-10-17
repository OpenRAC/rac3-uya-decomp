#include "common.h"

extern s32 D_001DD9C8[2];

s32 *func_00378600(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 8;
        return D_001DD9C8;
    }
    return 0;
}
