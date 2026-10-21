#include "common.h"

/* localdecomp:start func_004423D8 */
extern f32 func_0040C3C8(f32 a);
extern f32 func_0040CF10(f32 a, f32 b);
extern f32 func_0040CEC8(f32 a, f32 b);
void func_004423D8(f32 *out, f32 *a, f32 *b, f32 t) {
    f32 h = (1.0f - func_0040C3C8(t * 3.1415927f)) * 0.5f;
    out[0] = func_0040CEC8(a[0], func_0040CF10(b[0], a[0]) * h);
    out[1] = func_0040CEC8(a[1], func_0040CF10(b[1], a[1]) * h);
    out[2] = func_0040CEC8(a[2], func_0040CF10(b[2], a[2]) * h);
}
/* localdecomp:end func_004423D8 */
