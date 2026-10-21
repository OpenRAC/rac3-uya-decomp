#include "common.h"

/* localdecomp:start func_0030B3D0 */
typedef int Q_30B3D0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_30B3D0;
typedef struct {
    f32 f0, f4, f8;
    u8 padC[0x10 - 0xC];
    f32 f10, f14, f18;
    u8 pad1C[0x20 - 0x1C];
    Q_30B3D0 q20;
    V_30B3D0 v30;
    u8 pad40[0x50 - 0x40];
    f32 f50, f54, f58, f5C, f60, f64, f68, f6C, f70, f74, f78, f7C, f80, f84, f88, f8C, f90, f94;
    u8 pad98[0xA0 - 0x98];
    u8 *fA0;
    u8 padA4[0xB0 - 0xA4];
} S_30B3D0;
extern S_30B3D0 D_00271070[];
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040C2D0(void *, void *, void *);
extern s32 func_0040BA90(void *);

void func_0030B3D0(u8 *a0) {
    V_30B3D0 v;
    Q_30B3D0 a, b;
    S_30B3D0 *e, *g;
    u8 *t;
    s32 i;
    g = D_00271070;
    t = *(u8 **)(a0 + 0x68);
    for (i = 0; i < 16; i++) {
        e = &g[i];
        if (e->fA0 != a0) continue;
        e->f50 = func_0040CEC8(e->f50, e->f5C);
        e->f54 = func_0040CEC8(e->f54, e->f60);
        e->f58 = func_0040CEC8(e->f58, e->f64);
        e->f74 = func_0040CEC8(e->f74, e->f80);
        e->f78 = func_0040CEC8(e->f78, e->f84);
        e->f7C = func_0040CEC8(e->f7C, e->f88);
        e->f0 = func_0040C3C8(e->f50) * e->f68;
        e->f4 = func_0040C3E0(e->f54) * e->f6C;
        e->f8 = -func_0040C3E0(e->f58) * e->f70;
        e->f10 = func_0040C3C8(e->f74) * e->f8C;
        e->f14 = func_0040C3E0(e->f78) * e->f90;
        e->f18 = -func_0040C3E0(e->f7C) * e->f94;
        func_0040C2D0(&v, (u8 *)e + 0x40, a0 + 0xC0);
        e->q20 = *(Q_30B3D0 *)(a0 + 16);
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V_30B3D0 *)(a0 + 16)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(b) : "j"(b), "j"(a));
        __asm__("sqc2 %1, %0" : "=m"(e->v30) : "j"(b));
        if (func_0040BA90((u8 *)e + 0x98)) {
            e->fA0 = 0;
            *(s32 *)(t + 0x58) = *(s32 *)(t + 0x58) - 1;
        }
    }
}
/* localdecomp:end func_0030B3D0 */
