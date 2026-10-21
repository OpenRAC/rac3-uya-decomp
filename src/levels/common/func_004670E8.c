#include "common.h"

/* localdecomp:start func_004670E8 */
typedef int Q_4670E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4670E8;
typedef struct {
    f32 x, y, z;
    f32 fC;
    u8 b10, b11, b12, b13;
    f32 f14, f18;
    s16 h1C, h1E;
} P_4670E8;
typedef struct {
    u8 pad0[4];
    u32 color;
    u8 b8;
    u8 pad9;
    s16 h;
    f32 fC;
    V4_4670E8 pos;
    P_4670E8 v;
} O_4670E8;
extern V4_4670E8 D_001A4EC0;
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);
extern void func_004C6EC8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
void func_004670E8(O_4670E8 *o) {
    V4_4670E8 d;
    V4_4670E8 e;
    P_4670E8 *v;
    f32 ratio;
    Q_4670E8 qa, qb;
    V4_4670E8 *p;
    if (func_0040BAC0(&o->h) != 0) {
        func_0045E580(o);
        return;
    }
    v = &o->v;
    p = &o->pos;
    ratio = (f32)o->h / (f32)v->h1C;
    d.w = 0.0f;
    d.x = o->v.x;
    o->color = ((s32)((f32)v->h1E * ratio) << 24) | (v->b13 << 16) | (v->b12 << 8) | v->b11;
    d.y = v->y;
    d.z = v->z;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(d));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(o->pos));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(qa));
    if (o->pos.w != d.w) {
        if (o->pos.w == 2.0f) {
            func_004C6EC8(p, p);
        }
        o->pos.w = 2.0f;
    }
    func_0040BE90(&e, &D_001A4EC0, v->fC);
    {
        Q_4670E8 qc, qd;
        __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(qd) : "m"(e));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qc) : "j"(qc), "j"(qd));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qc));
    }
    func_0040BE90(&d, &d, v->f18);
    v->x = d.x;
    v->y = d.y;
    v->z = d.z;
    o->b8 += v->b10;
    o->fC += v->f14;
}
/* localdecomp:end func_004670E8 */
