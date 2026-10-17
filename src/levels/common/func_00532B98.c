#include "common.h"

extern void func_005FBBC0(f32, u8 *, u8 *, s32, s32);

void func_00532B98(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 356) != 0) {
        func_005FBBC0(1.0f, p + 288, p + 304, 0, 1);
    }
}
