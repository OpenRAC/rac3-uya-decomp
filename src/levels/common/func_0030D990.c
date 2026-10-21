#include "common.h"

/* localdecomp:start func_0030D990 */
typedef int Q_30D990 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_30D990;
typedef struct { f32 u, v; } UV_30D990;
typedef struct {
    V4_30D990 verts[4];
    u32 colors[4];
    UV_30D990 uv[4];
    unsigned long gif[4];
} Quad_30D990;
extern V4_30D990 D_001E2A40;
extern unsigned long func_00401CD0(s32);
extern void func_0030D478(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern void func_00405A58(void *, s32, s32);

void func_0030D990(V4_30D990 *a, V4_30D990 *b, s32 unused0, s32 alpha, s32 unused1, s32 n, f32 w, f32 unused2, f32 h) {
    Quad_30D990 q1;
    Quad_30D990 q2;
    V4_30D990 mtx[4];
    V4_30D990 c0, c1;

    q1.gif[1] = func_00401CD0(47);
    q1.gif[2] = 0xFF9000000260UL;
    q1.gif[3] = ((unsigned long)n << 2) | 0x8000000040UL;
    q1.gif[0] = 0;
    alpha <<= 24;
    q1.colors[3] = 0x800000;
    q1.colors[2] = 0x800000;
    q1.colors[1] = alpha + 0x800000;
    q1.colors[0] = alpha + 0x800000;
    q2.gif[1] = func_00401CD0(48);
    q2.gif[2] = 0xFF9000000260UL;
    q2.gif[3] = 0x8000000048UL;
    q2.gif[0] = 0;
    alpha += 0xFFFFFF;
    q2.colors[3] = 0x800000;
    q2.colors[2] = 0x800000;
    q2.colors[1] = alpha;
    q2.colors[0] = alpha;
    *(Q_30D990 *)&c0 = 0;
    *(Q_30D990 *)&c1 = 0;
    c0.w = 1.0f;
    c1.w = 1.0f;
    c0.z = w;
    c1.z = w;
    func_0030D478(&q1);
    func_0030D478(&q2);
    q1.uv[0].u = h;
    q1.uv[0].v = 0.0f;
    q1.uv[1].u = h;
    q1.uv[1].v = 1.0f;
    q1.uv[2].u = h + 1.0f;
    q1.uv[2].v = 0.0f;
    q1.uv[3].u = h + 1.0f;
    q1.uv[3].v = 1.0f;
    q2.uv[0].u = h;
    q2.uv[0].v = 0.0f;
    q2.uv[1].u = h;
    q2.uv[1].v = 1.0f;
    q2.uv[2].u = h + 1.0f;
    q2.uv[2].v = 0.0f;
    q2.uv[3].u = h + 1.0f;
    q2.uv[3].v = 1.0f;
    {
        Q_30D990 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(mtx[0]) : "j"(y));
    }
    func_0040C0F0(&mtx[0], &mtx[0], 1.0f);
    {
        Q_30D990 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(mtx[1]) : "j"(y));
    }
    func_0040BF20(&mtx[2], &mtx[1], &mtx[0]);
    func_0040C0F0(&mtx[2], &mtx[2], 1.0f);
    func_0040BF20(&mtx[1], &mtx[0], &mtx[2]);
    *(Q_30D990 *)&mtx[3] = *(Q_30D990 *)a;
    *(Q_30D990 *)&q1.verts[0] = *(Q_30D990 *)&c0;
    *(Q_30D990 *)&q2.verts[0] = *(Q_30D990 *)&c1;
    func_0040BE90(&q1.verts[1], &q1.verts[0], -1.0f);
    func_0040BE90(&q2.verts[1], &q2.verts[0], -1.0f);
    func_0040C2F8(&q1.verts[0], &q1.verts[0], mtx);
    func_0040C2F8(&q1.verts[1], &q1.verts[1], mtx);
    func_0040C2F8(&q2.verts[0], &q2.verts[0], mtx);
    func_0040C2F8(&q2.verts[1], &q2.verts[1], mtx);
    c0.z *= 0.5f;
    c1.z *= 0.5f;
    *(Q_30D990 *)&mtx[3] = *(Q_30D990 *)b;
    *(Q_30D990 *)&q1.verts[2] = *(Q_30D990 *)&c0;
    *(Q_30D990 *)&q2.verts[2] = *(Q_30D990 *)&c1;
    func_0040BE90(&q1.verts[3], &q1.verts[2], -1.0f);
    func_0040BE90(&q2.verts[3], &q2.verts[2], -1.0f);
    func_0040C2F8(&q1.verts[2], &q1.verts[2], mtx);
    func_0040C2F8(&q1.verts[3], &q1.verts[3], mtx);
    func_0040C2F8(&q2.verts[2], &q2.verts[2], mtx);
    func_0040C2F8(&q2.verts[3], &q2.verts[3], mtx);
    func_00405A58(&q1, 0, 0);
    func_00405A58(&q2, 0, 0);
}
/* localdecomp:end func_0030D990 */
