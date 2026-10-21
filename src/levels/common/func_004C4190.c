#include "common.h"

/* localdecomp:start func_004C4190 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4C4190;
typedef int Q_4C4190 __attribute__((mode(TI)));
extern void func_004C41E8(s32, void *);
extern void func_0040BE90(void *, void *, f32);
void func_004C4190(s32 a0, V_4C4190 *v, f32 a) {
    V_4C4190 t;
    Q_4C4190 x, y;
    func_004C41E8(a0, &t);
    func_0040BE90(&t, &t, a);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*v));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*v) : "j"(x));
}
/* localdecomp:end func_004C4190 */
