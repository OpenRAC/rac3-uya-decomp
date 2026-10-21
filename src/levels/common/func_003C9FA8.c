#include "common.h"

/* localdecomp:start func_003C9FA8 */
extern void func_00441FB8(u8 *a0, s32 a1, s32 a2);
s32 func_003C9FA8(u8 *a0, s32 a1, s32 a2) {
    u8 *p = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (p[1169] != 0) {
        return 0;
    }
    p[1168] = a1;
    *(s32 *)(p + 1148) = a2;
    func_00441FB8(a0, 26, -1);
    return a0[32] != old;
}
/* localdecomp:end func_003C9FA8 */
