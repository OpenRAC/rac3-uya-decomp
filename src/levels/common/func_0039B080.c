#include "common.h"

/* localdecomp:start func_0039B080 */
typedef int Q_39B080 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_39B080;
typedef struct { f32 u, v; } UV_39B080;
typedef struct {
    V4_39B080 verts[4];
    u32 colors[4];
    UV_39B080 uv[4];
    unsigned long gif[4];
} Quad_39B080;
extern V4_39B080 D_001E2A40;
extern u32 D_001E20D8;
extern unsigned long func_00401CD0(s32);
extern void func_0039AFB8(V4_39B080 *, s32);
extern void func_0039AFF8(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern void func_00405A58(void *, s32, s32);

void func_0039B080(s32 unused, s32 n, V4_39B080 *pts, s32 count) {
    Quad_39B080 q1;
    Quad_39B080 q2;
    V4_39B080 mtx[4];
    V4_39B080 c0, c1;
    s32 i;
    f32 t0, t1;

    q1.gif[1] = func_00401CD0(43);
    q1.gif[0] = 0;
    q1.gif[3] = ((unsigned long)n << 32) | 0x68;
    q1.gif[2] = 0xFF9000000260UL;
    q1.colors[1] = 0x7FFFFFFF;
    q1.colors[0] = 0x7FFFFFFF;
    i = 1;
    q2.gif[1] = func_00401CD0(43);
    q2.gif[3] = ((unsigned long)(n / 3) << 32) | 0x68;
    *(Q_39B080 *)&c0 = 0;
    *(Q_39B080 *)&c1 = 0;
    q2.gif[2] = 0xFF9000000260UL;
    q1.colors[1] = D_001E20D8;
    q2.colors[0] = D_001E20D8;
    c0.z = 0.04f;
    c1.z = 0.16f;
    q2.gif[0] = 0;
    c0.w = 1.0f;
    c1.w = 1.0f;
    func_0039AFB8(pts, count);
    func_0039AFF8(&q1);
    func_0039AFF8(&q2);
    {
        Q_39B080 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pts[0]));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pts[1]));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
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
        __asm__("sqc2 %1, %0" : "=m"(mtx[0]) : "j"(y));
    }
    func_0040C0F0(&mtx[0], &mtx[0], 1.0f);
    {
        Q_39B080 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pts[0]));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(mtx[1]) : "j"(y));
    }
    func_0040BF20(&mtx[2], &mtx[1], &mtx[0]);
    func_0040C0F0(&mtx[2], &mtx[2], 1.0f);
    func_0040BF20(&mtx[1], &mtx[0], &mtx[2]);
    *(Q_39B080 *)&mtx[3] = *(Q_39B080 *)&pts[0];
    *(Q_39B080 *)&q1.verts[0] = *(Q_39B080 *)&c0;
    func_0040BE90(&q1.verts[1], &q1.verts[0], -1.0f);
    func_0040C2F8(&q1.verts[0], &q1.verts[0], mtx);
    func_0040C2F8(&q1.verts[1], &q1.verts[1], mtx);
    *(Q_39B080 *)&q2.verts[0] = *(Q_39B080 *)&c1;
    func_0040BE90(&q2.verts[1], &q2.verts[0], -1.0f);
    func_0040C2F8(&q2.verts[0], &q2.verts[0], mtx);
    func_0040C2F8(&q2.verts[1], &q2.verts[1], mtx);
    for (; i < count - 1; i++) {
        V4_39B080 *p = &pts[i + 1];
        *(Q_39B080 *)&q1.verts[2] = *(Q_39B080 *)&c0;
        func_0040BE90(&q1.verts[3], &q1.verts[2], -1.0f);
        *(Q_39B080 *)&q2.verts[2] = *(Q_39B080 *)&c1;
        func_0040BE90(&q2.verts[3], &q2.verts[2], -1.0f);
        {
            Q_39B080 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*p));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"((*(V4_39B080 *)((u8 *)p - 16))));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(mtx[0]) : "j"(y));
        }
        func_0040C0F0(&mtx[0], &mtx[0], 1.0f);
        {
            Q_39B080 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"((*(V4_39B080 *)((u8 *)p - 16))));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(mtx[1]) : "j"(y));
        }
        func_0040BF20(&mtx[2], &mtx[1], &mtx[0]);
        func_0040C0F0(&mtx[2], &mtx[2], 1.0f);
        func_0040BF20(&mtx[1], &mtx[0], &mtx[2]);
        *(Q_39B080 *)&mtx[3] = *(Q_39B080 *)&(*(V4_39B080 *)((u8 *)p - 16));
        func_0040C2F8(&q1.verts[2], &q1.verts[2], mtx);
        func_0040C2F8(&q1.verts[3], &q1.verts[3], mtx);
        func_0040C2F8(&q2.verts[2], &q2.verts[2], mtx);
        func_0040C2F8(&q2.verts[3], &q2.verts[3], mtx);
        q1.colors[3] = 0x7F7F7F7F;
        q1.colors[2] = 0x7F7F7F7F;
        q2.colors[3] = D_001E20D8;
        q2.colors[2] = D_001E20D8;
        func_00405A58(&q1, 0, 0);
        func_00405A58(&q2, 0, 0);
        t0 = (f32)i * 0.33f;
        if (t0 >= 1.0f) {
            t1 = t0 + 0.33f;
            t0 -= 1.0f;
            t1 -= 1.0f;
        } else {
            t1 = t0 + 0.33f;
        }        q2.uv[0].u = t0;
        q2.uv[2].u = t1;
        q2.uv[1].u = t0;
        q2.uv[3].u = t1;
        *(Q_39B080 *)&q1.verts[0] = *(Q_39B080 *)&q1.verts[2];
        *(Q_39B080 *)&q1.verts[1] = *(Q_39B080 *)&q1.verts[3];
        *(Q_39B080 *)&q2.verts[0] = *(Q_39B080 *)&q2.verts[2];
        *(Q_39B080 *)&q2.verts[1] = *(Q_39B080 *)&q2.verts[3];
    }
}
/* localdecomp:end func_0039B080 */
