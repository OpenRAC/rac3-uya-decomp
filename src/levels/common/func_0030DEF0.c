#include "common.h"

/* localdecomp:start func_0030DEF0 */
typedef int Q_30DEF0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_30DEF0;
typedef struct { f32 u, v; } UV_30DEF0;
typedef struct {
    V4_30DEF0 verts[4];
    u32 colors[4];
    UV_30DEF0 uv[4];
    unsigned long gif[4];
} Quad_30DEF0;
extern V4_30DEF0 D_001E2A40;
extern unsigned long func_00401CD0(s32);
extern f32 func_004408C0(f32, f32);
extern void func_0030DEB0(V4_30DEF0 *, s32);
extern void func_0030D478(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern void func_00405A58(void *, s32, s32);

void func_0030DEF0(s32 unused, s32 k, V4_30DEF0 *pts, s32 n) {
    Quad_30DEF0 q1;
    Quad_30DEF0 q2;
    V4_30DEF0 mtx[4];
    V4_30DEF0 c0, c1;
    u32 color;
    s32 i;
    V4_30DEF0 *p;
    f32 u0, u1;
    f32 step;
    Q_30DEF0 a, b;

    color = 0x80FF0000;
    q1.gif[1] = func_00401CD0(43);
    q1.gif[2] = 0xFF9000000260UL;
    q1.gif[3] = ((unsigned long)k << 32) | 104;
    q1.gif[0] = 0;
    q1.colors[1] = 0x7FAFAFAF;
    q1.colors[0] = 0x7FAFAFAF;
    q2.gif[1] = func_00401CD0(43);
    q2.gif[2] = 0xFF9000000260UL;
    q2.gif[3] = ((unsigned long)(k / 3) << 32) | 104;
    q2.gif[0] = 0;
    q2.colors[1] = color;
    q2.colors[0] = color;
    *(Q_30DEF0 *)&c0 = 0;
    *(Q_30DEF0 *)&c1 = 0;
    c0.w = 1.0f;
    c1.w = 1.0f;
    c0.z = func_004408C0(0.02f, 0.1f);
    c1.z = func_004408C0(0.15f, 0.3f);
    func_0030DEB0(pts, n);
    func_0030D478(&q1);
    func_0030D478(&q2);
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
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(pts[0]));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(pts[1]));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(b) : "j"(a));
        __asm__("sqc2 %1, %0" : "=m"(mtx[0]) : "j"(b));
    }
    func_0040C0F0(&mtx[0], &mtx[0], 1.0f);
    {
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(pts[0]));
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(a) : "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(mtx[1]) : "j"(a));
    }
    func_0040BF20(&mtx[2], &mtx[1], &mtx[0]);
    func_0040C0F0(&mtx[2], &mtx[2], 1.0f);
    func_0040BF20(&mtx[1], &mtx[0], &mtx[2]);
    *(Q_30DEF0 *)&mtx[3] = *(Q_30DEF0 *)&pts[0];
    *(Q_30DEF0 *)&q1.verts[0] = *(Q_30DEF0 *)&c0;
    func_0040BE90(&q1.verts[1], &q1.verts[0], -1.0f);
    func_0040C2F8(&q1.verts[0], &q1.verts[0], mtx);
    func_0040C2F8(&q1.verts[1], &q1.verts[1], mtx);
    *(Q_30DEF0 *)&q2.verts[0] = *(Q_30DEF0 *)&c1;
    func_0040BE90(&q2.verts[1], &q2.verts[0], -1.0f);
    func_0040C2F8(&q2.verts[0], &q2.verts[0], mtx);
    func_0040C2F8(&q2.verts[1], &q2.verts[1], mtx);
    p = pts + 1;
    for (i = 1; i < n - 1; i++) {
        *(Q_30DEF0 *)&q1.verts[2] = *(Q_30DEF0 *)&c0;
        func_0040BE90(&q1.verts[3], &q1.verts[2], -1.0f);
        *(Q_30DEF0 *)&q2.verts[2] = *(Q_30DEF0 *)&c1;
        func_0040BE90(&q2.verts[3], &q2.verts[2], -1.0f);
        {
            __asm__("lqc2 %0, %1" : "=j"(a) : "m"(p[i - 1]));
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(p[i]));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(b) : "j"(a));
            __asm__("sqc2 %1, %0" : "=m"(mtx[0]) : "j"(b));
        }
        func_0040C0F0(&mtx[0], &mtx[0], 1.0f);
        {
            __asm__("lqc2 %0, %1" : "=j"(a) : "m"(p[i - 1]));
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(D_001E2A40));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(b) : "j"(a));
            __asm__("sqc2 %1, %0" : "=m"(mtx[1]) : "j"(b));
        }
        func_0040BF20(&mtx[2], &mtx[1], &mtx[0]);
        func_0040C0F0(&mtx[2], &mtx[2], 1.0f);
        func_0040BF20(&mtx[1], &mtx[0], &mtx[2]);
        *(Q_30DEF0 *)&mtx[3] = *(Q_30DEF0 *)&p[i - 1];
        func_0040C2F8(&q1.verts[2], &q1.verts[2], mtx);
        func_0040C2F8(&q1.verts[3], &q1.verts[3], mtx);
        func_0040C2F8(&q2.verts[2], &q2.verts[2], mtx);
        func_0040C2F8(&q2.verts[3], &q2.verts[3], mtx);
        q1.colors[3] = 0x7FAFAFAF;
        q1.colors[2] = 0x7FAFAFAF;
        q2.colors[3] = color;
        q2.colors[2] = color;
        func_00405A58(&q1, 0, 0);
        func_00405A58(&q2, 0, 0);
        step = 0.33f;
        u0 = (f32)i * step;
        u1 = u0 + step;
        if (u0 >= 1.0f) {
            u0 -= 1.0f;
            u1 -= 1.0f;
        }
        q2.uv[0].u = u0;
        q2.uv[1].u = u0;
        q2.uv[2].u = u1;
        q2.uv[3].u = u1;
        *(Q_30DEF0 *)&q1.verts[0] = *(Q_30DEF0 *)&q1.verts[2];
        *(Q_30DEF0 *)&q1.verts[1] = *(Q_30DEF0 *)&q1.verts[3];
        *(Q_30DEF0 *)&q2.verts[0] = *(Q_30DEF0 *)&q2.verts[2];
        *(Q_30DEF0 *)&q2.verts[1] = *(Q_30DEF0 *)&q2.verts[3];
    }
}
/* localdecomp:end func_0030DEF0 */
