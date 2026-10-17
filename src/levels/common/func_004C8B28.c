#include "common.h"

void func_004C8B28(void *a0, s32 a1) {
    s32 *v0 = *(s32 **)((u8 *)a0 + 0x10);
    if (a1 != 0) {
        *(f32 *)v0 = 1.0f;
    } else {
        *v0 = 0;
    }
}
