#include "common.h"

/* localdecomp:start func_0046B340 */
typedef int Q_46B340 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_46B340;
typedef struct {
    f32 x, y, z, pad;
    f32 dx, dy, dz;
    V_46B340 *p;
} S_46B340;
typedef struct {
    u8 pad0[4];
    u32 f4;
    u8 pad8[2];
    s16 fA;
    u8 padC[4];
    f32 f10, f14, f18;
    u8 pad1C[4];
    S_46B340 s;
} O_46B340;
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern u32 func_0040D020(u32, u32, f32);

void func_0046B340(O_46B340 *o) {
    S_46B340 *s = &o->s;
    Q_46B340 a, b, c;
    if (s->p != 0) {
        s->x += s->dx;
        s->y += s->dy;
        s->z += s->dz;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*(V_46B340 *)((u8 *)s->p + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(*(V_46B340 *)&s->x));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
        __asm__ __volatile__("sqc2 %1, %0" : "=m"(*(V_46B340 *)&o->f10) : "j"(c));
    } else {
        o->f10 += s->dx;
        o->f14 += s->dy;
        o->f18 += s->dz;
    }
    if (func_0040BAC0(&o->fA)) {
        func_0045E580(o);
        return;
    }
    if (s->p != 0) {
        o->f4 = func_0040D020(o->f4 & 0xFFFFFF, o->f4, (f32)(o->fA - 1) / (f32)o->fA);
    } else {
        o->f4 = func_0040D020(0, o->f4, (f32)(o->fA - 1) / (f32)o->fA);
    }
}
/* localdecomp:end func_0046B340 */
