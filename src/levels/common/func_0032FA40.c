#include "common.h"

/* localdecomp:start func_0032FA40 */
typedef int Q_32FA40 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32FA40;
typedef struct { f32 u, v; } UV_32FA40;
typedef struct {
    V4_32FA40 verts[4];
    u32 colors[4];
    UV_32FA40 uv[4];
    unsigned long gif[4];
} Quad_32FA40;
typedef struct {
    u8 pad0[48];
    V4_32FA40 v48;
} P_32FA40;
typedef struct {
    u8 pad0[104];
    P_32FA40 *p68;
    u8 pad108[84];
    u8 vC0[64];
} O_32FA40;
extern s32 D_001DFBC0;
extern V4_32FA40 D_001E2A40;
extern void func_00437698(O_32FA40 *, s32, V4_32FA40 *);
extern f32 func_004408C0(f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0032F748(O_32FA40 *, V4_32FA40 *);
extern unsigned long func_00401CD0(s32);
extern void func_0032F6B8(void *);
extern s32 func_0013D3E0(void);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern void func_00405A58(void *, s32, s32);

void func_0032FA40(O_32FA40 *obj) {
    Quad_32FA40 q1;
    Quad_32FA40 q2;
    V4_32FA40 mtx[4];
    V4_32FA40 a;
    V4_32FA40 b;
    V4_32FA40 u;
    V4_32FA40 c0, c1;
    P_32FA40 *p = obj->p68;

    if (D_001DFBC0 & 1) {
        func_00437698(obj, 1, &u);
    } else {
        func_00437698(obj, 2, &u);
    }
    a = u;
    func_0040C0F0(&b, &p->v48, func_004408C0(2.0f, 4.0f));
    func_0040C2D0(&b, &b, obj->vC0);
    {
        Q_32FA40 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(u));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(b) : "j"(x));
    }
    func_0032F748(obj, &a);
    q1.gif[1] = func_00401CD0(23);
    q1.gif[2] = 0xFF9000000260UL;
    q1.gif[0] = 0;
    q1.gif[3] = 0x8000000048UL;
    q1.colors[3] = 0x103080;
    q1.colors[2] = 0x103080;
    q1.colors[1] = 0x7F103080;
    q1.colors[0] = 0x7F103080;
    q2.gif[1] = func_00401CD0(23);
    q2.gif[2] = 0xFF9000000260UL;
    q2.gif[3] = 0x8000000048UL;
    q2.gif[0] = 0;
    q2.colors[3] = 0x103080;
    q2.colors[2] = 0x103080;
    q2.colors[1] = 0x3F103080;
    q2.colors[0] = 0x3F103080;
    *(Q_32FA40 *)&c0 = 0;
    *(Q_32FA40 *)&c1 = 0;
    c0.w = 1.0f;
    c1.w = 1.0f;
    c0.z = func_004408C0(0.1f, 0.3f);
    c1.z = c0.z + c0.z;
    func_0032F6B8(&q1);
    func_0032F6B8(&q2);
    if (!(func_0013D3E0() & 1)) {
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
        q2.uv[2].u = 1.0f;
        q2.uv[2].v = 0.0f;
        q2.uv[3].u = 1.0f;
        q2.uv[3].v = 1.0f;
    } else {
        q1.uv[0].u = 0.0f;
        q1.uv[0].v = 1.0f;
        q1.uv[1].u = 0.0f;
        q1.uv[1].v = 0.0f;
        q1.uv[2].u = 1.0f;
        q1.uv[2].v = 1.0f;
        q1.uv[3].u = 1.0f;
        q1.uv[3].v = 0.0f;
        q2.uv[0].u = 0.0f;
        q2.uv[0].v = 1.0f;
        q2.uv[1].u = 0.0f;
        q2.uv[1].v = 0.0f;
        q2.uv[2].u = 1.0f;
        q2.uv[2].v = 1.0f;
        q2.uv[3].u = 1.0f;
        q2.uv[3].v = 0.0f;
    }
    {
        Q_32FA40 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(mtx[0]) : "j"(y));
    }
    func_0040C0F0(&mtx[0], &mtx[0], 1.0f);
    {
        Q_32FA40 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(y) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(mtx[1]) : "j"(y));
    }
    func_0040BF20(&mtx[2], &mtx[1], &mtx[0]);
    func_0040C0F0(&mtx[2], &mtx[2], 1.0f);
    func_0040BF20(&mtx[1], &mtx[0], &mtx[2]);
    mtx[3] = a;
    q1.verts[0] = c0;
    q2.verts[0] = c1;
    func_0040BE90(&q1.verts[1], &q1.verts[0], -1.0f);
    func_0040BE90(&q2.verts[1], &q2.verts[0], -1.0f);
    func_0040C2F8(&q1.verts[0], &q1.verts[0], mtx);
    func_0040C2F8(&q1.verts[1], &q1.verts[1], mtx);
    func_0040C2F8(&q2.verts[0], &q2.verts[0], mtx);
    func_0040C2F8(&q2.verts[1], &q2.verts[1], mtx);
    c0.z *= 0.15f;
    c1.z = c0.z + c0.z;
    mtx[3] = b;
    q1.verts[2] = c0;
    q2.verts[2] = c1;
    func_0040BE90(&q1.verts[3], &q1.verts[2], -1.0f);
    func_0040BE90(&q2.verts[3], &q2.verts[2], -1.0f);
    func_0040C2F8(&q1.verts[2], &q1.verts[2], mtx);
    func_0040C2F8(&q1.verts[3], &q1.verts[3], mtx);
    func_0040C2F8(&q2.verts[2], &q2.verts[2], mtx);
    func_0040C2F8(&q2.verts[3], &q2.verts[3], mtx);
    func_00405A58(&q1, 0, 0);
    func_00405A58(&q2, 0, 0);
}
/* localdecomp:end func_0032FA40 */
