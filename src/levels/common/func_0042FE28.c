#include "common.h"

/* localdecomp:start func_0042FE28 */
extern s32 D_00142438[];
extern void func_00430258(void);

extern s32 D_00142438[];
extern u32 D_001D4CEC_00396E20;
extern s32 D_001D4CE8_00396E20;
extern void func_00430258(void);
void func_0042FE28(void) {
    s32 v;
    if (D_00142438[0] != 2) {
        v = 4;
    } else {
        u32 f = D_001D4CEC_00396E20;
        if (f & 0x20) {
            func_00430258();
            v = 0x12;
        } else if (f & 0x2000) {
            v = 0x1D;
        } else {
            return;
        }
    }
    D_001D4CE8_00396E20 = v;
}
/* localdecomp:end func_0042FE28 */
