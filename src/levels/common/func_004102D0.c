#include "common.h"

/* localdecomp:start func_004102D0 */
extern void func_0040D548(s32);
extern s32 D_001D55E8;

extern s32 D_001D55E8;
extern void func_0040D548(s32);
extern void func_0040DBE0_0038C628(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
extern s32 func_0040D940_0038C628(s32, s32, f32);
s32 func_004102D0(s32 x, s32 y, s32 a, s32 b, s32 c) {
    s32 saved;
    saved = D_001D55E8;
    func_0040D548(1);
    func_0040DBE0_0038C628(a, b, c, 1, 0, 0x80000000UL, (f32)x, (f32)y, 1.0f, 1.0f, 0.0f, 0.0f);
    x -= func_0040D940_0038C628(b, c, 1.0f) >> 1;
    func_0040D548(saved);
    return x;
}
/* localdecomp:end func_004102D0 */
