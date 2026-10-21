#include "common.h"

/* localdecomp:start func_0050CC50 */
extern u8 D_001A4BE0[];
void func_0050CC50(void) {
    u8 *b = D_001A4BE0;
    u8 *q;
    *(u16 *)(*(u8 **)(b + 9664) + 52) |= 1;
    q = *(u8 **)(b + 6688);
    if (q != 0) {
        *(u16 *)(q + 52) |= 1;
    }
}
/* localdecomp:end func_0050CC50 */
