#include "common.h"
extern u8 *D_002417C0[];
extern u32 D_0024145C[];
s32 func_006748D0(void) {
    u8 *p = D_002417C0[0];
    return (p && *(s32 *)(p + 384) == 2) || D_0024145C[0] - 46 < 4;
}
