#include "common.h"
extern s32 func_00452F60(u8 *);
extern void func_00452F40(u8 *, s32);
void func_003B4A50(u8 *a0, u8 *a1, s32 a2) {
    u8 *s = *(u8 **)(a0 + 104);
    s32 r;
    u8 x, y;
    if (*(s16 *)(a1 + 170) == *(s32 *)s) {
        r = func_00452F60(a1);
        x = a2 != 0;
        y = r == 0;
        x ^= y;
        if (!x) {
            if (r != 0) {
                *(s32 *)(s + 76) -= 1;
            } else {
                *(s32 *)(s + 76) += 1;
            }
            func_00452F40(a1, a2);
        }
    }
}
