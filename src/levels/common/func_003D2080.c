#include "common.h"

typedef int u128_003D2080 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D2080;

extern f32 func_0041CCE0(f32);
extern f32 func_0041CCF8(f32);
extern f32 D_001DEBE4;
extern f32 D_001DEBE8;

void func_003D2080(u8 *a0, u8 *a1, V4_003D2080 *a2) {
    V4_003D2080 v;
    u128_003D2080 x, y, r;

    v.x = func_0041CCE0(*(f32 *)(a0 + 0xF8)) * D_001DEBE4;
    v.y = func_0041CCF8(*(f32 *)(a0 + 0xF8)) * D_001DEBE4;
    v.z = 0.0f;
    v.z = D_001DEBE8 + v.z;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a2));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_003D2080 *)(*(u8 **)(a1 + 0xD4) + 0x10)) : "j"(r));
    *(f32 *)(*(u8 **)(a1 + 0xD4) + 0xF8) = *(f32 *)(a0 + 0xF8);
}
