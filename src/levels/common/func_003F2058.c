#include "common.h"

/* localdecomp:start func_003F2058 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_001E2D60[];
void func_003F2058(s32 arg0) {
    u8 *p = D_001E2D60 + arg0 * 0x460;
    if (p[2] != 0) {
        *(u128_t *)(p + 0x50) = *(u128_t *)(p + 0xC0);
        *(u128_t *)(p + 0x60) = *(u128_t *)(p + 0xD0);
    }
}
/* localdecomp:end func_003F2058 */
