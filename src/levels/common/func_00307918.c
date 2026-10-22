#include "common.h"

/* localdecomp:start func_00307918 */
typedef int Q_307918 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_307918;
typedef struct { u8 pad0[0xA]; s16 fA; } P_307918;
extern f32 D_001DFAA8[1];
extern s32 D_001D66B0;
extern f32 func_004183E0(void);
extern f32 func_00418328(f32 lo, f32 hi);
extern f32 func_003E4B30(f32 a);
extern f32 func_003E4B48(f32 a);
extern s32 func_004182E0(s32 lo, s32 hi);
extern s32 func_004182B0(s32 n);
extern void func_0043BBC8(V_307918 *pos, V_307918 *v, s32 a, s32 b);
extern void func_004184F0(V_307918 *v, f32 a, f32 b);
extern P_307918 *func_0043DCC8(V_307918 *v, void *a, f32 *b, f32 c, f32 d);

void func_00307918(void *unused, V_307918 *pos) {
    V_307918 v;
    Q_307918 a, b;
    f32 ang, r;
    s32 i;
    s32 t;
    P_307918 *p;
    for (i = 15; i >= 0; i--) {
        ang = func_004183E0();
        r = func_00418328(0.0f, 0.0500000045f);
        v.x = func_003E4B30(ang) * r;
        v.y = func_003E4B48(ang) * r;
        v.z = func_00418328(0.0500000045f, 0.108333342f);
        t = func_004182E0(0x5A, 0x78);
        func_0043BBC8(pos, &v, func_004182B0(2), t);
    }
    for (i = 0; i < 16; i++) {
        func_004184F0(&v, 1.0f, 1.0f);
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(a));
        v.z = D_001DFAA8[0] + 0.05f;
        p = func_0043DCC8(&v, &D_001D66B0, D_001DFAA8, func_00418328(0.7f, 1.0f), i == 0 ? 2.0f : -2.0f);
        if (p != 0) {
            p->fA = func_00418328(30.0f, 60.0f);
        }
    }
}
/* localdecomp:end func_00307918 */
