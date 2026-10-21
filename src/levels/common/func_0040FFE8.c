#include "common.h"

/* localdecomp:start func_0040FFE8 */
extern void func_0040D940();
f32 func_0040FFE8(s32 a, s32 unused, s32 c, f32 f) {
    f32 r = 1.0f;
    s32 t;
    if (a) t = ((s32 (*)(f32))func_0040D940)(1.0f); else t = 0;
    if (c < t) {
        r = (f32)c / (f32)t;
        if (r < f) r = f;
    }
    return r;
}
/* localdecomp:end func_0040FFE8 */
