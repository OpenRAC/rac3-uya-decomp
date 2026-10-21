#include "common.h"

typedef int Q_459A98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_459A98;
typedef struct {
    u8 pad0[0x10];
    V_459A98 v10;
} O_459A98;
typedef struct {
    u8 pad0[8];
    f32 f8;
    f32 fC;
    u8 pad10[0x40];
    Q_459A98 q50;
    u8 pad60[0x28];
    s32 f88;
    s32 f8C;
    f32 f90;
    u8 pad94[0x44];
    s32 fD8;
} W_459A98;
typedef struct { u8 pad0[0x18]; s32 f18; s32 f1C; } G_459A98;

extern Q_459A98 D_001EAAA0;
extern void func_0044DF40(void *, void *, s32);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern f32 func_0044E300(void *);

/* localdecomp:start func_00459A98 */
void func_00459A98(O_459A98 *o, W_459A98 *w) {
    V_459A98 t;
    V_459A98 t2;
    V_459A98 t3;
    Q_459A98 x, y, z;
    func_0044DF40(&o->v10, &t, 1);
    func_0040C0F0(&t2, &t, w->f8 + 0.1f);
    func_0040C0F0(&t3, &t, -w->fC - 0.1f);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t2));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(t2) : "j"(x));
    __asm__("lqc2 %0, %1" : "=j"(z) : "m"(t3));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(z), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(t3) : "j"(z));
    if (func_003F8448(&t2, &t3, 0, o, 0) != 0) {
        G_459A98 *g;
        w->f90 = func_0044E300(&D_001EAAA0);
        g = (G_459A98 *)&D_001EAAA0 - 1;
        w->f88 = g->f18;
        w->f8C = g->f1C;
        w->fD8 = -1;
        func_0040C0F0(&w->q50, (u8 *)&D_001EAAA0 + 0x20, 1.0f);
    } else {
        w->f90 = 0;
        w->fD8 = -1;
        __asm__ __volatile__("sq $0,%0" : "=m"(w->q50));
        w->f8C = 0;
        w->f88 = 0;
    }
}
/* localdecomp:end func_00459A98 */
