#include "common.h"

/* localdecomp:start func_0044B010 */
extern void func_0040C658(f32 *a0, f32 *a1);
extern void func_0040C9B0(f32 *a0, f32 *a1, f32 *a2);
extern void func_00447748(f32 *a0, f32 *a1);

void func_0044B010(u8 *moby, f32 x, f32 y, f32 z) {
    f32 v[4];
    f32 m1[16];
    f32 m2[16];

    v[0] = x;
    v[1] = y;
    v[2] = z;
    func_0040C658(m1, v);
    func_0040C658(m2, (f32 *)(moby + 240));
    func_0040C9B0(m2, m2, m1);
    func_00447748(m2, (f32 *)(moby + 240));
}
/* localdecomp:end func_0044B010 */
