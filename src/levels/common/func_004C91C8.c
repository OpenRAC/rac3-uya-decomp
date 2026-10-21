#include "common.h"

/* localdecomp:start func_004C91C8 */
void func_004C91C8(u8 *a0, s32 a1, s32 a2) {
    u32 *p = *(u32 **)(a0 + 12);
    p[2] = (p[2] & 0xFFFFFF) | (a1 << 24);
    (*(u32 **)(a0 + 12))[3] = ((*(u32 **)(a0 + 12))[3] & 0xFFFFFF) | (a2 << 24);
}
/* localdecomp:end func_004C91C8 */
