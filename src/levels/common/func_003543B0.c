#include "common.h"
extern void func_00425278(u8 *a0, s32 a1, s32 a2);
extern void func_00350C38(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 t0);
s32 func_003543B0(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    f32 f;
    if (a0[96] & 2) {
        func_00425278(a0, 1, 0);
        func_00350C38(a0, s1, 0, 0, 0);
        f = (*(f32 *)(s1 + 788) + *(f32 *)(s1 + 796)) * 0.5f;
        if (*(f32 *)(s1 + 616) < f) {
            *(f32 *)(s1 + 616) = f;
        }
        return 1;
    }
    return 0;
}
