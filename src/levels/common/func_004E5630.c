#include "common.h"

/* localdecomp:start func_004E5630 */
typedef struct {
    u8 pad0[9836];
    f32 arr[32];
    s32 f26EC;
    s32 f26F0;
} G_4E5630;
extern G_4E5630 D_001A4BE0;
f32 func_004E5630(s32 a0) {
    s32 n;
    s32 m;
    n = a0 < 32 ? a0 : 31;
    m = D_001A4BE0.f26F0;
    if (m < n) {
        n = m;
    }
    return D_001A4BE0.arr[(D_001A4BE0.f26EC - n + 31) % 32];
}
/* localdecomp:end func_004E5630 */
