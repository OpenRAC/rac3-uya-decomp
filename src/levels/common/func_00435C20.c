#include "common.h"

extern void func_0040BCB8();
extern s32 func_00435C20(u8 *, s32, s32);
extern s32 func_00435A50(u8 *, s32, s32, s32);
extern void func_0040BCB8(u8 *, u8 *, s32);

extern s32 func_00435A50(u8 *, s32, s32, s32);
extern void func_0040BCB8(u8 *, u8 *, s32);
s32 func_00435C20(u8 *p, s32 a, s32 b) {
    s32 r = func_00435A50(p, a, b, 0);
    if (r >= 0) {
        func_0040BCB8(&p[r * 2], &p[r * 2 + 2], (0x5F - r) * 2);
        p[0xBE] = 0;
        return 1;
    }
    return 0;
}
