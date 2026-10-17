#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_004234F0(s32 a, s32 b);

u8 *func_003B7C98(u8 *a0) {
    u8 *m = func_004234F0(7230, 128);
    if (m != 0) {
        *(u8 *)(m + 48) = 255;
        *(u16 *)(m + 52) &= ~0x80;
        *(s16 *)(m + 50) = 64;
        *(u8 *)(m + 49) = 1;
        *(u8 **)(m + 184) = a0;
        *(u128_t *)(m + 16) = *(u128_t *)(a0 + 16);
        *(u128_t *)(m + 240) = *(u128_t *)(a0 + 240);
    }
    return m;
}
