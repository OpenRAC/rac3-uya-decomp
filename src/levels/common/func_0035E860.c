#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_001E9158[];
extern void func_00422218(u8 *a0, s32 a1, u8 *a2);
extern s32 func_003E2E48(u8 *a0, u128_t *a1, s32 a2, u8 *a3, s32 t0);
s32 func_0035E860(u8 *a0) {
    u8 buf[16];
    u128_t q;
    u8 *s1;
    s32 d;
    s1 = *(u8 **)(a0 + 104);
    func_00422218(a0, 0, buf);
    q = *(u128_t *)(s1 + 544);
    if (func_003E2E48(buf, &q, 16, a0, 0) == 0) {
        return 1;
    }
    d = D_001E9158[0];
    if (d != 0) {
        if (d == *(s32 *)(s1 + 560)) {
            return 1;
        }
    }
    return 0;
}
