#include "common.h"

/* localdecomp:start func_00448F40 */
extern f32 func_0040CEC8(f32, f32);

void func_00448F40(f32 *a0, f32 *a1) {
    a0[2] = func_0040CEC8(a0[2], a1[2]);
    a0[1] = func_0040CEC8(a0[1], a1[1]);
    a0[0] = func_0040CEC8(a0[0], a1[0]);
}
/* localdecomp:end func_00448F40 */
