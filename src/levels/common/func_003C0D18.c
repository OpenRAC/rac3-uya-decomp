#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 *D_001DEF84[];
extern void func_003A7318(s32, u128_t *, u128_t *, s32);

void func_003C0D18(u8 *a0) {
    u128_t out;
    u128_t tmp;
    u8 *s = *(u8 **)(D_001DEF84[0] + *(s16 *)(a0 + 132) * 32 + 28);

    tmp = *(u128_t *)(a0 + 48);
    func_003A7318(*(s32 *)(s + 252), &out, &tmp, *(s32 *)(s + 36));
    *(u128_t *)(a0 + 48) = out;
}
