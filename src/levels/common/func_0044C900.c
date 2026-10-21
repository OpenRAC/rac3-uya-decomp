#include "common.h"

/* localdecomp:start func_0044C900 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_44C900;
typedef int Q_44C900 __attribute__((mode(TI)));
extern void func_00440CF8(void *);
void func_0044C900(V_44C900 *out, V_44C900 *b) {
    V_44C900 t;
    Q_44C900 x, y;
    func_00440CF8(&t);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
}
/* localdecomp:end func_0044C900 */
