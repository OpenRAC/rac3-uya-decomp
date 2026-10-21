#include "common.h"

/* localdecomp:start func_00455E98 */
typedef int u128_455E98 __attribute__((mode(TI)));

void func_00455E98(u8 *a0, u8 *a1, u8 *a2) {
    *(u8 **)(a2 + 80) = a1;
    *(u128_455E98 *)(a2 + 16) = *(u128_455E98 *)(a1 + 16);
    *(u128_455E98 *)(a2 + 0) = *(u128_455E98 *)(a1 + 16);
    *(u128_455E98 *)(a2 + 32) = *(u128_455E98 *)(a1 + 16);
    *(u128_455E98 *)(a2 + 112) = *(u128_455E98 *)(a0 + 16);
    *(s32 *)(a2 + 64) = 0;
}
/* localdecomp:end func_00455E98 */
