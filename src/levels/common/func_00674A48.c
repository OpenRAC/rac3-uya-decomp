#include "common.h"
extern s32 func_006748D0(void *a0);
extern void func_005D9B98(void *a0);
extern void func_005DC930(void *a0);
void func_00674A48(void *a0) {
    if (func_006748D0(a0) == 0) {
        func_005D9B98(a0);
    } else {
        func_005DC930(a0);
    }
}
