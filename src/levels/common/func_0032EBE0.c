#include "common.h"

extern void func_00437698(u8 *, s32, f32 *);
extern s32 func_003F9498(f32 *, s32, u8 *, f32);
extern s32 D_001EAA9C[];

void func_0032EBE0(u8 *a0) {
    f32 v[4];

    func_00437698(a0, 0, v);
    if (func_003F9498(v, 2, a0, 0.25f) && D_001EAA9C[0] > 0) {
        a0[32] = 8;
    }
}
