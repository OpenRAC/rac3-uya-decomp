#include "common.h"

/* localdecomp:start func_003C3E90 */
typedef int u128_3C3E90 __attribute__((mode(TI)));

void func_003C3E90(u8 *a0, u128_3C3E90 *a1, u128_3C3E90 *a2) {
    *(u128_3C3E90 *)(a0 + 0x00) = *a1;
    *(u128_3C3E90 *)(a0 + 0x10) = *a2;
}
/* localdecomp:end func_003C3E90 */
