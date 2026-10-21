#include "common.h"

/* localdecomp:start func_005028C8 */
extern u8 D_001A4BE0[];
extern void func_00436220(s32);
void func_005028C8(void) {
    u8 *p = D_001A4BE0;
    u8 *q;
    if (*(s32 *)(p + 6660) != 0) {
        func_00436220(*(s32 *)(p + 6660));
        *(s32 *)(p + 6660) = 0;
    }
    q = *(u8 **)(p + 4848);
    if (q != 0) {
        *(u16 *)(q + 52) &= 0xffbe;
    }
    q = *(u8 **)(p + 4852);
    if (q != 0) {
        *(u16 *)(q + 52) &= 0xffbe;
    }
}
/* localdecomp:end func_005028C8 */
