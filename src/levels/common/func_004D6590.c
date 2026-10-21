#include "common.h"

/* localdecomp:start func_004D6590 */
typedef int Q_4D6590 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_4D6590;
typedef struct { V_4D6590 m[4]; } M_4D6590;
typedef struct {
    u8 pad[0x20];
    s8 b20;
} T_4D6590;
typedef struct {
    T_4D6590 *f0;
    s32 f4;
    u8 pad8[0xD - 0x8];
    u8 bD;
    u8 padE[0x10 - 0xE];
    V_4D6590 v10;
    u8 pad20[0x1C - 0x20 + 0x20];
} S_4D6590;
typedef struct {
    u8 pad0[4];
    u32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    V_4D6590 v10;
    S_4D6590 s;
} O_4D6590;
extern u8 D_001E13EC[];
extern f32 D_001E13F0[];
extern s32 func_0040BAC0(s16 *);
extern void func_0045E580(O_4D6590 *);
extern void func_00437600(T_4D6590 *, s32, M_4D6590 *);
extern void func_0040C2D0(V_4D6590 *, V_4D6590 *, M_4D6590 *);
void func_004D6590(O_4D6590 *o) {
    S_4D6590 *s = &o->s;
    M_4D6590 m;
    Q_4D6590 x, y;
    if (o->hA >= 0 && func_0040BAC0(&o->hA) != 0) {
        func_0045E580(o);
        return;
    }
    if (s->f0 != 0) {
        if (s->f0->b20 < 0) {
            func_0045E580(o);
            return;
        }
        func_00437600(s->f0, s->f4, &m);
        func_0040C2D0(&o->v10, &s->v10, &m);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->v10));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m.m[3]));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(o->v10) : "j"(x));
        o->v10.w = 0;
    } else {
        o->v10 = s->v10;
    }
    if (D_001E13EC[0] != 0) {
        o->w4 = (o->w4 & 0xFFFFFF) | ((s32)(D_001E13F0[0] * 128.0f) << 24);
    }
    o->fC = o->fC * *(f32 *)((u8 *)s + 0x1C);
    o->b8 = o->b8 + *(u8 *)((u8 *)s + 0xD);
}
/* localdecomp:end func_004D6590 */
