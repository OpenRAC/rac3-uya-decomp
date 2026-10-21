#include "common.h"

/* localdecomp:start func_003B6448 */
extern void func_003B6498(u8 *a0, u8 *a1);
void func_003B6448(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    if (a0[32] == 0) {
        func_003B6498(a0, v);
    }
    if (a0[32] == 1) {
        *(u16 *)(a0 + 52) |= 2;
    }
}
/* localdecomp:end func_003B6448 */
