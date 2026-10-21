#include "common.h"

/* localdecomp:start func_003AC0C8 */
extern void func_004A7200(s32, s32, s32);
void func_003AC0C8(s32 a0, u8 *a1) {
    s32 t;
    if ((u32)(*(s32 *)(a1 + 3136) - 1) < 2) {
        *(s32 *)(a1 + 3136) = 3;
        t = *(s32 *)(*(u8 **)(a1 + 104) + 68);
        if (t >= 0) {
            func_004A7200(t, 0, *(s32 *)(a1 + 100));
        }
    }
}
/* localdecomp:end func_003AC0C8 */
