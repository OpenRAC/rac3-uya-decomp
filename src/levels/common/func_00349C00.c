#include "common.h"
extern u8 *func_00431400(u8 *, s32, s32);
void func_00349C00(u8 *a0) {
    u8 *p = func_00431400(a0, 0x10000, 0);
    if (p != 0) {
        u8 *q = *(u8 **)(p + 32);
        if (q != 0) {
            s16 t = *(s16 *)(q + 170);
            if (t == 208 || t == 2085) {
                a0[188] = 1;
            }
        }
    }
    a0[168] = 255;
}
