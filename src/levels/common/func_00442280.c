#include "common.h"

/* localdecomp:start func_00442280 */
extern f32 func_0040CF10(f32 a, f32 b);
extern f32 func_0040C3C8(f32 a);
extern f32 func_0040CEC8(f32 a, f32 b);

f32 func_00442280(f32 a, f32 b, f32 t) {
    f32 r = func_0040CF10(b, a);
    f32 c = func_0040C3C8(t * 3.1415927f);
    return func_0040CEC8(a, r * ((1.0f - c) * 0.5f));
}
/* localdecomp:end func_00442280 */
