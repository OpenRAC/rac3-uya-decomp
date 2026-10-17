#include "common.h"

extern s32 func_00423BE8(s32, s32);

void func_00351678(void *self, u8 *obj) {
    s32 v;
    *(s32 *)(obj + 896) = -1;
    v = func_00423BE8(4, 6) * 2;
    *(s32 *)(obj + 860) = v;
    *(s32 *)(obj + 908) = v;
}
