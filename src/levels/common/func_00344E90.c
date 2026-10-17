#include "common.h"
extern s32 func_0041D798(u8 *);
extern void func_00475198(s32, s32, u8 *);
void func_00344E90(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    if (a0[32] == 19 && v[440] == 0 && func_0041D798(a0) && *(s16 *)(a0 + 170) == 5957) {
        func_00475198(0, 0, a0);
    }
}
