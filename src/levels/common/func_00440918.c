#include "common.h"

/* localdecomp:start func_00440918 */
extern s32 func_0013D3E0(void);
f32 func_00440918(f32 a, f32 b) {
    s32 r = func_0013D3E0();
    f32 x = a + (f32)r * (b - a) * (1.0f / 32768.0f);
    if (r & 1) {
        x = -x;
    }
    return x;
}
/* localdecomp:end func_00440918 */
