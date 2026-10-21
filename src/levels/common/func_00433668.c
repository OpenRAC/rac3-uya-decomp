#include "common.h"

/* localdecomp:start func_00433668 */
extern u8 *D_001D67C8;
extern void func_004CA1E8(u8 *, s32, s32);

void func_00433668(s32 a0, s32 a1) {
    u8 *p = D_001D67C8;
    if (p != 0) {
        func_004CA1E8(p + 0x1FCA8, a0, a1);
    }
}
/* localdecomp:end func_00433668 */
