#include "common.h"

extern s32 func_00436340(u8 *);
extern s32 func_00350528(u8 *, u8 *);
extern void func_00425278(u8 *, s32, s32);
extern void func_00350C38(u8 *, u8 *, s32, s32, s32);

s32 func_00356740(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    s32 ret;
    if (func_00436340(a0)) {
        func_00350C38(a0, s1, 12, 0, 10);
    }
    func_00350528(a0, s1);
    if ((a0[96] & 2) == 0) {
        ret = 0;
    } else {
        *(s32 *)(s1 + 900) = 0;
        func_00425278(a0, 3, -1);
        func_00350C38(a0, s1, 2, 0, 10);
        ret = 1;
    }
    return ret;
}
