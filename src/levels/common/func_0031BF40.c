#include "common.h"

/* localdecomp:start func_0031BF40 */
typedef int Q_31BF40 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_31BF40;
typedef struct { f32 u, v; } UV_31BF40;
typedef struct {
    V4_31BF40 verts[4];
    u32 colors[4];
    UV_31BF40 uv[4];
    unsigned long gif[4];
} Quad_31BF40;
typedef struct { f32 x, y, z; } V3_31BF40;
typedef struct {
    s32 i0;
    f32 f4, f8, fC, f10, f14, f18, f1C;
    u32 c20, c24, c28, c2C;
    V3_31BF40 v30;
    u32 c3C;
} P_31BF40;
typedef struct {
    u8 pad0[16];
    V4_31BF40 pos;
    u8 pad20[72];
    P_31BF40 *p104;
} O_31BF40;
extern V4_31BF40 D_001E2A40;
extern f32 func_0040C3E0(f32);
extern void func_004075A8(void *, s32, s32, s32);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_00405A58(void *, s32, s32);
void func_0031BF40(O_31BF40 *obj) {
    P_31BF40 *p = obj->p104;
    V4_31BF40 a;
    V4_31BF40 pos;
    Quad_31BF40 q;
    V4_31BF40 t;
    V4_31BF40 d;
    V4_31BF40 e;
    V4_31BF40 f;
    f32 s;
    u32 al;
    s32 i;

    {
        V3_31BF40 *v = &p->v30;
        a.x = v->x;
        a.y = v->y;
        a.z = v->z;
    }
    a.w = 0.0f;
    pos = obj->pos;
    s = (f32)p->i0 * p->f4;
    s = func_0040C3E0(s * 3.1415927f);
    func_004075A8(&q, 23, 0, 128);
    al = (s32)(s * 128.0f) << 24;
    q.colors[0] = q.colors[1] = q.colors[2] = q.colors[3] = p->c20 | al;
    q.colors[2] = q.colors[3] = p->c24 | al;
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    for (i = 0; i < 4; i++) {
        q.uv[i].u -= p->f8;
        if (q.uv[i].u <= 7.0f) {
            q.uv[i].u += 7.0f;
        }
    }
    p->f8 -= 0.1f;
    if (p->f8 <= 4.0f) {
        p->f8 += 4.0f;
    }
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t) : "j"(r));
    }
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
    }
    func_0040BE90(&d, &d, 0.5f);
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(r));
    }
    func_0040BF20(&f, &t, &d);
    func_0040C0F0(&f, &f, p->f10);
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(f));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(q.verts[0]) : "j"(r));
    }
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(f));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(q.verts[1]) : "j"(r));
    }
    func_0040C0F0(&f, &f, p->f14);
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(f));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(q.verts[2]) : "j"(r));
    }
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(f));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(q.verts[3]) : "j"(r));
    }
    func_00405A58(&q, 0, 0);
    q.colors[0] = q.colors[2];
    q.colors[1] = q.colors[3];
    q.colors[2] = q.colors[3] = p->c28;
    q.verts[0] = q.verts[2];
    q.verts[1] = q.verts[3];
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(q.verts[2]));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(q.verts[2]) : "j"(r));
    }
    {
        Q_31BF40 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(q.verts[3]));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(d));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(q.verts[3]) : "j"(y));
    }
    func_00405A58(&q, 0, 0);
    func_004075A8(&q, 14, 1, 128);
    q.colors[0] = q.colors[1] = q.colors[2] = q.colors[3] = p->c2C | ((s32)(s * 64.0f) << 24);
    q.uv[0].u = 0.0f;
    q.uv[0].v = 0.0f;
    q.uv[1].u = 0.0f;
    q.uv[1].v = 1.0f;
    q.uv[2].u = 1.0f;
    q.uv[2].v = 0.0f;
    q.uv[3].u = 1.0f;
    q.uv[3].v = 1.0f;
    q.colors[2] = q.colors[3] = p->c3C;
    func_0040C0F0(&f, &f, p->f18);
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(f));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(q.verts[0]) : "j"(r));
    }
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(f));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(q.verts[1]) : "j"(r));
    }
    {
        Q_31BF40 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(d));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(y));
    }
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(e) : "j"(r));
    }
    func_0040C0F0(&f, &f, p->f1C);
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(f));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(q.verts[2]) : "j"(r));
    }
    {
        Q_31BF40 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(f));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(q.verts[3]) : "j"(r));
    }
    func_00405A58(&q, 0, 0);
}
/* localdecomp:end func_0031BF40 */
