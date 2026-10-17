#include "common.h"

extern u8 *D_0024C05C;
extern void func_005D9EF8(u8 *, s32 *, s32 *);

s32 func_005D9F18(s32 i, s32 *a, s32 *b) {
    s32 r;

    *a = 0;
    r = 0;
    *b = 0;
    if (i >= 0) {
        r = 1;
        func_005D9EF8(D_0024C05C + (i << 8), a, b);
    }
    return r;
}
