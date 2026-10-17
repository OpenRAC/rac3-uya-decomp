#include "common.h"
extern void func_003A3D20(u8 *a0, s32 a1);
void func_003A4208(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 104);
    if (*(s32 *)(s0 + 456) == 0) {
        func_003A3D20(a0, 2);
    }
    if (*(s32 *)(s0 + 456) == 1) {
        func_003A3D20(a0, 8);
    }
    if (*(s32 *)(s0 + 456) == 2) {
        func_003A3D20(a0, 9);
    }
}
