#include "common.h"

extern s32 D_00142C4C[];
s32 func_00434F28(void) {
    s32 v = D_00142C4C[0] & 0x4000;
    return v != 0;
}
