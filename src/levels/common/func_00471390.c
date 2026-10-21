#include "common.h"

typedef int Q_471390 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_471390;

typedef struct {
    V4_471390 v;
    s32 pad10;
    s16 h20;
    s16 h22;
    s32 pad18;
    f32 f28;
} Vel_471390;

typedef struct {
    s32 pad0;
    u32 color;
    u8 b8;
    u8 pad9;
    s16 h10;
    s32 pad0C;
    V4_471390 pos;
    Vel_471390 vel;
} Obj_471390;

extern V4_471390 D_001A4C60;
typedef struct {
    u8 pad0[0x170];
    f32 f170;
} G_471390;
extern s32 D_001DFBC0;
extern V4_471390 D_001E2900;
extern void func_004C6EC8(V4_471390 *a, V4_471390 *b);
extern void func_0040BE90(V4_471390 *a, V4_471390 *b, f32 s);
extern f32 func_0040BFB0(V4_471390 *a, V4_471390 *b);
extern f32 func_004408C0(f32 lo, f32 hi);
extern void func_0040C0F0(V4_471390 *a, V4_471390 *b, f32 s);
extern f32 func_0040CEC8(f32 a, f32 b);
extern f32 func_0040C3E0(f32 a);
extern s32 func_0040BAC0(s16 *p);
extern void func_0045E580(Obj_471390 *o);

/* localdecomp:start func_00471390 */
void func_00471390(Obj_471390 *o)
{
    Vel_471390 *v;
    f32 f;
    G_471390 *g;
    V4_471390 dir;

    func_004C6EC8(&o->pos, &o->pos);
    v = &o->vel;
    func_0040BE90(&v->v, &v->v, 0.9f);
    v->v.z = v->v.z - v->v.w;
    {
        Q_471390 a, b, r;
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(o->vel.v));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(o->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(r));
    }
    func_004C6EC8(&o->pos, &o->pos);
    f = func_0040BFB0(&o->pos, &D_001A4C60);
    if (f < 1.05f && (g = (G_471390 *)((u8 *)&D_001A4C60 - 0x80), g->f170 != 0.0f)) {
        V4_471390 tmp;
        Q_471390 a, b, r;
        tmp = D_001A4C60;
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(o->pos));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(tmp));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(r));
        f = func_004408C0(0.1f, 2.0f);
        func_0040C0F0(&dir, &dir, g->f170 * 0.2f + f * 0.016666668f * 0.15f);
        o->b8 += (s32)((f32)v->h22 * g->f170 * 0.5f);
        {
            Q_471390 c, d, s;
            __asm__("lqc2 %0, %1" : "=j"(d) : "m"(dir));
            __asm__("lqc2 %0, %1" : "=j"(c) : "m"(o->pos));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(s) : "j"(c), "j"(d));
            __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(s));
        }
    }
    if (D_001DFBC0 % 10 == 0) {
        f = func_0040CEC8(v->f28, 1.0f);
        v->f28 = f;
        f = func_0040C3E0(f);
        func_0040C0F0(&dir, &D_001E2900, f * 0.0075f);
        __asm__ __volatile__(
            "lqc2 vf1, %0\n"
            "lqc2 vf2, %1\n"
            "vadd.xyz vf1, vf1, vf2\n"
            "sqc2 vf1, %0\n"
            : "+m"(v->v) : "m"(dir));
    }
    if (o->h10 < v->h20) {
        o->color = ((s32)((f32)o->h10 / (f32)v->h20 * 128.0f) << 24) | 0x204040;
    } else {
        o->color = 0x4F204040;
    }
    o->b8 += *(u8 *)&v->h22;
    if (func_0040BAC0(&o->h10)) {
        func_0045E580(o);
    }
}
/* localdecomp:end func_00471390 */
