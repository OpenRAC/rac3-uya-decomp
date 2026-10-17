#include "common.h"

extern f32 func_0058F3C0();

s32 func_00558308(void) {
    if (func_0058F3C0() < 0.0f) {
        return 1;
    }
    return -1;
}
