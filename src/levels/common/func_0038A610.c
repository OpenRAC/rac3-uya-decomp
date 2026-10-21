#include "common.h"

/* localdecomp:start func_0038A610 */
extern void func_004C3500(u8 *, u8 *, s32, s32, float);
void func_0038A610(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_004C3500(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_0038A610 */
