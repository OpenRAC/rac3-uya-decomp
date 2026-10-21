#include "common.h"

/* localdecomp:start func_00459BC8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_459BC8;
typedef int Q_459BC8 __attribute__((mode(TI)));
extern void func_00459BF8(void *, void *, void *);
void func_00459BC8(V_459BC8 *a, V_459BC8 *b) {
    V_459BC8 t;
    Q_459BC8 x, y;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_459BC8 *)((u8 *)a + 16)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(x));
    func_00459BF8(a, b, &t);
}
/* localdecomp:end func_00459BC8 */
