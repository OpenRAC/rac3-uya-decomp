#include "common.h"

/* localdecomp:start func_003F15C8 */
extern u8 D_001E2AC0[];

void func_003F15C8(s32 i) {
    u8 *e = (u8 *)(i * 1120 + (s32)D_001E2AC0);
    u8 *p = *(u8 **)(e + 292);
    if (p != 0) {
        *(s32 *)(p + 152) = 0;
    }
}
/* localdecomp:end func_003F15C8 */
