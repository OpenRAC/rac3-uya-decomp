#include "common.h"

/* localdecomp:start func_005B8460 */
typedef int Q_5B8460 __attribute__((mode(TI)));
typedef union { struct { f32 x, y, z, w; } v; Q_5B8460 q; } __attribute__((aligned(16))) V_5B8460;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_5B8460;
extern void func_0058F7E8(void *, s32);
extern void func_0058F358(void *, void *, f32);

void func_005B8460(V4_5B8460 *pos, s32 *arg) {
    V_5B8460 v;
    Q_5B8460 a, b, r;

    v.q = 0;
    v.v.x = 3.1415925f;
    v.v.y = 3.1415925f;
    v.v.z = 3.1415925f;
    func_0058F7E8(pos, *arg);
    func_0058F358(pos, pos, 0.024639942f);
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*pos));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(v.v));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(*pos) : "j"(r));
}
/* localdecomp:end func_005B8460 */
