#include "common.h"

extern s32 D_00241298;
extern s32 D_00242A94;
extern void func_00489EF8(s32, s32, s32);

s32 func_003ED458(u8 *a0, s32 a1) {
    s32 id;
    u8 *p;
    s32 v;

    p = *(u8 **)(a0 + 144);
    id = 2250;
    if (a1 != 0) {
        id = 2244;
    }
    if (p != 0) {
        v = p[9417];
        if (v != D_00241298) {
            return 0;
        }
        if (D_00242A94 == 0) {
            func_00489EF8(id, 4, 0);
        } else {
            func_00489EF8(id, 4, v);
        }
    }
    return 0;
}
