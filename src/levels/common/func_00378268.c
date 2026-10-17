#include "common.h"

extern void func_00441FB8(u8 *, s32, s32);

void func_00378268(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (p != 0) {
        *(s32 *)(p + 20) = 0;
    }
    func_00441FB8(a0, 5, -1);
}
