#include "common.h"

/* localdecomp:start func_003181A0 */
typedef int Q_3181A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3181A0;
extern V4_3181A0 D_00274020[];
extern V4_3181A0 D_001A4CC0;
extern f32 func_004408C0(f32, f32);
extern f32 func_00440978(void);
extern void func_00440CF8(void *, f32, f32, f32);
void func_003181A0(void) {
    s32 i;
    V4_3181A0 *p = D_00274020;
    for (i = 24; i >= 0; i--) {
        Q_3181A0 a, b, c;
        f32 x = func_004408C0(0.01f, 7.0f);
        f32 y = func_00440978();
        f32 z = func_004408C0(0.0f, 3.1415927f);
        func_00440CF8(p, x, y, z);
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*p));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(D_001A4CC0));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(*p) : "j"(c));
        p++;
    }
}
/* localdecomp:end func_003181A0 */
