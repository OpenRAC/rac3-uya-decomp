#include "common.h"

extern void func_00353D40(u8 *a0, u8 *a1);
extern void func_00353F28(u8 *a0, u8 *a1);
extern void func_00353E08(u8 *a0, u8 *a1);

void func_00354048(u8 *a0, u8 *a1) {
    if (*(s32 *)(a1 + 864) != 0) {
        if (a0[67] == 7) {
            func_00353D40(a0, a1);
        } else {
            func_00353F28(a0, a1);
            *(s32 *)(a1 + 864) = 0;
        }
    } else if (a0[67] == 7) {
        func_00353E08(a0, a1);
        *(s32 *)(a1 + 864) = 1;
    }
}
