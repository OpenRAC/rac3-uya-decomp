#include "common.h"

/* localdecomp:start func_00365F48 */
typedef int Q_365F48 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_365F48;
extern V4_365F48 D_001A4C60;
extern f32 D_001E1CB0;
extern f32 D_001E1CC0;
extern f32 D_001E1CD0;
extern f32 D_001E1CE4;
extern void func_004C41E8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040BE68(void *, void *, void *, f32);
void func_00365F48(void) {
    V4_365F48 a;
    V4_365F48 b;
    Q_365F48 x, y;
    func_004C41E8(&D_001A4C60, &a);
    func_0040BE90(&D_001E1CB0, &a, 0.5f);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E1CB0));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001A4C60));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(D_001E1CB0) : "j"(x));
    if (D_001E1CE4 > 0.0f) {
        func_0040BE68(&D_001E1CB0, &D_001E1CB0, &D_001E1CC0, D_001E1CE4 * 0.4f + 0.4f);
        func_0040BE90(&b, &D_001E1CD0, D_001E1CE4 * -0.55f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E1CB0));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(D_001E1CB0) : "j"(x));
    } else {
        func_0040BE68(&D_001E1CB0, &D_001E1CB0, &D_001E1CC0, 0.4f);
    }
}
/* localdecomp:end func_00365F48 */
