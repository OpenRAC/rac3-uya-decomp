#include "common.h"

/* localdecomp:start func_00410758 */
extern f32 func_0040FFE8(s32, s32, s32, f32);
extern void func_0040DBE0_0038CA08(s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, unsigned long, f32);
void func_00410758(s32 x, s32 y, s32 a, s32 b, s32 c, s32 d, f32 p) {
    f32 r = func_0040FFE8(b, c, d, p);
    func_0040DBE0_0038CA08(a, b, c, (f32)x, (f32)y, r, r, 0.0f, 1, 0, 0x80000000UL, 0.0f);
}
/* localdecomp:end func_00410758 */
