#include "common.h"

/* localdecomp:start func_00448B80 */
extern f32 func_0040BF38(s32 a);
extern void func_0040C0F0(s32 a, s32 b, f32 x);
void func_00448B80(s32 a, f32 x) {
    if (x < func_0040BF38(a)) func_0040C0F0(a, a, x);
}
/* localdecomp:end func_00448B80 */
