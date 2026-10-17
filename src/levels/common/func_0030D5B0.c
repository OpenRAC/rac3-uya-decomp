#include "common.h"

extern s32 func_004345D0(s32, s32, s32);

s32 func_0030D5B0(u8 *a0, s32 a1) {
    return func_004345D0(a1, *(s32 *)(*(u8 **)(a0 + 104) + 112), 0) != 0;
}
