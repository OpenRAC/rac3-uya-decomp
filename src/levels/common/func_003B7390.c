#include "common.h"
typedef int u128_3B7390 __attribute__((mode(TI)));
extern s32 D_001DEDD8;
extern u8 *func_004083B0(s32, s32);
u8 *func_003B7390(u128_3B7390 *a0, u128_3B7390 *a1) {
    u8 *p = func_004083B0(7937, 128);
    if (p != 0) {
        u8 *q = *(u8 **)(p + 104);
        p[48] = 255;
        *(u128_3B7390 *)q = *a1;
        *(u128_3B7390 *)(p + 16) = *a0;
        *(s32 *)(q + 16) = D_001DEDD8;
    }
    return p;
}
