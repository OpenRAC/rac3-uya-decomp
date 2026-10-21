#include "common.h"

/* localdecomp:start func_0051C4A0 */
extern s32 func_0051C4A0(u8 *arg0, s32, s32);

void func_0051C428_003EB620(void *, s32, s32);

s32 func_0051C4A0(u8 *arg0, s32 arg1, s32 arg2) {
    s32 a = 0;
    s32 ok = 1;
    s32 b = 0;

    if (arg1 != 0) {
        if (arg1 == 1) {
            a = 1;
        } else {
            ok = 0;
        }
    }
    if (arg2 == 0) {
        b = 1;
    } else if (arg2 != 1) {
        ok = 0;
    }
    func_0051C428_003EB620(arg0, 1, a);
    func_0051C428_003EB620(arg0, 2, b);
    *(s8 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    return ok;
}
/* localdecomp:end func_0051C4A0 */
