#include "common.h"

/* localdecomp:start func_0042CFB8 */
extern s32 D_001D545C[];
extern s32 D_001D7BE0[];
extern f32 D_001D71D8;
extern f32 D_001D71DC[];
extern f32 D_001D71E0;
extern f32 D_001D71E4[];

s32 func_0042CFB8(f32 *a0, f32 *a1)
{
    s32 r = 0;

    if (D_001D545C[0] == 3) {
        if (D_001D7BE0[0] == 9) {
            *a0 = D_001D71D8;
            *a1 = D_001D71DC[0];
            r = 1;
        } else if ((u32)D_001D7BE0[0] < 9) {
            r = 1;
            *a0 = D_001D71E0;
            *a1 = D_001D71E4[0];
        }
    }
    return r;
}
/* localdecomp:end func_0042CFB8 */
