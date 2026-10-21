#include "common.h"

/* localdecomp:start func_004C8840 */
extern s32 func_0040D020(f32, s32, s32);
void func_004C8840(f32 f, s32 x, s32 *out, s32 *a, s32 *b) {
    out[0] = func_0040D020(f, a[0], b[0]);
    out[1] = func_0040D020(f, a[1], b[1]);
    out[2] = func_0040D020(f, a[2], b[2]);
    out[3] = func_0040D020(f, a[3], b[3]);
}
/* localdecomp:end func_004C8840 */
