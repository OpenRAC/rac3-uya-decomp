#include "common.h"
extern s32 func_00421C10(u8 *a0);
extern s32 func_00421C90(u8 *a0);
extern s32 func_00421C70(u8 *a0);
extern void func_00474F30(u8 *a0);
extern void func_003DAE40(u8 *a0);
void func_00421CA0(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    u8 *p;
    if (*(u8 **)(s1 + 120) != 0) {
        if (func_00421C10(a0) || func_00421C90(a0) || func_00421C70(a0)) {
            func_00474F30(*(u8 **)(s1 + 120));
            *(u8 **)(s1 + 120) = 0;
        } else {
            p = *(u8 **)(s1 + 120);
            if (*(s16 *)(p + 170) == 6899) {
                func_003DAE40(p);
            }
            *(u8 **)(s1 + 120) = 0;
        }
    }
}
