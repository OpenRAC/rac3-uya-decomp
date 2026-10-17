#include "common.h"
extern u8 *func_005E5A88(u8 *a0, s32 a1, s32 a2);
void func_005E5AE8(u8 *a0, s32 a1, s32 a2) {
    s32 i;
    for (i = 0; i < *(s32 *)(a0 + 20); i++) {
        *(s32 *)(func_005E5A88(a0, i, a1) + 32) = a2;
    }
}
