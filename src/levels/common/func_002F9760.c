#include "common.h"
typedef struct {
    u8 pad0[20];
    s32 total;
    f32 scale;
    s16 timer;
    s16 f1E;
} Sub_002F9760;
typedef struct {
    u8 pad0[35];
    u8 f23;
    u8 pad24[8];
    f32 f2C;
    u8 pad30[56];
    Sub_002F9760 *sub;
    u8 pad6C[132];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} Obj_002F9760;
extern f32 func_0040CEC8(f32, f32);
extern s32 func_0040BAC0(s16 *);
extern void func_00436220(Obj_002F9760 *);
void func_002F9760(Obj_002F9760 *o) {
    Sub_002F9760 *s;
    f32 k;
    s32 half;
    s = o->sub;
    k = 0.0523598827f;
    o->f2C = (f32)(s->total - s->timer) * s->scale / (f32)s->total;
    o->fF0 = func_0040CEC8(o->fF0, k);
    o->fF4 = func_0040CEC8(o->fF4, k);
    o->fF8 = func_0040CEC8(o->fF8, k);
    if (func_0040BAC0(&s->timer) != 0) {
        func_00436220(o);
        return;
    }
    half = s->total / 2;
    if (s->timer < half) {
        o->f23 = (s->timer * s->f1E) / half;
    }
}
