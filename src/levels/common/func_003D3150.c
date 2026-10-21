#include "common.h"

/* localdecomp:start func_003D3150 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_00435E70(s32, s32);

u8 *func_003D3150(u8 *src) {
    u8 *o = func_00435E70(7110, 128);
    if (o != 0) {
        *(u128_t *)(o + 16) = *(u128_t *)(src + 16);
        o[48] = 64;
        *(u8 **)(o + 184) = src;
    }
    return o;
}
/* localdecomp:end func_003D3150 */
