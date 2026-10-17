#include "common.h"

typedef struct {
    f32 target;
    f32 base;
    s32 b;
    s32 a;
    f32 scale;
} Sub;

typedef struct {
    char pad0[0x4];
    s32 result;
    char pad8[0xA - 0x8];
    s16 timer;
    f32 out;
    char vec[0x20 - 0x10];
    Sub sub;
} Obj;

extern s32 func_0040BAC0(s16 *);
extern void func_0045E580(Obj *);
extern void func_004C6EC8(void *, void *);
extern s32 func_0040D020(s32, s32, f32);

void func_00467CF8(Obj *o) {
    Sub *s;
    f32 t;

    if (func_0040BAC0(&o->timer) != 0) {
        func_0045E580(o);
        return;
    }
    s = &o->sub;
    func_004C6EC8(o->vec, o->vec);
    t = o->timer * s->scale;
    o->result = func_0040D020(s->a, s->b, t);
    o->out = ((o->sub.target - s->base) * t + s->base) * 210000.0f;
}
