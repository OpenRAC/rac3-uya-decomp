#include "common.h"
extern void func_00445BF0(s32 *r, s32 *g, s32 *b, s32 a3);
u32 func_00445C50(u32 c, s32 a1) {
    s32 r;
    s32 g;
    s32 b;
    u32 a;
    if (a1 == 0) {
        return c;
    }
    r = c & 0xff;
    g = (s32)(c & 0xff00) >> 8;
    b = (c >> 16) & 0xff;
    a = c >> 24;
    func_00445BF0(&r, &g, &b, a1);
    return (a << 24) | (b << 16) | (g << 8) | r;
}
