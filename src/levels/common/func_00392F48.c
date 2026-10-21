#include "common.h"

/* localdecomp:start func_00392F48 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_392F48;
typedef struct { u8 pad[20]; s32 i20; } P_392F48;
typedef struct { u8 pad[16]; u8 m16[16]; u8 b32; u8 pad33[71]; P_392F48 *p104; } O_392F48;
typedef struct {
    u8 pad[48];
    O_392F48 *p48;
    u8 pad52[4];
    s32 i56;
    u8 pad60[4];
    s32 i64;
    s32 i68;
} W_392F48;
typedef struct {
    V4_392F48 v0;
    V4_392F48 v16;
    u8 pad32[4];
    f32 f36;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f52;
    f32 f56;
    f32 f60;
    f32 f64;
    f32 f68;
    f32 f72;
    f32 f76;
    s32 i80;
    s32 i84;
    s32 i88;
    s32 i92;
    s32 i96;
    s32 i100;
    s32 i104;
    s32 i108;
    u8 pad112[4];
    s32 i116;
    s32 i120;
    W_392F48 *w;
} E_392F48;
extern E_392F48 *D_001E209C;
extern f32 func_00442068(f32);
extern f32 func_00442070(f32);
extern s32 func_0040D020(s32, s32, f32);
extern void func_0040C0F0(V4_392F48 *, V4_392F48 *, f32);
extern void func_0044DF40(void *, V4_392F48 *, s32);
extern f32 func_0040CEC8(f32, f32);
extern s32 func_00440878(s32, s32);
extern s32 func_0040BA90(s32 *);
void func_00392F48(W_392F48 *own) {
    V4_392F48 a;
    V4_392F48 b;
    V4_392F48 c;
    E_392F48 *e;
    O_392F48 *o;
    P_392F48 *p;
    s32 i;
    f32 t;
    f32 r;

    __asm__("sq $0,%0" : "=m"(*(u128_t *)&a));
    for (i = 0; i < 300; i++) {
        e = (E_392F48 *)((i << 7) + (s32)D_001E209C);
        if (e->w != own) {
            continue;
        }
        t = 1.0f - (f32)e->i84 / (f32)e->i88;
        if (e->i116 == 0) {
            e->i104 = func_0040D020(e->i100, e->i108, t);
            e->f44 = e->f40 + (e->f48 - e->f40) * t;
            e->f60 = e->f56 + (e->f64 - e->f56) * t;
            e->f72 = e->f68 + (e->f76 - e->f68) * t;
            func_0040C0F0(&a, &e->v16, e->f36 * func_00442070(t));
        } else if (e->i116 == 1) {
            r = func_00442068(t);
            e->i96 = e->i92 - e->i92 * r;
            if (e->i120 != 2) {
                e->i104 = func_0040D020(e->i100, e->i108, t);
                e->f44 = e->f40 + (e->f48 - e->f40) * t;
                e->f60 = e->f56 + (e->f64 - e->f56) * t;
                e->f72 = e->f68 + (e->f76 - e->f68) * t;
                func_0040C0F0(&a, &e->v16, e->f36 * func_00442070(t));
            } else {
                func_0040C0F0(&a, &e->v16, e->f36);
            }
        }
        func_0044DF40(own->p48->m16, &b, 1);
        func_0040C0F0(&c, &b, e->f60);
        __asm__(
            "lqc2 $vf1, %1\n"
            "lqc2 $vf2, %2\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "=m"(e->v0) : "m"(e->v0), "m"(c));
        if (e->i120 != 1) {
            __asm__ __volatile__(
                "lqc2 $vf1, %1\n"
                "lqc2 $vf2, %0\n"
                "vadd.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, %0\n"
                : : "m"(e->v0), "m"(a) : "memory");
        }
        o = e->w->p48;
        p = o->p104;
        e->f52 = func_0040CEC8(e->f52, e->f44);
        if (o->b32 == 2 && p->i20 < 38 && e->i120 != 2) {
            s32 v;
            e->i116 = 1;
            v = func_00440878(30, 45);
            e->i88 = e->i84 = v;            
            e->f68 = e->f72;
            e->i100 = e->i104;
            e->f56 = e->f60;
            e->i92 = e->i96;
            e->f40 = e->f44;
        }
        if (func_0040BA90(&e->i84) == 0) {
            continue;
        }
        if (e->i116 == 0) {
            e->i116 = 1;
            if (e->i120 == 1) {
                e->i88 = 30;
                e->i84 = 30;
            } else {
                e->i88 = 55;
                e->i84 = 55;
            }
        } else if (e->i96 > 0) {
            e->i116 = 2;
            e->i96--;
        } else {
            e->w->i56--;
            switch (e->i120) {
            case 0:
                e->w->i64--;
                break;
            case 1:
                e->w->i68--;
                break;
            }
            e->w = 0;
        }
    }
}
/* localdecomp:end func_00392F48 */
