#include "common.h"

/* localdecomp:start func_003D99B8 */
typedef int Q_3D99B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3D99B8;
typedef struct {
    V_3D99B8 v0;
    V_3D99B8 v10;
    s32 f20;
    f32 f24;
    f32 f28;
    s32 f2C;
} P_3D99B8;
typedef struct {
    u8 pad[0x10];
    V_3D99B8 v10;
} O_3D99B8;
extern P_3D99B8 D_002A2EC0[];
extern void func_004C41E8(V_3D99B8 *, V_3D99B8 *);
extern void func_0040CCA0(V_3D99B8 *, V_3D99B8 *, V_3D99B8 *, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3E0(f32);
extern f32 func_004408C0(f32, f32);
extern void func_003D9858(void);
extern void func_004026A0(void (*)(void), O_3D99B8 *);
void func_003D99B8(O_3D99B8 *o) {
    V_3D99B8 a, t;
    Q_3D99B8 x, y, r;
    P_3D99B8 *p;
    f32 s;
    s32 i;
    func_004C41E8(&o->v10, &a);
    for (i = 0; i < 64; i++) {
        p = &D_002A2EC0[i];
        if (p->f20 != 0) {
            func_0040CCA0(&t, &p->v10, &a, p->f28);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(p->v0) : "j"(r));
            p->f28 = func_0040CEC8(p->f28, p->f24);
            s = func_0040C3E0(p->f28);
            p->v0.z = p->v0.z + s * func_004408C0(0.01f, 0.015f);
        }
    }
    func_004026A0(func_003D9858, o);
}
/* localdecomp:end func_003D99B8 */
