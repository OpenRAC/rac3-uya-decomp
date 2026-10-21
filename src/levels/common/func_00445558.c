#include "common.h"

/* localdecomp:start func_00445558 */
extern f32 func_004454A8(f32, f32, u8 *);
extern f32 func_0040CEC8(f32, f32);

void func_00445558(f32 *val, u8 *obj, f32 a, f32 lim)
{
    f32 d = func_004454A8(a, *val, obj);

    if (lim < d) {
        d = lim;
    } else if (d < -lim) {
        d = -lim;
    }
    *val = func_0040CEC8(*val, d);
    func_004454A8(a, *val, obj);
}
/* localdecomp:end func_00445558 */
