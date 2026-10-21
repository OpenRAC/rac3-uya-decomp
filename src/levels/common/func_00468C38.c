#include "common.h"

/* localdecomp:start func_00468C38 */
typedef int Q_468C38 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_468C38;
typedef struct {
    u8 pad0[0x10];
    V4_468C38 v10;
} G_468C38;
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    s16 fA;
    f32 fC;
    V4_468C38 v10;
    V4_468C38 v20;
    s32 f30;
    G_468C38 *f34;
} O_468C38;
typedef struct { u8 pad0[0x10]; s32 f10; G_468C38 *f14; } E_468C38;
extern G_468C38 *D_001A71A0[];
extern u8 *D_00221118[];
extern O_468C38 *func_0045E438(s32);
O_468C38 *func_00468C38(V4_468C38 *pos, s32 a5, u8 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, f32 f) {
    O_468C38 *o;
    G_468C38 *g;
    E_468C38 *e;
    Q_468C38 x, y, z;
    o = func_0045E438(0x3B);
    if (o != 0) {
        e = (E_468C38 *)((u8 *)o + 0x20);
        e->f14 = (G_468C38 *)a11;
        e->f10 = a10;
        g = D_001A71A0[0];
        e->f14 = g;
        if (a10 == 1 && g != 0) {
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(g->v10));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(o->v20) : "j"(z));
        }
        o->v10 = *pos;
        o->f4 = a5;
        o->f9 = 0x21;
        o->f3 = a8 ? 0x44 : 0x48;
        o->f8 = a6;
        o->f1 = 0;
        o->fC = f * 210000.0f;
        o->f2 = D_00221118[a7][0];
        o->fA = a9;
    }
    return o;
}
/* localdecomp:end func_00468C38 */
