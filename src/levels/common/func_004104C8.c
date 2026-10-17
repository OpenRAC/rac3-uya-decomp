#include "common.h"

extern void func_0040D548(s32);
extern s32 D_001D55E8;
extern void func_0040DBE0(f32, f32, f32, f32, s32, s32, s32, s32, s32, unsigned long, f32, f32);

extern s32 D_001D55E8;
extern void func_0040D548(s32);
void func_004104C8(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 save;
    save = D_001D55E8;
    func_0040D548(1);
    ((void (*)(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32))func_0040DBE0)(c, d, e, 0, 0, 0x80000000, (f32)a, (f32)b, 1.0f, 1.0f, 0.0f, 0.0f);
    func_0040D548(save);
}
