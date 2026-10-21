#include "common.h"

/* localdecomp:start func_004335A0 */
extern u8 *D_001D67C8;
extern void func_004CA9B0(u8 *, s32, s32, s32, s32);

void func_004335A0(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 *p = D_001D67C8;
    if (p != 0) {
        func_004CA9B0(&p[0x1FCA8], a3, a0, a1, a2);
    }
}
/* localdecomp:end func_004335A0 */
