#include "common.h"

/* localdecomp:start func_00335D70 */
void func_00335D70(u8 *a, u8 *b) {
    u8 *s = *(u8 **)(b + 104);
    u8 *d = *(u8 **)(a + 104);
    *(s32 *)(d + 64) = *(s32 *)(s + 108);
    *(s32 *)(d + 72) = *(s32 *)(s + 124);
    *(s32 *)(d + 68) = *(s32 *)(s + 112);
}
/* localdecomp:end func_00335D70 */
