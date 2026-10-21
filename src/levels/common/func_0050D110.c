#include "common.h"

/* localdecomp:start func_0050D110 */
typedef int Q_50D110 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_50D110;
extern V_50D110 D_001A4BE0[];
extern void func_0040C2F8(void *, void *, void *);
void func_0050D110(V_50D110 *v, s32 flag, f32 x, f32 y, f32 z) {
    Q_50D110 a, b;
    __asm__("sq $0, %0" : "=m"(*v));
    v->x = x;
    v->y = y;
    v->z = z;
    func_0040C2F8(v, v, D_001A4BE0);
    if (flag) {
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(D_001A4BE0[8]));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*v));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(*v) : "j"(a));
    }
}
/* localdecomp:end func_0050D110 */
