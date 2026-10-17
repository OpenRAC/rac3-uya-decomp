#include "common.h"

extern void func_00433EA0(u8 *, u32);
void func_00433EA0(u8 *, u32);

s32 func_00490CF8(s32 *p) {
    s32 v = 1;
    if (p[3] != 0) {
        if (p[4] != 0) {
            func_00433EA0((u8 *)p[3], p[4]);
        }
        v = 2;
    }
    p[0] = v;
    return 1;
}
