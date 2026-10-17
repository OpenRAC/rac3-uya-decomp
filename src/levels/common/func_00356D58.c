#include "common.h"
extern s32 func_00356A68(u8 *a0, u8 *a1);
extern s32 func_00436340(u8 *a0);
extern s32 func_003F0638(s32 *a0);
extern void func_00425278(u8 *a0, s32 a1, s32 a2);
s32 func_00356D58(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 104);
    if (func_00356A68(a0, s0) != 0) {
        return 1;
    }
    if (func_00436340(a0) != 0) {
        *(s32 *)(s0 + 816) = 20;
    }
    if (func_003F0638((s32 *)(s0 + 816)) != 0) {
        func_00425278(a0, 22, -1);
        return 1;
    }
    return 0;
}
