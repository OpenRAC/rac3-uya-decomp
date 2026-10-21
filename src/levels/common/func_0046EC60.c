#include "common.h"

/* localdecomp:start func_0046EC60 */
typedef int Q_46EC60 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_46EC60;
typedef struct {
    f32 x, y, z;
    s32 c;
    u8 b10, b11, b12, b13;
    f32 f14, f18, f1C;
} P_46EC60;
typedef struct {
    u8 pad0[4];
    u32 color;
    u8 b8;
    u8 pad9;
    s16 h;
    f32 fC;
    V4_46EC60 pos;
    P_46EC60 v;
} O_46EC60;
extern void func_004C6EC8(void *, void *);
extern s32 func_0040D020(s32, s32, f32);
extern f32 func_00442070(f32);
extern f32 func_00442068(f32);
extern void func_0040BE90(void *, void *, f32);
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
void func_0046EC60(O_46EC60 *o) {
    V4_46EC60 n;
    V4_46EC60 d;
    P_46EC60 *v = &o->v;
    f32 t;
    d.x = o->v.x;
    d.y = v->y;
    d.z = v->z;
    d.w = 0.0f;
    func_004C6EC8(&o->pos, &o->pos);
    t = 1.0f - (f32)o->h / (f32)v->b11;
    if (v->b13 == 0) {
        o->color = func_0040D020(0x103080, v->c, t) | (v->b12 << 24);
        o->fC = v->f14 + (v->f18 - v->f14) * t;
        func_0040BE90(&n, &d, v->f1C * func_00442070(t));
    } else {
        f32 r = func_00442068(t);
        f32 b = (f32)v->b12;
        o->color = v->c | ((s32)(b - b * r) << 24);
        func_0040BE90(&n, &d, v->f1C);
    }
    {
        Q_46EC60 qa, qb, qr;
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(o->pos));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(n));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qb), "j"(qa));
        __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(qr));
    }
    o->b8 += v->b10;
    if (func_0040BAC0(&o->h) != 0) {
        if (v->b13 == 0) {
            v->b13 = 1;
            v->b11 = 20;
            o->h = 20;
        } else {
            func_0045E580(o);
        }
    }
}
/* localdecomp:end func_0046EC60 */
