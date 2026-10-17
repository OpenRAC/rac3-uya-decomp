#include "common.h"
extern void func_00424F38(u8 *, s32, s32, s32);
void func_00350CA8(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    if (a0[67] != a2) {
        func_00424F38(a0, a2, a3, a4);
    }
}
