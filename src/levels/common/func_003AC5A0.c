#include "common.h"

/* localdecomp:start func_003AC5A0 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_00445F18(u8 *a0);
extern void func_0040C638(u8 *a0, u8 *a1);
void func_003AC5A0(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    u8 *v = func_00445F18(a0);
    s32 *src = (s32 *)(*(u8 **)(*(u8 **)(v + 8) + 104) + 160);
    s32 *dst = (s32 *)(s1 + 3216);
    s32 i;
    for (i = 0; i < 4; i++) {
        *dst++ = *src++;
    }
    *(u128_t *)(a0 + 16) = *(u128_t *)(s1 + 3376);
    *(u128_t *)(a0 + 240) = *(u128_t *)(s1 + 3392);
    func_0040C638(a0 + 192, a0 + 240);
}
/* localdecomp:end func_003AC5A0 */
