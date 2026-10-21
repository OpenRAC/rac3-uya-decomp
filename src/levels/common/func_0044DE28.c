#include "common.h"

/* localdecomp:start func_0044DE28 */
extern void func_0044DC18(u8 *a, u8 *b);
extern void func_0040C2D0(u8 *a, u8 *b, u8 *c);

void func_0044DE28(u8 *a0, u8 *a1, float f)
{
    func_0044DC18(a0, a1);
    *(float *)(a1 + 8) = f;
    func_0040C2D0(a1, a1, a0 + 192);
}
/* localdecomp:end func_0044DE28 */
