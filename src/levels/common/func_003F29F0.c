#include "common.h"

/* localdecomp:start func_003F29F0 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 D_001E2D60[];
extern u8 D_001E2AC0[];
extern s32 func_003F22B0();
extern s32 func_003F2480();
void func_003F29F0(u8 *o) {
    u8 *e;
    u8 *d;
    s32 r;
    e = D_001E2D60 + *(s32 *)(o + 0x94) * 0x460;
    if (e[2] == 0) {
        r = func_003F22B0(o, e + 0x10);
    } else {
        r = func_003F2480(o, e + 0x70);
    }
    if (r) {
        d = D_001E2AC0 + *(s32 *)(o + 0x94) * 0x460;
        *(u128_t *)(d + 0x380) = *(u128_t *)(o + 0x00);
        *(u128_t *)(d + 0x390) = *(u128_t *)(o + 0x10);
        *(u128_t *)(d + 0x3A0) = *(u128_t *)(o + 0x20);
        *(volatile u128_t *)(d + 0x000) = *(u128_t *)(o + 0x30);
        *(volatile u8 *)(e + 2) = 0;
        *(volatile u16 *)e = 0;
    }
}
/* localdecomp:end func_003F29F0 */
