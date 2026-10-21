#include "common.h"

/* localdecomp:start func_004711E8 */
extern s32 func_0040BAC0(u8 *a0);
extern void func_0045E580(u8 *a0);
void func_004711E8(u8 *a0) {
    u8 *s1 = a0 + 48;
    if (s1 != 0) {
        if (func_0040BAC0(a0 + 10) != 0) {
            func_0045E580(a0);
        } else {
            (*(void (**)(u8 *, u8 *))(*(u8 **)(s1 + 4) + 20))(a0, s1);
        }
    }
}
/* localdecomp:end func_004711E8 */
