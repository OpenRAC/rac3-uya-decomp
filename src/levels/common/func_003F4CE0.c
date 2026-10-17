#include "common.h"
extern u8 D_0024A140[];
extern void func_003F3BC0(u8 *, u8 *);
extern s32 func_003F4FF8(u8 *, u8 *, u8 *, s32, s32);
extern f32 func_0045C850(u8 *, u8 *);
extern void func_00481658(u8 *);
void func_003F4CE0(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    u8 *s0 = **(u8 ***)(a0 + 144);
    func_003F3BC0(s0, a0);
    func_003F4FF8(a0, s1 + 304, s0, 0, 0);
    if (a0[49] != 0 && func_0045C850(D_0024A140, a0 + 16) < 256.0f) {
        func_00481658(a0);
        a0[111] = 15;
    }
}
