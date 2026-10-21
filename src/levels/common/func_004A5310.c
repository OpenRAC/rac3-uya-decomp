#include "common.h"

/* localdecomp:start func_004A5310 */
typedef int Q_004A5310 __attribute__((mode(TI)));
typedef struct {
    float x, y, z, w;
} __attribute__((aligned(16))) V4_004A5310;
extern V4_004A5310 D_001E2A40;
extern V4_004A5310 D_001EAAA0;
extern s32 D_001A30F4[];
extern void func_00440B30(void *, float, float);
extern s32 func_003F8448(void *, void *, s32, s32, s32);
extern void func_0040BE90(void *, void *, float);
void func_004A5310(V4_004A5310 *a0, V4_004A5310 *a1) {
    Q_004A5310 x, y, r;
    Q_004A5310 x2, y2, r2, r3;
    if (a1 == 0) {
        a1 = &D_001E2A40;
    }
    func_00440B30(a0, 0.5f, 6.0f);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a0));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a1));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*a0) : "j"(r));
    if (func_003F8448(a1, a0, 130, D_001A30F4[0], 0) != 0) {
        __asm__("lqc2 %0, %1" : "=j"(y2) : "m"(*a1));
        __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(D_001EAAA0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r2) : "j"(x2), "j"(y2));
        __asm__("sqc2 %1, %0" : "=m"(*a0) : "j"(r2));
        func_0040BE90(a0, a0, 0.75f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a1));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a0));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r3) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*a0) : "j"(r3));
    }
}
/* localdecomp:end func_004A5310 */
