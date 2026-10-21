#include "common.h"

/* localdecomp:start func_0035DFF0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_35DFF0;
typedef int Q_35DFF0 __attribute__((mode(TI)));
typedef struct {
    V_35DFF0 v[4];
    u32 col[4];
    f32 uv[4][2];
    u8 pad[24];
    unsigned long tag;
} P_35DFF0;
typedef struct {
    u8 pad0[0x10];
    V_35DFF0 v10;
    u8 pad1[0x68 - 0x20];
    void *p68;
} O_35DFF0;
extern V_35DFF0 D_001E2A40;
extern f32 func_004408C0(f32, f32);
extern void func_004075A8(void *, s32, s32, s32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_00405A58(void *, void *, s32);
void func_0035DFF0(O_35DFF0 *o) {
    V_35DFF0 m[4];
    P_35DFF0 q;
    V_35DFF0 r;
    void *s;
    f32 a;
    f32 b;
    s32 i;
    s = o->p68;
    a = func_004408C0(0.14f, 0.22f);
    b = func_004408C0(1.333f, 1.5f);
    func_0040C0F0(&m[0], s, 1.0f);
    {
        Q_35DFF0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m[1]) : "j"(x));
    }
    func_0040BF20(&m[2], &m[1], &m[0]);
    func_0040C0F0(&m[2], &m[2], a);
    func_0040C0F0(&m[0], &m[0], b);
    m[0].w = 0.0f;
    m[1].w = 0.0f;
    m[2].w = 0.0f;
    func_004075A8(&q, 0x3F, 1, 0x80);
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    for (i = 0; i < 4; i++) {
        __asm__ __volatile__("sq $0, %0" : "=m"(*(Q_35DFF0 *)&q.v[i]));
        if (i < 2) {
            q.v[i].x = 0.0f;
        } else {
            q.v[i].x = 1.0f;
        }
        q.v[i].y = 0.0f;
        if (i & 1) {
            q.v[i].z = 1.0f;
        } else {
            q.v[i].z = -1.0f;
        }
        q.v[i].w = 1.0f;
        q.col[i] = 0x7FFFFFFF;
    }
    func_0040C0F0(&r, s, -1.25f);
    {
        Q_35DFF0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(r));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m[3]) : "j"(x));
    }
    m[3].w = 1.0f;
    func_00405A58(&q, m, 0);
}
/* localdecomp:end func_0035DFF0 */
