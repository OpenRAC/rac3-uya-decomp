#include "common.h"

/* localdecomp:start func_0042B8F0 */
void func_0042B8F0(u8 *dst, u8 *a, u8 *b, u8 *mask)
{
    s32 i;
    s32 j;
    s32 bit;

    for (i = 0; i < 32768; i++) {
        bit = 1;
        for (j = 0; j < 8; j++) {
            if (*mask & bit) {
                *dst = *a;
            } else {
                *dst = *b;
            }
            bit <<= 1;
            a++;
            b++;
            dst++;
        }
        mask++;
    }
}
/* localdecomp:end func_0042B8F0 */
