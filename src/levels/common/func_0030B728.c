#include "common.h"

/* localdecomp:start func_0030B728 */
typedef int Q_30B728 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_30B728;
typedef struct {
    V4_30B728 verts[4];
    u32 colors[4];
    f32 uv[8];
    unsigned long gif[4];
} Quad_30B728;
extern V4_30B728 D_001E2A40;
extern unsigned long func_00401CD0(s32);
extern f32 func_004408C0(f32, f32);
extern void func_0030AC38(V4_30B728 *, s32);
extern void func_0030A8D0(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern void func_0040BE68(void *, void *, void *, f32);
extern s32 func_0040D020(s32, s32, f32);
extern void func_00405A58(void *, s32, s32);

void func_0030B728(s32 unused, s32 n, V4_30B728 *pts, s32 count) {
    Quad_30B728 q1;
    Quad_30B728 q2;
    V4_30B728 mtx[4];
    V4_30B728 c0, c1;
    s32 i;
    f32 fi, t, u, u2;
    s32 col;
    V4_30B728 *p;
    u32 col1 = 0x7F0072FF;
    u32 col2 = 0x400072FF;

    q1.gif[1] = func_00401CD0(43);
    q1.gif[2] = 0xFF9000000260UL;
    q1.gif[3] = ((unsigned long)n << 32) | 104;
    q1.gif[0] = 0;
    q1.colors[1] = col1;
    q1.colors[0] = col1;
    q2.gif[1] = func_00401CD0(43);
    q2.gif[2] = 0xFF9000000260UL;
    q2.gif[3] = ((unsigned long)(n / 3) << 32) | 104;
    q2.gif[0] = 0;
    q2.colors[1] = col2;
    q2.colors[0] = col2;
    *(Q_30B728 *)&c0 = 0;
    *(Q_30B728 *)&c1 = 0;
    c0.w = 1.0f;
    c1.w = 1.0f;
    i = 1;
    c0.z = func_004408C0(0.005f, 0.085f) * 0.25f;
    c1.z = func_004408C0(0.1f, 0.25f) * 0.25f;
    func_0030AC38(pts, count);
    func_0030A8D0(&q1);
    func_0030A8D0(&q2);
    q1.uv[0] = 0.0f;
    q1.uv[1] = 0.0f;
    q1.uv[2] = 0.0f;
    q1.uv[3] = 1.0f;
    q1.uv[4] = 1.0f;
    q1.uv[5] = 0.0f;
    q1.uv[6] = 1.0f;
    q1.uv[7] = 1.0f;
    q2.uv[0] = 0.0f;
    q2.uv[1] = 0.0f;
    q2.uv[2] = 0.0f;
    q2.uv[3] = 1.0f;
    q2.uv[4] = 0.33f;
    q2.uv[5] = 0.0f;
    q2.uv[6] = 0.33f;
    q2.uv[7] = 1.0f;
    {
        Q_30B728 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pts[0]));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(pts[1]));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(mtx[0]) : "j"(y));
    }
    func_0040C0F0(&mtx[0], &mtx[0], 1.0f);
    {
        Q_30B728 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pts[0]));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(mtx[1]) : "j"(y));
    }
    func_0040BF20(&mtx[2], &mtx[1], &mtx[0]);
    func_0040C0F0(&mtx[2], &mtx[2], 1.0f);
    func_0040BF20(&mtx[1], &mtx[0], &mtx[2]);
    *(Q_30B728 *)&mtx[3] = *(Q_30B728 *)&pts[0];
    *(Q_30B728 *)&q1.verts[0] = *(Q_30B728 *)&c0;
    func_0040BE90(&q1.verts[1], &q1.verts[0], -1.0f);
    func_0040C2F8(&q1.verts[0], &q1.verts[0], mtx);
    func_0040C2F8(&q1.verts[1], &q1.verts[1], mtx);
    *(Q_30B728 *)&q2.verts[0] = *(Q_30B728 *)&c1;
    func_0040BE90(&q2.verts[1], &q2.verts[0], -1.0f);
    func_0040C2F8(&q2.verts[0], &q2.verts[0], mtx);
    func_0040C2F8(&q2.verts[1], &q2.verts[1], mtx);
    for (; i < count - 1; i++) {
        p = &pts[i + 1];
        *(Q_30B728 *)&q1.verts[2] = *(Q_30B728 *)&c0;
        fi = i;
        func_0040BE90(&q1.verts[3], &q1.verts[2], -1.0f);
        *(Q_30B728 *)&q2.verts[2] = *(Q_30B728 *)&c1;
        func_0040BE90(&q2.verts[3], &q2.verts[2], -1.0f);
        {
            Q_30B728 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*p));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(p - 1)));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(mtx[0]) : "j"(y));
        }
        func_0040C0F0(&mtx[0], &mtx[0], 1.0f);
        {
            Q_30B728 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(p - 1)));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(mtx[1]) : "j"(y));
        }
        func_0040BF20(&mtx[2], &mtx[1], &mtx[0]);
        func_0040C0F0(&mtx[2], &mtx[2], 1.0f);
        func_0040BF20(&mtx[1], &mtx[0], &mtx[2]);
        *(Q_30B728 *)&mtx[3] = *(Q_30B728 *)&*(p - 1);
        func_0040C2F8(&q1.verts[2], &q1.verts[2], mtx);
        func_0040C2F8(&q1.verts[3], &q1.verts[3], mtx);
        func_0040C2F8(&q2.verts[2], &q2.verts[2], mtx);
        func_0040C2F8(&q2.verts[3], &q2.verts[3], mtx);
        t = fi / ((f32)count - 2.0f);
        q1.colors[2] = q1.colors[3] = func_0040D020(0x7F0072FF, 0x7FDDB973, t);
        q2.colors[2] = q2.colors[3] = func_0040D020(0x7F0072FF, 0x40FF0000, t);
        if (i == count - 2) {
            func_0040BE68(&q1.verts[2], &q1.verts[2], &q1.verts[3], 0.5f);
            func_0040BE68(&q2.verts[2], &q2.verts[2], &q2.verts[3], 0.5f);
            *(Q_30B728 *)&q1.verts[3] = *(Q_30B728 *)&q1.verts[2];
            *(Q_30B728 *)&q2.verts[3] = *(Q_30B728 *)&q2.verts[2];
        }
        func_00405A58(&q1, 0, 0);
        func_00405A58(&q2, 0, 0);
        u = fi * 0.33f;
        u2 = u + 0.33f;
        if (u >= 1.0f) {
            u -= 1.0f;
            u2 -= 1.0f;
        }
        q1.colors[1] = q1.colors[2];
        q1.colors[0] = q1.colors[2];
        q2.colors[1] = q2.colors[2];
        q2.colors[0] = q2.colors[2];
        q2.uv[0] = u;
        q2.uv[4] = u2;
        q2.uv[2] = u;
        q2.uv[6] = u2;
        *(Q_30B728 *)&q1.verts[0] = *(Q_30B728 *)&q1.verts[2];
        *(Q_30B728 *)&q1.verts[1] = *(Q_30B728 *)&q1.verts[3];
        *(Q_30B728 *)&q2.verts[0] = *(Q_30B728 *)&q2.verts[2];
        *(Q_30B728 *)&q2.verts[1] = *(Q_30B728 *)&q2.verts[3];
    }
}
/* localdecomp:end func_0030B728 */
