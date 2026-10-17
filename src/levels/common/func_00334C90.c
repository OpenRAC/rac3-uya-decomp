#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern void func_00333D30(void *, void *, f32);

s32 func_00334C90(void *a, u8 *b, u8 *c, u8 *d) {
    u8 *t = *(u8 **)(d + 0xC0);

    *(u8 **)(d + 0x440) = t;
    *(u128_t *)(d + 0x400) = *(u128_t *)(t + 0x10);
    *(u128_t *)(d + 0x3F0) = *(u128_t *)(t + 0x10);
    *(u128_t *)(d + 0x410) = *(u128_t *)(t + 0x10);
    func_00333D30(c, d, 12.0f);
    *(u128_t *)(b + 0x80) = *(u128_t *)(c + 0x10);
    *(u128_t *)(d + 0x4A0) = *(u128_t *)(d + 0x400);
    return 0;
}
