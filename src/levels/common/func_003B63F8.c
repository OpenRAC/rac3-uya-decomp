#include "common.h"

/* localdecomp:start func_003B63F8 */
extern void **func_00438488(s32 a0, s32 a1, s32 a2);
f32 func_003B63F8(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 104);
    void **v = func_00438488(*(s32 *)s0, 6, 4);
    s32 x = *(s32 *)(s0 + 284);
    if (x == 0) {
        return 0.0f;
    }
    return ((f32 (*)(s32))*v)(x);
}
/* localdecomp:end func_003B63F8 */
