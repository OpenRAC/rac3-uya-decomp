#include "common.h"
extern s32 D_001D5D60;
extern void func_005908F8(s32);
extern void func_00590F90(s32, s32, s32, s32, s32, unsigned long, f32, f32, f32, f32, f32, f32);
void func_00593950(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 save;
    save = D_001D5D60;
    func_005908F8(1);
    func_00590F90(c, d, e, 2, 0, 0x80000000, (f32)a, (f32)b, 1.0f, 1.0f, 0.0f, 0.0f);
    func_005908F8(save);
}
