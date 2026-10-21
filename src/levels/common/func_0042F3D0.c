#include "common.h"

/* localdecomp:start func_0042F3D0 */
extern s32 D_00142438[];
extern s32 D_001D4CE8;
extern s32 D_001D4CEC;
extern u8 D_001D672C;
extern void func_00430258(void);
void func_0042F3D0(void) {
    s32 f;
    if (D_00142438[0] != 2) {
        D_001D4CE8 = 4;
        return;
    }
    f = D_001D4CEC;
    if (f & 0x20) {
        func_00430258();
        if (D_001D672C != 0) {
            D_001D4CE8 = 26;
        } else {
            D_001D4CE8 = 7;
        }
    } else if (f & 8) {
        D_001D4CEC = f ^ 8;
        D_001D4CE8 = 9;
    }
}
/* localdecomp:end func_0042F3D0 */
