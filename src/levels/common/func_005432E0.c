#include "common.h"

extern u8 *D_002417C0[];

s32 func_005432E0(void) {
    s32 n = 0;
    s32 i;
    u8 b = D_002417C0[0][409];
    for (i = 0; i < 8; i++) {
        n += (b >> i) & 1;
    }
    return n;
}
