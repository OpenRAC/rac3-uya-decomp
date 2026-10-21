#include "common.h"

/* localdecomp:start func_003B51E0 */
extern s32 func_00326DA8(s32);
extern s32 func_00438538(s32);
extern void func_00326DF0(s32, u8);
extern s32 func_00438670(s32, s32);

s32 func_003B51E0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 neg = 0;
    if (a4 < 0) neg = 1;
    if (neg == 0) {
        a3 = func_00326DA8(a4);
    }
    if (a3 == 255) {
        a3 = func_00438538(a2);
        if (neg == 0) {
            func_00326DF0(a4, a3);
        }
    } else if (func_00438670(a3, a2) == 0) {
        a3 = 255;
    }
    return a3;
}
/* localdecomp:end func_003B51E0 */
