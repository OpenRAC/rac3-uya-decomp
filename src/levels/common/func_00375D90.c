#include "common.h"

typedef int u128_00375D90 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00375D90;

extern s32 func_00375CE0(V4_00375D90 *a0, u128_00375D90 *a1);
extern void func_0041C768(V4_00375D90 *a0, u128_00375D90 *a1, f32 f);
extern s32 D_001E1B50[4];
extern f32 D_001E1B40[4];

s32 func_00375D90(V4_00375D90 *a0, u128_00375D90 *a1) {
    u128_00375D90 x, y, r;
    if (func_00375CE0(a0, a1) == 0) {
        return 0;
    }
    func_0041C768(a0, (u128_00375D90 *)D_001E1B50, 0.2f);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a0));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_00375D90 *)D_001E1B40));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*a0) : "j"(r));
    *a1 = *(u128_00375D90 *)D_001E1B50;
    return 1;
}
