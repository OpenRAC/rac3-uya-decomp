#include "common.h"

/* localdecomp:start func_0044EAB8 */
extern f32 func_0040C3E0(f32);
extern f32 func_0040CEC8(f32, f32);
extern void func_0040D020(s32, s32, f32);

void func_0044EAB8(f32 *a, s32 b, s32 c, f32 step) {
    f32 t;

    t = func_0040C3E0(*a) * 0.5f + 0.5f;
    *a = func_0040CEC8(*a, step);
    func_0040D020(b, c, t);
}
/* localdecomp:end func_0044EAB8 */
