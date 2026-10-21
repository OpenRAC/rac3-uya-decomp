#include "common.h"

/* localdecomp:start func_004475E8 */
extern void func_0040BE90(f32 *, void *, f32);
extern f32 func_0040C3C8(f32);

extern f32 func_0040C3E0(f32);
extern f32 func_0040C3C8(f32);
extern void func_0040BE90(f32 *, void *, f32);
void func_004475E8(f32 *q, void *axis, f32 angle) {
    f32 h = angle * 0.5f;
    func_0040BE90(q, axis, func_0040C3E0(h));
    q[3] = func_0040C3C8(h);
}
/* localdecomp:end func_004475E8 */
