#include "common.h"

/* localdecomp:start func_0044B550 */
extern void func_00438938(s32, u32 *, u32 *, u32 *);

u32 func_0044B550(s32 a0) {
    u32 r, g, b;
    func_00438938(a0, &r, &g, &b);
    return 0x80000000 | (b << 16) | (g << 8) | r;
}
/* localdecomp:end func_0044B550 */
