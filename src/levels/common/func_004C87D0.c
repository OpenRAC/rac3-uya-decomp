#include "common.h"

/* localdecomp:start func_004C87D0 */
void func_004C87D0(s32 unused, f32 *out, f32 *a, f32 *b, f32 t) {
    f32 s = 1.0f - t;
    out[0] = s * a[0] + t * b[0];
    out[1] = s * a[1] + t * b[1];
    out[2] = s * a[2] + t * b[2];
    out[3] = s * a[3] + t * b[3];
}
/* localdecomp:end func_004C87D0 */
