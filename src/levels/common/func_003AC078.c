#include "common.h"

/* localdecomp:start func_003AC078 */
extern void func_004A7200(s32, s32, s32);

void func_003AC078(s32 a0, u8 *s) {
    s32 st = *(s32 *)(s + 3136);
    s32 idx;
    if (st == 0 || st == 3) {
        *(s32 *)(s + 3136) = 1;
        idx = *(s32 *)(*(u8 **)(s + 104) + 68);
        if (idx >= 0) {
            func_004A7200(idx, 0, *(s32 *)(s + 100));
        }
    }
}
/* localdecomp:end func_003AC078 */
