#include "common.h"

/* localdecomp:start func_00557A90 */
typedef int Q_00557A90 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00557A90;
extern f32 func_0058F4B0(V4_00557A90 *, V4_00557A90 *);

f32 func_00557A90(V4_00557A90 *a, V4_00557A90 *b, f32 r) {
    V4_00557A90 tmp;
    V4_00557A90 d;
    Q_00557A90 x, y;
    f32 dist;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
    tmp = d;
    dist = func_0058F4B0(a, b);
    if (r * 3.0f < dist) {
        return 0.5235988f;
    }
    if (r * 1.5f < dist) {
        return 1.0471976f;
    }
    return 2.0943952f;
}
/* localdecomp:end func_00557A90 */
