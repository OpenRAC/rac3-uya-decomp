#include "common.h"

/* localdecomp:start func_00639128 */
/* PROVISIONAL, VU0 j-constraint form. */
typedef int Q_00639128 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00639128;
extern V_00639128 D_0025F860[];
extern void func_005B2950(V_00639128 *, f32, f32, f32);
extern s32 func_0057F278(u8 *, V_00639128 *, s32, s32, s32);
extern void func_0062F938(u8 *, V_00639128 *, s32, f32, f32, f32);
extern f32 func_0058F980(f32, f32);
extern f32 func_0058F430(V_00639128 *);

s32 func_00639128(u8 *o) {
    V_00639128 a;
    V_00639128 b;
    V_00639128 c;
    Q_00639128 x, y, r;
    func_005B2950(&a, 10.0f, *(f32 *)(o + 0x23B8), -*(f32 *)(o + 0x23B4));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_00639128 *)(o + 0x23A0)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(r));
    if (func_0057F278(o + 0x23A0, &a, 4, *(s32 *)(o + 0x2524), 0) != 0) {
    func_0062F938(o, &b, 1, 0.5f, 0.0f, 0.5f);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_0025F860[0]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(c) : "j"(r));
    *(f32 *)(o + 0x1084) = func_0058F980(c.x, c.y);
    *(f32 *)(o + 0x1088) = func_0058F980(func_0058F430(&c), c.z);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00639128 */
