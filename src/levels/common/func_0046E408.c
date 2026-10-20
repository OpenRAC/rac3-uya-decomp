#include "common.h"

typedef struct {
    f32 *p;
    f32 radius;
    f32 angle;
    f32 speed;
    f32 rise;
    u8 step;
} Orbit_0046E408;

typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[3];
    f32 f12;
    f32 f16;
    f32 pad20;
    f32 f24;
    f32 pad28;
    Orbit_0046E408 o;
} Obj_0046E408;

extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern f32 func_0040CFB0(f32, f32);
extern void func_0045E580(Obj_0046E408 *);

void func_0046E408(Obj_0046E408 *m) {
    Orbit_0046E408 *o = &m->o;

    m->b8 += o->step;
    o->angle = func_0040CEC8(o->angle, o->speed);
    m->f12 += o->rise;
    m->f16 = m->o.p[0] + o->radius * func_0040C3C8(o->angle);
    m->f24 = m->o.p[2] + o->radius * func_0040C3E0(o->angle);
    if (func_0040CFB0(o->angle, m->o.p[4]) < __builtin_fabsf(o->speed + o->speed)) {
        func_0045E580(m);
    }
}
