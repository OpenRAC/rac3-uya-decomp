#include "common.h"

extern s32 D_00241298;
extern void func_005FBBC0(u8 *, u8 *, s32, s32, f32);

void func_00549FC0(u8 *m) {
    u8 *p;
    u8 *q;

    if (m == 0) {
        return;
    }
    if (m[32] == 254) {
        return;
    }
    if (m[32] == 253) {
        return;
    }
    p = *(u8 **)(m + 104);
    if (p == 0) {
        return;
    }
    q = *(u8 **)(p + 64);
    if (q == 0) {
        return;
    }
    if (q[9417] != D_00241298) {
        return;
    }
    if (*(s32 *)(p + 52) == 0) {
        return;
    }
    func_005FBBC0(p, p + 16, 0, 1, 1.0f);
}
