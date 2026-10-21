#include "common.h"

/* localdecomp:start func_00459E50 */
extern s32 D_001D673C;
extern void *func_00445EB8(void *);
extern f32 func_0044E300(void *);

s32 func_00459E50(u8 *a0, u8 *a1) {
    u8 *p;
    s32 r;

    if (*(f32 *)(a1 + 144) >= *(f32 *)(a0 + 24)) return 0;
    p = func_00445EB8(a0);
    if (p == 0) return 0;
    r = 0;
    if (D_001D673C != 0) {
        if (func_0044E300(a0 + 16) < *(f32 *)(p + 64) - 0.5f) r = 1;
    } else {
        if (*(f32 *)(a0 + 24) < *(f32 *)(p + 64) - 0.5f) r = 1;
    }
    return r;
}
/* localdecomp:end func_00459E50 */
