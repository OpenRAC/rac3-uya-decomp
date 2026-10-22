#include "common.h"

/* localdecomp:start func_005FC918 */
typedef int Q_005FC918 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_005FC918;
extern void func_0058F5B0(void *, void *, f32);
extern void func_0058F358(void *, void *, f32);
extern s32 func_0057F278(void *, void *, s32, s32, s32);
extern s32 func_00583560(void);

s32 func_005FC918(V4_005FC918 *dir, V4_005FC918 *pos, V4_005FC918 *out, s32 hit, f32 len) {
    V4_005FC918 v;
    Q_005FC918 x, y;
    if (hit != 0) {
        func_0058F5B0(&v, dir, -6.0f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(x));
        if (func_0057F278(pos, &v, 2, 0, 0) == 0 || func_00583560() != 2) {
            __asm__("vmr32.xyzw %0, $vf0" : "=j"(x));
            __asm__("sqc2 %1, %0" : "=m"(*dir) : "j"(x));
            func_0058F358(dir, dir, len);
            hit = 0;
        }
    }
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*dir));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*out));
    __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*out) : "j"(x));
    return hit;
}
/* localdecomp:end func_005FC918 */
