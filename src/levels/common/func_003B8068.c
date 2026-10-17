#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern void func_003F9858(u8 *, u8 *);

void func_003B8068(u8 *a0) {
    u8 **p = *(u8 ***)(a0 + 104);
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (*p != 0) {
            *(f32 *)(*p + 240) = *(f32 *)(a0 + 240);
            *(u128_t *)(*p + 16) = *(u128_t *)(a0 + 16);
            func_003F9858(*p + 192, *p + 240);
        }
        p++;
    }
}
