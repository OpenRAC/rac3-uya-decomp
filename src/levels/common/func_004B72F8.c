#include "common.h"

/* localdecomp:start func_004B72F8 */
extern u8 D_001426E0[];
extern void func_004344A0(void);
void func_004B72F8(u32 a0) {
    if (a0 >= 8) {
        a0 -= 8;
        if (a0 < 8) {
            D_001426E0[200] |= 1 << a0;
        }
        func_004344A0();
    } else {
        D_001426E0[62] |= 1 << a0;
        func_004344A0();
    }
}
/* localdecomp:end func_004B72F8 */
