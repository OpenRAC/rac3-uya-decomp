#include "common.h"

/* localdecomp:start func_0045A420 */
extern void func_0040C920(void *, void *);
extern void func_0040C2D0(void *, void *, void *);
extern f32 func_0040BF68(void *);
extern f32 func_0040C490(f32, f32);

f32 func_0045A420(u8 *a0, void *a1) {
    f32 v[4];
    f32 m[12];
    func_0040C920(m, a0 + 192);
    func_0040C2D0(v, a1, m);
    return func_0040C490(v[2], func_0040BF68(v));
}
/* localdecomp:end func_0045A420 */
