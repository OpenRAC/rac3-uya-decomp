#include "common.h"
extern s32 func_00350698(u8 *a0, s32 a1);
extern void func_00425278(u8 *a0, s32 a1, s32 a2);
extern void func_00350C38(u8 *a0, s32 a1, s32 a2, s32 a3, s32 t0);
s32 func_003540C0(u8 *a0) {
    s32 s1 = *(s32 *)(a0 + 104);
    if (func_00350698(a0, s1) != 0 || a0[32] == 2) {
        func_00425278(a0, 1, 1);
        func_00350C38(a0, s1, 1, 0, 10);
        return 1;
    }
    return 0;
}
