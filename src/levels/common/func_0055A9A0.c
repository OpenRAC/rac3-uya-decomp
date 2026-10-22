#include "common.h"

/* localdecomp:start func_0055A9A0 */
extern f32 func_0058F980(f32, f32);
extern f32 func_00590400(f32, f32);
extern f32 func_0058F400(void *);
extern void func_0058F5B0(void *, void *, f32);

void func_0055A9A0(u8 *o, f32 *v) {
    f32 lim = 1.8325957f;
    f32 a = func_00590400(*(f32 *)(o + 0xB8), func_0058F980(v[0], v[1]));

    if (lim < a) {
        a = lim;
    }
    func_0058F5B0(v, v, func_0058F400(v) * ((lim - a) / lim * 0.3f + 0.7f));
}
/* localdecomp:end func_0055A9A0 */
