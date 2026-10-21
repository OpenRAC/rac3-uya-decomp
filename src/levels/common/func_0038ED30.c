#include "common.h"

/* localdecomp:start func_0038ED30 */
typedef int Q_38ED30 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_38ED30;
typedef struct {
    u8 pad0[3];
    u8 f3;
} P_38ED30;
extern f32 func_00440978(void);
extern f32 func_004408C0(f32, f32);
extern s32 func_00440878(s32, s32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern P_38ED30 *func_00467BD8(void *, s32, s32, s32, f32, f32);
extern s32 func_00440848(s32);
void func_0038ED30(V_38ED30 *obj) {
    V_38ED30 v;
    Q_38ED30 a, b, c;
    f32 ang, k1, k2, k3, k4;
    s32 i, r;
    P_38ED30 *p;
    for (i = 0; i >= 0; i--) {
        ang = func_00440978();
        k1 = func_004408C0(0.0f, 0.6f);
        k2 = func_004408C0(0.0f, 1.5f);
        k3 = func_004408C0(1.0f, 5.0f);
        r = func_00440878(100, 160);
        v.x = func_0040C3C8(ang) * k1;
        v.y = func_0040C3E0(ang) * k1;
        v.z = 0.0f;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*obj));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(c));
        p = func_00467BD8(&v, 0x5005C162, 0x5C162, r, k2, k3);
        if (p != 0) {
            p->f3 = func_00440848(3) ? 72 : 68;
        }
    }
}
/* localdecomp:end func_0038ED30 */
