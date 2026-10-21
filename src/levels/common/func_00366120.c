#include "common.h"

/* localdecomp:start func_00366120 */
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3E0(f32);
extern f32 func_0040C3C8(f32);

void func_00366120(f32 *a0, f32 *a1, f32 *a2, s32 a3, s32 t0)
{
    if (t0 != 0) {
        *a0 += 0.045f;
        if (*a0 > 1.0f) {
            *a0 = 1.0f;
        }
    } else if (*a0 < 0.1f) {
        *a0 += 0.01f;
        if (*a0 > 0.1f) {
            *a0 = 0.1f;
        }
    } else {
        *a0 -= 0.006f;
        if (*a0 < 0.1f) {
            *a0 = 0.1f;
        }
    }
    *a1 = func_0040CEC8(*a1, *a0 * 0.31415927f);
    a2[a3 + 4] = func_0040C3E0(*a1 * 0.5f);
    a2[7] = func_0040C3C8(*a1 * 0.5f);
}
/* localdecomp:end func_00366120 */
