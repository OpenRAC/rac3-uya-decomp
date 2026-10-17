#include "common.h"

extern s32 D_001D55E8;
extern void func_0040D548(s32 a0);
extern s32 func_0040D940(s32 a0, s32 a1, f32 f);

s32 func_00410120(s32 a0, s32 a1)
{
    s32 saved = D_001D55E8;
    s32 r;

    func_0040D548(1);
    r = func_0040D940(a0, a1, 1.0f);
    func_0040D548(saved);
    return r;
}
