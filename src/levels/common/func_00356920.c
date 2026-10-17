#include "common.h"

extern s32 func_00436340(void *);
extern void func_00350C38(void *, void *, s32, s32, s32);
extern void func_00425278(void *, s32, s32);

s32 func_00356920(u8 *arg0) {
    u8 *s = *(u8 **)(arg0 + 104);

    if (func_00436340(arg0)) {
        *(s32 *)(s + 636) = -*(s32 *)(s + 636);
        func_00350C38(arg0, s, 3, 0, 10);
    }
    if (arg0[96] & 2) {
        func_00425278(arg0, 1, -1);
        func_00350C38(arg0, s, 2, 0, 10);
        return 1;
    }
    return 0;
}
