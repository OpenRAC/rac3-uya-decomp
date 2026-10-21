#include "common.h"

/* localdecomp:start func_003C9DC8 */
extern void func_00441FF8(u8 *, s32, s32);

s32 func_003C9DC8(u8 *a0, s32 a1, s32 a2) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 old = a0[32];
    if (v[1169] != 0) return 0;
    v[1168] = a1;
    *(s32 *)(v + 1148) = a2;
    func_00441FF8(a0, 22, -1);
    return a0[32] != old;
}
/* localdecomp:end func_003C9DC8 */
