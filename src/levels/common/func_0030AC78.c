#include "common.h"

/* localdecomp:start func_0030AC78 */
typedef int Q_30AC78 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_30AC78;
typedef struct { f32 u, v; } UV_30AC78;
typedef struct {
    V4_30AC78 verts[4];
    u32 colors[4];
    UV_30AC78 uv[4];
    unsigned long gif[4];
} Quad_30AC78;
extern V4_30AC78 D_001E2A40;
extern unsigned long func_00401CD0(s32);
extern f32 func_004408C0(f32, f32);
extern void func_0030AC38(void *, s32);
extern void func_0030A8D0(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern u32 func_0040D020(u32, u32, f32);
extern void func_00405A58(void *, s32, s32);

void func_0030AC78(void *unused, s32 alpha, V4_30AC78 *pts, s32 n) {
    Quad_30AC78 q1;
    Quad_30AC78 q2;
    V4_30AC78 mtx[4];
    V4_30AC78 c0, c1;
    s32 i;
    u32 col2 = 0x400072FF;

    q1.gif[1] = func_00401CD0(43);
    q1.gif[2] = 0xFF9000000260UL;
    q1.gif[3] = ((unsigned long)alpha << 32) | 104;
    q1.gif[0] = 0;
    q1.colors[1] = 0x7F0072FF;
    q1.colors[0] = 0x7F0072FF;
    q2.gif[1] = func_00401CD0(43);
    q2.gif[2] = 0xFF9000000260UL;
    q2.gif[3] = ((unsigned long)(alpha / 3) << 32) | 104;
    q2.gif[0] = 0;
    q2.colors[1] = col2;
    q2.colors[0] = col2;
    *(Q_30AC78 *)&c0 = 0;
    *(Q_30AC78 *)&c1 = 0;
    c0.w = 1.0f;
    c1.w = 1.0f;
    c0.z = func_004408C0(0.005f, 0.085f) * 2.0f;
    c1.z = func_004408C0(0.1f, 0.25f) * 2.0f;
    func_0030AC38(pts, n);
    func_0030A8D0(&q1);
    func_0030A8D0(&q2);
    q1.uv[0].u = 0.0f;
    q1.uv[0].v = 0.0f;
    q1.uv[1].u = 0.0f;
    q1.uv[1].v = 1.0f;
    q1.uv[2].u = 1.0f;
    q1.uv[2].v = 0.0f;
    q1.uv[3].u = 1.0f;
    q1.uv[3].v = 1.0f;
    q2.uv[0].u = 0.0f;
    q2.uv[0].v = 0.0f;
    q2.uv[1].u = 0.0f;
    q2.uv[1].v = 1.0f;
    q2.uv[2].u = 0.33f;
    q2.uv[2].v = 0.0f;
    q2.uv[3].u = 0.33f;
    q2.uv[3].v = 1.0f;
    {
        Q_30AC78 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pts[0]));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pts[1]));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(mtx[0]) : "j"(y));
    }
    func_0040C0F0(&mtx[0], &mtx[0], 1.0f);
    {
        Q_30AC78 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pts[0]));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(mtx[1]) : "j"(y));
    }
    func_0040BF20(&mtx[2], &mtx[1], &mtx[0]);
    func_0040C0F0(&mtx[2], &mtx[2], 1.0f);
    func_0040BF20(&mtx[1], &mtx[0], &mtx[2]);
    *(Q_30AC78 *)&mtx[3] = *(Q_30AC78 *)&pts[0];
    *(Q_30AC78 *)&q1.verts[0] = *(Q_30AC78 *)&c0;
    func_0040BE90(&q1.verts[1], &q1.verts[0], -1.0f);
    func_0040C2F8(&q1.verts[0], &q1.verts[0], mtx);
    func_0040C2F8(&q1.verts[1], &q1.verts[1], mtx);
    *(Q_30AC78 *)&q2.verts[0] = *(Q_30AC78 *)&c1;
    func_0040BE90(&q2.verts[1], &q2.verts[0], -1.0f);
    func_0040C2F8(&q2.verts[0], &q2.verts[0], mtx);
    func_0040C2F8(&q2.verts[1], &q2.verts[1], mtx);
    for (i = 1; i < n - 1; i++) {
        f32 t, u0, u1;
        V4_30AC78 *b = &pts[i + 1];
        V4_30AC78 *a = b - 1;
        *(Q_30AC78 *)&q1.verts[2] = *(Q_30AC78 *)&c0;
        func_0040BE90(&q1.verts[3], &q1.verts[2], -1.0f);
        *(Q_30AC78 *)&q2.verts[2] = *(Q_30AC78 *)&c1;
        func_0040BE90(&q2.verts[3], &q2.verts[2], -1.0f);
        {
            Q_30AC78 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(mtx[0]) : "j"(y));
        }
        func_0040C0F0(&mtx[0], &mtx[0], 1.0f);
        {
            Q_30AC78 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(mtx[1]) : "j"(y));
        }
        func_0040BF20(&mtx[2], &mtx[1], &mtx[0]);
        func_0040C0F0(&mtx[2], &mtx[2], 1.0f);
        func_0040BF20(&mtx[1], &mtx[0], &mtx[2]);
        *(Q_30AC78 *)&mtx[3] = *(Q_30AC78 *)a;
        func_0040C2F8(&q1.verts[2], &q1.verts[2], mtx);
        func_0040C2F8(&q1.verts[3], &q1.verts[3], mtx);
        func_0040C2F8(&q2.verts[2], &q2.verts[2], mtx);
        func_0040C2F8(&q2.verts[3], &q2.verts[3], mtx);
        t = (f32)i / ((f32)n - 2.0f);
        q1.colors[2] = q1.colors[3] = func_0040D020(0x7F0072FF, 0x7FDDB973, t);
        q2.colors[2] = q2.colors[3] = func_0040D020(0x7F0072FF, 0x40FF0000, t);
        func_00405A58(&q1, 0, 0);
        func_00405A58(&q2, 0, 0);
        u0 = (f32)i * 0.33f;
        u1 = u0 + 0.33f;
        if (u0 >= 1.0f) {
            u0 -= 1.0f;
            u1 -= 1.0f;
        }
        q1.colors[0] = q1.colors[1] = q1.colors[2];
        q2.colors[0] = q2.colors[1] = q2.colors[2];
        q2.uv[0].u = u0;
        q2.uv[1].u = u0;
        q2.uv[2].u = u1;
        q2.uv[3].u = u1;
        q1.verts[0] = q1.verts[2];
        q1.verts[1] = q1.verts[3];
        q2.verts[0] = q2.verts[2];
        q2.verts[1] = q2.verts[3];
    }
}
/* localdecomp:end func_0030AC78 */
