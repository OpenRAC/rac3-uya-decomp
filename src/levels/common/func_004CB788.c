#include "common.h"

void func_004CB788(u8 *state, s32 mode) {
    *(s32 *)(state + 0x1C) = mode;
    if (state[0x28] == 0) {
        if (mode == 1) *(f32 *)(state + 0x18) = 0.0f;
        else *(f32 *)(state + 0x18) = 1.0f;
        state[0x28] = 1;
    }
}
