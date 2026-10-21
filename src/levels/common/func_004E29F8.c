#include "common.h"

/* localdecomp:start func_004E29F8 */
extern u8 D_001A4BE0[];
void func_004E29F8(void) {
    u8 *b = D_001A4BE0;
    u8 *p;
    s32 i;
    *(s32 *)(b + 4468) = 0;
    *(s32 *)(b + 4472) = 0;
    p = b;
    for (i = 0; i < 4; i++) {
        *(s32 *)(p + 4500) = 0;
        *(s32 *)(p + 4504) = 0;
        p += 16;
    }
}
/* localdecomp:end func_004E29F8 */
