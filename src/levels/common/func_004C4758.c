#include "common.h"

/* localdecomp:start func_004C4758 */
extern s32 func_004C4710(void *, s32);

s32 func_004C4758(void *ctx, s32 *list, s32 n, s32 type) {
    s32 best = 0;
    s32 bestd = 9999;
    s32 d;
    s32 i;

    for (i = 0; i < n; i++) {
        if (type <= 0 || *(u8 *)(*(s32 *)(list[i] + 36) + 70) == type) {
            d = func_004C4710(ctx, list[i]);
            if (d < bestd && d != -1) {
                best = list[i];
                bestd = d;
            }
        }
    }
    return best;
}
/* localdecomp:end func_004C4758 */
