#include "common.h"
extern s32 func_0053ED70(s32, s32, s32, s32);
extern void func_00532320(s32, u8 *, s32);
void func_0042F678(s32 a0, s32 a1, u8 a2) {
    u8 buf[4];
    s32 h = func_0053ED70(a0, 1, 0, 0);
    buf[0] = a1;
    func_00532320(h, buf, 1);
    buf[0] = a2;
    func_00532320(h, buf, 1);
}
