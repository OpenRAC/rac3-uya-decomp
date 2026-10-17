#include "common.h"
extern f32 D_001DFC14;
extern f32 func_0058F4B0(u8 *, u8 *);
s32 func_00558E60(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a0 + 104);
    u8 *e;
    s32 i;
    if (a1 == 0) {
        return 0;
    }
    for (i = 0; i < *(s32 *)s; i++) {
        e = ((u8 **)(s + 16))[i];
        if (e != 0 && e != a1 && func_0058F4B0(e + 16, a1 + 16) < D_001DFC14) {
            return 1;
        }
    }
    return 0;
}
