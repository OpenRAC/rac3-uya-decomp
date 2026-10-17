#include "common.h"

extern u8 *D_002417C0[];
extern s32 func_0066F7C8(void);

s32 func_0066F8B8(void) {
    u8 *p = D_002417C0[0];
    s32 r = 1;
    if (p != 0) {
        s32 b = p[409];
        r = (b >> func_0066F7C8()) & 1;
    }
    return r;
}
