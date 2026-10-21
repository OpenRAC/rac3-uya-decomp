#include "common.h"

/* localdecomp:start func_00479140 */
extern s32 D_001D8188[2];
extern s32 D_001D8198[2];
extern f32 D_001D81A8[2];
extern s32 D_001D81B8;

void func_00479140(s32 a0, s32 idx, u8 flag, f32 f) {
    if (f > 1.0f) {
        f = 1.0f;
    }
    if (f < 0.0f) {
        f = 0.0f;
    }
    D_001D8188[idx] += 2;
    D_001D81A8[idx] = f;
    if (flag) {
        if (D_001D81B8 >> 1 < D_001D8188[idx]) {
            D_001D8188[idx] = D_001D81B8 >> 1;
        }
    } else {
        if (D_001D81B8 < D_001D8188[idx]) {
            D_001D8188[idx] = D_001D81B8;
        }
    }
    D_001D8198[idx] = a0;
}
/* localdecomp:end func_00479140 */
