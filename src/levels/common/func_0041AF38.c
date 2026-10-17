#include "common.h"

extern s32 D_001A5F78[];
extern u8 *func_0053ED70(u8 *, s32, s32, s32);
extern void func_00532320(u8 *, void *, s32);

void func_0041AF38(u8 *a, s32 v) {
    s32 buf[2];
    u8 *h;

    if (v == -1) {
        h = func_0053ED70(a, 1, 0, 250);
    } else {
        h = func_0053ED70(a, 1, 0, -1);
    }
    buf[0] = v;
    func_00532320(h, &buf[0], 4);
    buf[1] = D_001A5F78[0];
    func_00532320(h, &buf[1], 4);
}
