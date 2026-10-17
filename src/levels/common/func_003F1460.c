#include "common.h"
typedef int u128_3F1460 __attribute__((mode(TI)));
extern s32 func_0044D2E0(void *a0, s32 a1, u8 *a2, f32 f12);
s32 func_003F1460(u8 *a0, u128_3F1460 *a1) {
    u128_3F1460 tmp = *a1;
    u8 *p = *(u8 **)(a0 + 104);
    ((f32 *)&tmp)[2] += *(f32 *)(p + 116) + *(f32 *)(p + 112);
    return func_0044D2E0(&tmp, 16, a0, *(f32 *)(p + 112)) == 0;
}
