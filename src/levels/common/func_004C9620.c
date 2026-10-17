#include "common.h"

void func_004C9620(u8 *p, s32 a, s32 b) {
    (*(f32 **)(p + 0x28))[0] = a;
    (*(f32 **)(p + 0x28))[1] = b;
}
