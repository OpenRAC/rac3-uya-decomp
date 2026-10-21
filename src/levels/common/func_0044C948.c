#include "common.h"

/* localdecomp:start func_0044C948 */
extern s32 D_001D4BD0[];
extern s32 D_001D4BD4[];
extern void func_003FE7B0(f32 *, void *);

void func_0044C948(void *a0, s32 *x, s32 *y) {
    f32 v[4];

    func_003FE7B0(v, a0);
    *x = (v[0] - (f32)D_001D4BD0[0]) * 0.0625f;
    *y = (v[1] - (f32)D_001D4BD4[0]) * 0.0625f;
}
/* localdecomp:end func_0044C948 */
