#include "common.h"

extern f32 D_001DD058;

s32 func_00348770(u8 *a0, u8 *a1) {
    if (*(f32 *)(a1 + 8) < *(f32 *)(a0 + 24) + D_001DD058) {
        return 1;
    }
    return 0;
}
