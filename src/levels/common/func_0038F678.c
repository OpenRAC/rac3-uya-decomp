#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_00435E70(s32, s32);
u8 *func_0038F678(u128_t *a0, u128_t *a1) {
    u8 *m;
    u8 *p;

    m = func_00435E70(6283, 128);
    if (m != 0) {
        m[32] = 0;
        m[48] = 255;
        p = *(u8 **)(m + 104);
        *(u128_t *)(m + 16) = *a0;
        *(u128_t *)p = *a1;
        *(s32 *)(p + 16) = 30;
        *(s32 *)(p + 20) = 0;
        *(s32 *)(p + 24) = 70;
    }
    return m;
}
