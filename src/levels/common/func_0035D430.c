#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_001EA758[];
extern void func_004305D8(u8 *a0, s32 a1, u8 *a2);
extern s32 func_003F1D60(u8 *a0, u128_t *a1, s32 a2, u8 *a3, s32 t0);
s32 func_0035D430(u8 *a0) {
    u8 buf[16];
    u128_t q;
    u8 *s1;
    s32 d;
    s1 = *(u8 **)(a0 + 104);
    func_004305D8(a0, 6, buf);
    q = *(u128_t *)(s1 + 544);
    if (func_003F1D60(buf, &q, 16, a0, 0) == 0) {
        return 1;
    }
    d = D_001EA758[0];
    if (d != 0) {
        if (d == *(s32 *)(s1 + 560)) {
            return 1;
        }
    }
    return 0;
}
