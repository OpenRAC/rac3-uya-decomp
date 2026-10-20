#include "common.h"
typedef int s128_3D8F20 __attribute__((mode(TI)));
extern void func_00437698(void *, s32, s128_3D8F20 *);
extern f32 func_004408C0(f32, f32);
extern void func_004082B0(void *, s32, u32, s32, f32, f32, f32);
void func_003D8F20(void *m) {
    s128_3D8F20 v;
    func_00437698(m, 14, &v);
    func_004082B0(&v, 11, 0x40202080, 1, func_004408C0(0.09f, 0.16f), 0.08f, 0.0f);
    func_00437698(m, 15, &v);
    func_004082B0(&v, 11, 0x40202080, 1, func_004408C0(0.09f, 0.16f), 0.08f, 0.0f);
}
