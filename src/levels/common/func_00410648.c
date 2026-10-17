#include "common.h"

extern void func_0040D548(s32);
extern void func_0040EE10(s32, long, s32, s32, unsigned long, s32, f32, f32);
extern s32 D_001D55E8;

extern s32 D_001D55E8;
extern void func_0040D548(s32);
extern void func_0040EE10(s32, long, s32, s32, unsigned long, s32, f32, f32);
void func_00410648(s32 a, s32 b, s32 c, s32 d) {
    s32 old = D_001D55E8;
    func_0040D548(1);
    ((void (*)(s32, s32, s32, s32, f32, f32, unsigned long))func_0040EE10)(a, b, c, d, 1.0f, 1.0f, 0x80000000UL);
    func_0040D548(old);
}
