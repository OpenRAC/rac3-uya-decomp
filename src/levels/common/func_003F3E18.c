#include "common.h"

/* localdecomp:start func_003F3E18 */
typedef int Q_003F3E18 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003F3E18;
extern f32 func_0040BF68(void *);
extern f32 func_0040C490(f32, f32);
extern void func_0040CF10(f32, f32);
extern f32 func_0040BF38(void *);
s32 func_003F3E18(f32 *a0, V4_003F3E18 *a1, V4_003F3E18 *a2) {
    V4_003F3E18 t;
    Q_003F3E18 x, y;
    f32 f;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a1));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a2));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(t) : "j"(x));
    a0[1] = func_0040C490(func_0040BF68(&t), t.z);
    f = func_0040C490(t.x, t.y);
    func_0040CF10(f, a0[0]);
    a0[0] = f;
    a0[2] = func_0040BF38(&t);
    return 0;
}
/* localdecomp:end func_003F3E18 */
