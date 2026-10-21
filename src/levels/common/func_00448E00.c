#include "common.h"

/* localdecomp:start func_00448E00 */
typedef int Q_448E00 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_448E00;
extern u8 *D_001E01A4;
extern void func_0040C2D0(void *, void *, void *);
extern f32 func_0040BF38(void *);
s32 func_00448E00(V4_448E00 *p, s32 i) {
    V4_448E00 a;
    V4_448E00 b;
    Q_448E00 x, y;
    u8 *e;
    if (i >= 0) {
        e = D_001E01A4 + i * 128;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*p));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_448E00 *)(e + 0x30)));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
        a.w = 0.0f;
        func_0040C2D0(&b, &a, e + 0x40);
        if (func_0040BF38(&b) < 1.0f) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_00448E00 */
