#include "common.h"

/* localdecomp:start func_0062F0A0 */
typedef int Q_0062F0A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0062F0A0;
extern void func_0058F5B0(void *, void *, f32);
extern void func_005B6330(V4_0062F0A0 *, V4_0062F0A0 *);

void func_0062F0A0(u8 *a0, V4_0062F0A0 *a, V4_0062F0A0 *b, s32 mode, f32 fa, f32 fb) {
    V4_0062F0A0 v;
    Q_0062F0A0 x, y;
    if (mode != 0) {
        func_0058F5B0(&v, *(u8 **)(a0 + 0x2524) + 0xE0, fb);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_0062F0A0 *)(a0 + 0xA0)));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*b) : "j"(x));
        func_0058F5B0(&v, *(u8 **)(a0 + 0x2524) + 0xE0, fa);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_0062F0A0 *)(a0 + 0xA0)));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*a) : "j"(x));
        {
            V4_0062F0A0 t = *a;
            func_005B6330(&t, b);
        }
        return;
    }
    v = *(V4_0062F0A0 *)(a0 + 0xA0);
    *b = v;
    b->z += fb;
    if (b->z < 0.0f) {
        b->z = 0.0f;
    }
    *a = v;
    a->z += fa;
}
/* localdecomp:end func_0062F0A0 */
