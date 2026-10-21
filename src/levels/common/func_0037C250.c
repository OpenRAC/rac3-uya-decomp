#include "common.h"

/* localdecomp:start func_0037C250 */
typedef int Q_37C250 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_37C250;
typedef struct { f32 u, v; } UV_37C250;
typedef struct {
    V4_37C250 verts[4];
    u32 colors[4];
    UV_37C250 uv[4];
    unsigned long gif[4];
} Quad_37C250;
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad[0xEE];
} E_37C250;
extern u8 D_00142627[];
extern E_37C250 D_002C5640[];
extern V4_37C250 D_001E2A40;
extern unsigned long func_00401CD0(s32);
extern f32 func_004408C0(f32, f32);
extern void func_0037B690(V4_37C250 *, s32);
extern void func_0037B6D0(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040BE68(void *, void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern u32 func_0040D020(u32, u32, f32);
extern void func_00405A58(void *, s32, s32);

void func_0037C250(s32 unused, s32 n, V4_37C250 *pts, s32 count) {
    Quad_37C250 q1;
    Quad_37C250 q2;
    V4_37C250 mtx[4];
    V4_37C250 c0, c1;
    u32 colA, colB;
    s32 i;
    u32 ca, cb, col;
    V4_37C250 *p;
    f32 fi, t, u0, u1;

    ca = 0x3FFF8040;
    cb = 0x0FFF8040;
    colA = 0x3FAF7F7F;
    colB = 0x0FAF7F7F;
    if ((D_002C5640 + D_00142627[0])->b1 >= 3) {
        colA = 0x3F101070;
        colB = 0x0F101070;
        ca = 0x3F4080FF;
        cb = 0x0F4080FF;
    }
    q1.gif[1] = func_00401CD0(0x2B);
    q1.gif[2] = 0xFF9000000260UL;
    q1.gif[3] = ((unsigned long)n << 32) | 0x68;
    q1.gif[0] = 0;
    q1.colors[1] = ca;
    q1.colors[0] = ca;
    i = 1;
    q2.gif[1] = func_00401CD0(0x2B);
    q2.gif[2] = 0xFF9000000260UL;
    q2.gif[3] = ((unsigned long)(n / 3) << 32) | 0x68;
    q2.gif[0] = 0;
    q2.colors[1] = cb;
    q2.colors[0] = cb;
    *(Q_37C250 *)&c0 = 0;
    *(Q_37C250 *)&c1 = 0;
    c0.w = 1.0f;
    c1.w = 1.0f;
    c0.z = func_004408C0(0.01f, 0.085f) * 1.5f;
    c1.z = func_004408C0(0.15f, 0.25f) * 1.5f;
    func_0037B690(pts, count);
    func_0037B6D0(&q1);
    func_0037B6D0(&q2);
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
        Q_37C250 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pts[0]));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pts[1]));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(mtx[0]) : "j"(y));
    }
    func_0040C0F0(&mtx[0], &mtx[0], 1.0f);
    {
        Q_37C250 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pts[0]));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(mtx[1]) : "j"(y));
    }
    func_0040BF20(&mtx[2], &mtx[1], &mtx[0]);
    func_0040C0F0(&mtx[2], &mtx[2], 1.0f);
    func_0040BF20(&mtx[1], &mtx[0], &mtx[2]);
    *(Q_37C250 *)&mtx[3] = *(Q_37C250 *)&pts[0];
    *(Q_37C250 *)&q1.verts[0] = *(Q_37C250 *)&c0;
    func_0040BE90(&q1.verts[1], &q1.verts[0], -1.0f);
    func_0040C2F8(&q1.verts[0], &q1.verts[0], mtx);
    func_0040C2F8(&q1.verts[1], &q1.verts[1], mtx);
    *(Q_37C250 *)&q2.verts[0] = *(Q_37C250 *)&c1;
    func_0040BE90(&q2.verts[1], &q2.verts[0], -1.0f);
    func_0040C2F8(&q2.verts[0], &q2.verts[0], mtx);
    func_0040C2F8(&q2.verts[1], &q2.verts[1], mtx);
    for (; i < count - 1; i++) {
        fi = (f32)i;
        *(Q_37C250 *)&q1.verts[2] = *(Q_37C250 *)&c0;
        func_0040BE90(&q1.verts[3], &q1.verts[2], -1.0f);
        *(Q_37C250 *)&q2.verts[2] = *(Q_37C250 *)&c1;
        func_0040BE90(&q2.verts[3], &q2.verts[2], -1.0f);
        {
            Q_37C250 x, y;
            V4_37C250 *a = &pts[i + 1];
            V4_37C250 *b = a - 1;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*b));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(mtx[0]) : "j"(y));
        }
        func_0040C0F0(&mtx[0], &mtx[0], 1.0f);
        {
            Q_37C250 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pts[i]));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(mtx[1]) : "j"(y));
        }
        func_0040BF20(&mtx[2], &mtx[1], &mtx[0]);
        func_0040C0F0(&mtx[2], &mtx[2], 1.0f);
        func_0040BF20(&mtx[1], &mtx[0], &mtx[2]);
        *(Q_37C250 *)&mtx[3] = *(Q_37C250 *)&pts[i];
        func_0040C2F8(&q1.verts[2], &q1.verts[2], mtx);
        func_0040C2F8(&q1.verts[3], &q1.verts[3], mtx);
        func_0040C2F8(&q2.verts[2], &q2.verts[2], mtx);
        func_0040C2F8(&q2.verts[3], &q2.verts[3], mtx);
        t = fi / ((f32)count - 2.0f);
        q1.colors[2] = q1.colors[3] = func_0040D020(ca, colA, t);
        q2.colors[2] = q2.colors[3] = func_0040D020(ca, colB, t);
        if (i == count - 2) {
            func_0040BE68(&q1.verts[2], &q1.verts[2], &q1.verts[3], 0.5f);
            func_0040BE68(&q2.verts[2], &q2.verts[2], &q2.verts[3], 0.5f);
            *(Q_37C250 *)&q1.verts[3] = *(Q_37C250 *)&q1.verts[2];
            *(Q_37C250 *)&q2.verts[3] = *(Q_37C250 *)&q2.verts[2];
        }
        func_00405A58(&q1, 0, 0);
        func_00405A58(&q2, 0, 0);
        u0 = fi * 0.33f;
        u1 = u0 + 0.33f;
        if (u0 >= 1.0f) {
            u0 -= 1.0f;
            u1 -= 1.0f;
        }
        q1.colors[1] = q1.colors[2];
        q1.colors[0] = q1.colors[2];
        q2.colors[1] = q2.colors[2];
        q2.colors[0] = q2.colors[2];
        q2.uv[0].u = u0;
        q2.uv[1].u = u0;
        q2.uv[2].u = u1;
        q2.uv[3].u = u1;
        *(Q_37C250 *)&q1.verts[0] = *(Q_37C250 *)&q1.verts[2];
        *(Q_37C250 *)&q1.verts[1] = *(Q_37C250 *)&q1.verts[3];
        *(Q_37C250 *)&q2.verts[0] = *(Q_37C250 *)&q2.verts[2];
        *(Q_37C250 *)&q2.verts[1] = *(Q_37C250 *)&q2.verts[3];
    }
}
/* localdecomp:end func_0037C250 */
