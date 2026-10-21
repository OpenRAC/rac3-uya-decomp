#include "common.h"

/* localdecomp:start func_00468430 */
typedef int Q_468430 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_468430;
typedef struct {
    u8 pad0[32];
    u8 b32;
    u8 pad33[137];
    s16 h170;
    u8 pad172[4];
} T_468430;
typedef struct {
    T_468430 *t;
    s32 i4;
    s32 i8;
    f32 f12;
} S_468430;
typedef struct {
    u8 pad0[16];
    V4_468430 a;
    V4_468430 b;
    S_468430 s;
} O_468430;
extern void func_0045E580(void *);
extern f32 func_004408C0(f32, f32);
extern void func_00437698(void *, s32, void *);
extern f32 func_0040BFB0(void *, void *);
extern void func_0040C0F0(void *, void *, f32);
void func_00468430(O_468430 *o) {
    S_468430 *s = &o->s;
    T_468430 *t = s->t;
    V4_468430 old;
    Q_468430 x, y;
    f32 f20, f21;
    V4_468430 *pa;
    if (t == 0 || t->h170 != s->i8 || t->b32 == 254 || t->b32 == 253) {
        func_0045E580(o);
        return;
    }
    f20 = s->f12 * func_004408C0(0.5f, 1.0f);
    pa = &o->a;
    old = o->a;
    f21 = o->b.w;
    if (s->i4 > 0) {
        func_00437698(s->t, s->i4, pa);
    } else {
        *pa = ((O_468430 *)s->t)->a;
    }
    if (func_0040BFB0(pa, &o->b) > 1.5f) {
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->a));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(old));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(old) : "j"(x));
        func_0040C0F0(&old, &old, 1.5f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(o->a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(old));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(o->b) : "j"(x));
    }
    o->a.w = f20;
    o->b.w = f21;
}
/* localdecomp:end func_00468430 */
