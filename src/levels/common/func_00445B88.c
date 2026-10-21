#include "common.h"

/* localdecomp:start func_00445B88 */
u32 func_00445B88(f32 r, f32 g, f32 b, f32 a) {
    u32 gv = ((s32)(g * 255.0f) & 0xff) << 8;
    return ((s32)(r * 255.0f) & 0xff) | gv | (((s32)(b * 255.0f) & 0xff) << 16) | (((s32)(a * 255.0f) & 0xff) << 24);
}
/* localdecomp:end func_00445B88 */
