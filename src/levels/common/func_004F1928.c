#include "common.h"

/* localdecomp:start func_004F1928 */
typedef int Q_4F1928 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4F1928;
typedef struct { V4_4F1928 v; f32 f10; f32 f14; f32 f18; } S_4F1928;
extern S_4F1928 D_001E2AC0;
extern V4_4F1928 D_001EAAA0;
extern u8 D_1A4BE0[];
extern void func_00440CF8(void *, f32, f32, f32);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern void func_0050D110(void *, s32, f32, f32, f32);
extern f32 func_0040C490(f32, f32);
extern f32 func_0040BF68(void *);
s32 func_004F1928(void) {
    V4_4F1928 a, b, c;
    Q_4F1928 x, y;
    u8 *g;
    func_00440CF8(&a, 10.0f, D_001E2AC0.f18, -D_001E2AC0.f14);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2AC0.v));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
    g = D_1A4BE0;
    if (func_003F8448(&D_001E2AC0, &a, 4, *(void **)(g + 0x25C0), 0) != 0) {
        func_0050D110(&b, 1, 0.5f, 0.0f, 0.5f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001EAAA0));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(c) : "j"(x));
        *(f32 *)(g + 0xBE4) = func_0040C490(c.x, c.y);
        *(f32 *)(g + 0xBE8) = func_0040C490(func_0040BF68(&c), c.z);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_004F1928 */
