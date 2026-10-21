#include "common.h"

/* localdecomp:start func_00458600 */
extern int func_004493C0(u8 *a, int b, u8 *c, u8 *d, u8 *e, u8 *f);

void func_00458600(u8 *a0, u8 *a1)
{
    int v = *(int *)(a1 + 136);
    if (v != 0) {
        if (func_004493C0(a0, v, a0 + 16, a0 + 240, a0 + 16, a0 + 240) != 0) {
            *(int *)(a1 + 148) |= 0x40;
        }
    }
}
/* localdecomp:end func_00458600 */
