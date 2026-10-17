#include "common.h"
extern u8 *func_003252E8(void);
extern s32 func_003291E0(void *, s32);
extern s32 func_003292A8(void *, s32);
extern void func_004A7368(s32, s32, s32);
extern void func_00441FB8(void *, s32, s32);
s32 func_00327740(void) {
    u8 *m = func_003252E8();
    s32 v = *(s32 *)(m + 104);
    if (func_003291E0(m, v)) {
        func_004A7368(20, 0, 0);
        func_00441FB8(m, 8, -1);
        return 1;
    }
    if (func_003292A8(m, v)) {
        func_00441FB8(m, 5, -1);
        return 1;
    }
    return 0;
}
