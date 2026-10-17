#include "common.h"
extern s32 D_001D673C;
extern f32 func_00405B68(f32, f32);
extern s32 func_00450F18(u8 *, f32);
extern u8 *func_00450B60(u8 *);
extern f32 func_00451EF0(u8 *, u8 *, f32 *, s32);
s32 func_00450FA8(u8 *a0, f32 *a1) {
    u8 *p;
    if (D_001D673C == 0) {
        return func_00450F18(a0, func_00405B68(a1[0], a1[1]));
    }
    p = func_00450B60(a0);
    if (p == 0) {
        return 0;
    }
    if (*(f32 *)(p + 48) < func_00451EF0(a0, p, a1, 0)) {
        return 0;
    }
    return 1;
}
