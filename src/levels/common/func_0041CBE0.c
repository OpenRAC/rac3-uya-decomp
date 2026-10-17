#include "common.h"
extern s32 func_0053ED70(s32, s32, s32, s32);
extern void func_00532320(s32, s32 *, s32);
void func_0041CBE0(s32 a0, s32 a1, s32 a2) {
    s32 buf[2];
    s32 h = func_0053ED70(a0, 0, 0, 250);
    buf[0] = a1;
    func_00532320(h, &buf[0], 4);
    buf[1] = a2;
    func_00532320(h, &buf[1], 4);
}
