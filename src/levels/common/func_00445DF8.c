#include "common.h"

/* localdecomp:start func_00445DF8 */
typedef int Q_00445DF8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00445DF8;
extern void func_0040C0F0(void *, void *, f32);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
void func_00445DF8(V4_00445DF8 *a0, V4_00445DF8 *a1, V4_00445DF8 *a2, f32 f12) {
    V4_00445DF8 t0, t1;
    Q_00445DF8 x, y;
    func_0040C0F0(&t1, a2, 1.0f);
    func_0040BE90(&t0, &t1, func_0040BEF8(&t1, a1) * f12);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a1));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t0));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*a0) : "j"(x));
}
/* localdecomp:end func_00445DF8 */
