#include "common.h"

/* localdecomp:start func_005B83E8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_5B83E8;
typedef int Q_5B83E8 __attribute__((mode(TI)));
extern void func_0058F358(void *, void *, f32);
extern s32 func_0058F800(void *);

void func_005B83E8(V_5B83E8 *a, s32 *out) {
    V_5B83E8 t;
    V_5B83E8 k;
    Q_5B83E8 x, y;

    *(Q_5B83E8 *)&k = 0;
    k.x = 3.1415925f;
    k.y = 3.1415925f;
    k.z = 3.1415925f;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(k));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(x));
    func_0058F358(&t, &t, 40.58451f);
    *out = func_0058F800(&t);
}
/* localdecomp:end func_005B83E8 */
