#include "common.h"

/* localdecomp:start func_005FC8C0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_5FC8C0;
typedef int Q_5FC8C0 __attribute__((mode(TI)));
extern void func_005FC9F8(s32, s32, V_5FC8C0 *);
extern void func_0058F358(V_5FC8C0 *, V_5FC8C0 *, f32);

void func_005FC8C0(s32 a, s32 b, V_5FC8C0 *v, f32 f) {
    V_5FC8C0 t;
    Q_5FC8C0 x, y;

    func_005FC9F8(a, b, &t);
    func_0058F358(&t, &t, f);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*v));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
    __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*v) : "j"(x));
}
/* localdecomp:end func_005FC8C0 */
