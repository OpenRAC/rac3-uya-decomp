#include "common.h"

extern s32 func_006748D0(s32, s32);
extern void func_005DCA18(s32, s32);
extern void func_005D9CE8(s32, s32);

void func_00674A90(s32 a0, s32 a1) {
    if (func_006748D0(a0, a1)) {
        func_005DCA18(a0, a1);
    } else {
        func_005D9CE8(a0, a1);
    }
}
