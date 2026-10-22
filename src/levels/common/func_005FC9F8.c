#include "common.h"

/* localdecomp:start func_005FC9F8 */
/* PROVISIONAL, VU0 j-constraint form. */
typedef int Q_005FC9F8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_005FC9F8;
extern void func_0058F5B0(V_005FC9F8 *, V_005FC9F8 *, f32);
extern s32 func_0057F278(V_005FC9F8 *, V_005FC9F8 *, s32, s32, s32);
extern s32 func_00583560(void);

void func_005FC9F8(u8 *o, V_005FC9F8 *a, V_005FC9F8 *out) {
    V_005FC9F8 t;
    V_005FC9F8 u;
    Q_005FC9F8 x, y, r;
    if (o != 0 && *(s16 *)(o + 0x2D8) != 0) {
        *out = *(V_005FC9F8 *)(*(u8 **)(o + 0x2524) + 0xE0);
        func_0058F5B0(&t, out, 0.1f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(t) : "j"(y));
        func_0058F5B0(&u, out, -6.0f);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(u));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(u) : "j"(r));
        if (func_0057F278(&t, &u, 2, 0, 0) != 0 && func_00583560() == 2) {
            return;
        }
    }
    __asm__ __volatile__(
        "vmr32.xyzw $vf1, $vf0\n"
        "sqc2 $vf1, 0(%0)\n"
        : : "r"(out) : "memory");
}
/* localdecomp:end func_005FC9F8 */
