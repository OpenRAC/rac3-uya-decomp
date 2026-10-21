#include "common.h"

/* localdecomp:start func_004F0928 */
typedef int Q_4F0928 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4F0928;
extern V4_4F0928 D_001A4D40;
extern f32 func_0050D430(void *);
extern void func_0050D530(void *, void *, f32);
extern void func_0050D5B0(void *, void *, f32);
void func_004F0928(f32 a) {
    Q_4F0928 p, q, r;
    f32 f = func_0050D430(&D_001A4D40);
    if (f > 0.001f) {
        f32 z = 0.0f;
        f32 g;
        func_0050D530(&D_001A4D40, &D_001A4D40, z);
        g = f - a;
        if (g < z) g = z;
        func_0050D5B0(&D_001A4D40, &D_001A4D40, g);
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(D_001A4D40));
        __asm__("lqc2 %0, %1" : "=j"(p) : "m"(*(V4_4F0928 *)((u8 *)&D_001A4D40 - 0x70)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(p), "j"(q));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_4F0928 *)((u8 *)&D_001A4D40 - 0x70)) : "j"(r));
    } else {
        __asm__("sq $0, 0(%0)" : : "r"(&D_001A4D40) : "memory");
    }
}
/* localdecomp:end func_004F0928 */
