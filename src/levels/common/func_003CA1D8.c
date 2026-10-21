#include "common.h"

/* localdecomp:start func_003CA1D8 */
extern void func_004A6DF8(u8 *, s32);

void func_003CA1D8(u8 *a0) {
    u8 *s1;
    *(s32 *)(a0 + 152) = 0;
    *(u16 *)(a0 + 52) |= 0x41;
    *(u16 *)(a0 + 52) &= ~0x1000;
    s1 = *(u8 **)(a0 + 104);
    func_004A6DF8(a0, 1);
    *(u16 *)(a0 + 52) |= 2;
    if (*(u8 **)(s1 + 1360) != 0) {
        *(u16 *)(*(u8 **)(s1 + 1360) + 52) |= 0x41;
        *(u16 *)(*(u8 **)(s1 + 1360) + 52) &= ~0x1000;
        *(s32 *)(*(u8 **)(s1 + 1360) + 152) = 0;
        func_004A6DF8(*(u8 **)(s1 + 1360), 1);
        *(u16 *)(*(u8 **)(s1 + 1360) + 52) |= 2;
    }
}
/* localdecomp:end func_003CA1D8 */
