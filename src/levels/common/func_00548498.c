#include "common.h"

extern void func_00619D58(u8 *, u8 **);
extern u32 func_0061B008(s32);

void func_00548498(u8 *self, u8 *msg) {
    u8 *v;
    u8 *p;
    f32 *src;
    f32 *dst;

    if (msg[3] != 8) {
        return;
    }
    v = *(u8 **)(self + 104);
    p = *(u8 **)(v + 80);
    if (p == 0) {
        func_00619D58(self, (u8 **)(v + 80));
        p = *(u8 **)(*(u8 **)(self + 104) + 80);
        if (p == 0) {
            return;
        }
    }
    src = (f32 *)(p + 944);
    dst = (f32 *)(msg + 24);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    if (*(s32 *)(p + 4216) != 0) {
        *(u32 *)(msg + 8) = func_0061B008(*(s32 *)(p + 4216));
    } else {
        *(u32 *)(msg + 8) = 0xFFFFFFFF;
    }
}
