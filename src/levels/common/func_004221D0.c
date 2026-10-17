#include "common.h"

extern s32 func_0053ED70(s32, s32, s32, s32);
extern void func_00532320(s32, s32 *, s32);

void func_004221D0(s32 a, s32 b) {
    s32 buf[4];
    s32 h = func_0053ED70(a, 1, 0, 250);
    buf[0] = b;
    func_00532320(h, buf, 4);
}
