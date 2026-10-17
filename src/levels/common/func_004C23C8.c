#include "common.h"

extern void func_0012CB88(void *, s16, s32, s32, s32, s32, s32, s32);
extern void func_0011F0A0(s32);
extern void func_0012CE48(void *, s32);
extern void func_0012A9F0(s32, s32);

void func_004C23C8(s32 dst, s32 src, s32 size) {
    u8 buf[112];
    s32 n = (size + 16383) & ~16383;
    s32 s = 0;
    s32 d = 0;

    while (n > 0) {
        func_0012CB88(buf, (src + s) >> 8, 1, 1, 0, 0, 64, 64);
        s += 16384;
        func_0011F0A0(0);
        func_0012CE48(buf, dst + d);
        d += 12288;
        func_0012A9F0(0, 0);
        n -= 16384;
    }
}
