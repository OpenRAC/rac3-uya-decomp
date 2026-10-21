#include "common.h"

/* localdecomp:start func_00312F80 */
typedef int s128 __attribute__((mode(TI)));
typedef union {
    s128 q;
    f32 f[4];
} Vec4;

typedef struct {
    u8 pad0[20];
    s32 w20;
} Obj312F80Y;

typedef struct {
    u8 pad0[32];
    u8 b32;
    u8 pad21[71];
    Obj312F80Y *y;
} Obj312F80X;

typedef struct {
    u8 pad0[48];
    Obj312F80X *x;
    s32 pad52;
    s32 w56;
    s32 pad60;
    s32 w64;
    s32 w68;
} Owner312F80;

typedef struct {
    Vec4 pos;
    Vec4 dir;
    s32 pad32;
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
    s32 pad80;
    s32 timer;
    s32 total;
    s32 w92;
    s32 w96;
    s32 w100;
    s32 w104;
    s32 w108;
    s32 pad112;
    s32 state;
    s32 type;
    Owner312F80 *owner;
} Ent312F80;

extern s32 D_001E17B4;

extern f32 func_00442068(f32);
extern f32 func_00442070(f32);
extern s32 func_0040D020(s32, s32, f32);
extern void func_0040C0F0(Vec4 *, Vec4 *, f32);
extern void func_0044DF40(void *, Vec4 *, s32);
extern f32 func_0040CEC8(f32, f32);
extern s32 func_00440878(s32, s32);
extern s32 func_0040BA90(s32 *);

void func_00312F80(Owner312F80 *arg) {
    Vec4 off;
    Vec4 dir;
    Vec4 step;
    s32 i;
    s32 one;

    __asm__("sq $0,%0" : "=m"(off.q));
    for (i = 0; i < 320; i++) {
        Ent312F80 *e = (Ent312F80 *)((i << 7) + D_001E17B4);
        f32 t;
        Obj312F80X *x;
        Obj312F80Y *y;

        if (e->owner != arg) {
            continue;
        }
        t = 1.0f - (f32)e->timer / (f32)e->total;
        if (e->state == 0) {
            e->w104 = func_0040D020(e->w100, e->w108, t);
            e->f44 = e->f40 + (e->f48 - e->f40) * t;
            e->f60 = e->f56 + (e->f64 - e->f56) * t;
            e->f72 = e->f68 + (e->f76 - e->f68) * t;
            func_0040C0F0(&off, &e->dir, e->f36 * func_00442070(t));
        } else if (e->state == 1) {
            e->w96 = e->w92 - e->w92 * func_00442068(t);
            if (e->type != 2) {
                e->w104 = func_0040D020(e->w100, e->w108, t);
                e->f44 = e->f40 + (e->f48 - e->f40) * t;
                e->f60 = e->f56 + (e->f64 - e->f56) * t;
                e->f72 = e->f68 + (e->f76 - e->f68) * t;
                func_0040C0F0(&off, &e->dir, e->f36 * func_00442070(t));
            } else {
                func_0040C0F0(&off, &e->dir, e->f36);
            }
        }
        one = 1;
        func_0044DF40((u8 *)arg->x + 16, &dir, one);
        func_0040C0F0(&step, &dir, e->f60);
        __asm__ __volatile__(
            "lqc2 vf1,%1\n"
            "lqc2 vf2,%2\n"
            "vadd.xyz vf1,vf1,vf2\n"
            "sqc2 vf1,%0\n"
            : "=m"(e->pos) : "m"(e->pos), "m"(step));
        if (e->type != one) {
            __asm__ __volatile__(
                "lqc2 vf1,%1\n"
                "lqc2 vf2,%2\n"
                "vadd.xyz vf1,vf1,vf2\n"
                "sqc2 vf1,%0\n"
                : "=m"(e->pos) : "m"(off), "m"(e->pos));
        }
        x = e->owner->x;
        y = x->y;
        e->f52 = func_0040CEC8(e->f52, e->f44);
        if (x->b32 == 2 && y->w20 < 38 && e->type != 2) {
            s32 n;
            e->state = one;
            n = func_00440878(30, 45);
            e->timer = n;
            e->total = n;
            e->f68 = e->f72;
            e->w100 = e->w104;
            e->f56 = e->f60;
            e->w92 = e->w96;
            e->f40 = e->f44;
        }
        if (func_0040BA90(&e->timer) == 0) {
            continue;
        }
        if (e->state == 0) {
            s32 n;
            e->state = 1;
            if (e->type == 1) {
                n = 30;
                e->timer = n;
            } else {
                n = 55;
                e->timer = n;
            }
            e->total = n;
        } else if (e->w96 > 0) {
            e->state = 2;
            e->w96--;
        } else {
            e->owner->w56--;
            switch (e->type) {
            case 0:
                e->owner->w64--;
                break;
            case 1:
                e->owner->w68--;
                break;
            }
            e->owner = 0;
        }
    }
}
/* localdecomp:end func_00312F80 */
