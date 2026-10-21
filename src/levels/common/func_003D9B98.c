#include "common.h"

/* localdecomp:start func_003D9B98 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3D9B98;
typedef int Q_3D9B98 __attribute__((mode(TI)));
typedef struct {
    V_3D9B98 v[4];
    u32 col[4];
    f32 uv[4][2];
    u8 pad[24];
    unsigned long tag;
} P_3D9B98;
extern V_3D9B98 D_001E2A40;
extern V_3D9B98 D_001A4EC0;
extern V_3D9B98 D_001D7C50[4];
extern void func_004075A8(void *, s32, s32, s32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040C638(void *, void *);
extern void func_0040C960(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern void func_004C1FE8(s32, unsigned long);
extern void func_00405A58(void *, void *, s32);
extern void func_00401BB0(void *, f32 *, f32 *);
extern s32 func_00440848(s32);
extern f32 func_004408C0(f32, f32);

void func_003D9B98(V_3D9B98 *pos, s32 tex, s32 flag, f32 size, f32 dist, f32 ang, f32 jit) {
    P_3D9B98 q;
    V_3D9B98 m[4];
    V_3D9B98 t;
    V_3D9B98 c;
    V_3D9B98 d;
    V_3D9B98 e[1];
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    func_004075A8(&q, tex, 1, 128);
    {
        Q_3D9B98 x, y;
        q.tag = 0x800000004AUL;
        m[3] = *pos;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E2A40));
        q.col[3] = 0x80808080;
        q.col[2] = 0x80808080;
        q.col[1] = 0x80808080;
        q.col[0] = 0x80808080;
        q.uv[0][0] = 0.0f;
        q.uv[0][1] = 0.0f;
        q.uv[1][0] = 0.0f;
        q.uv[1][1] = 1.0f;
        q.uv[2][0] = 1.0f;
        q.uv[2][1] = 0.0f;
        q.uv[3][0] = 1.0f;
        q.uv[3][1] = 1.0f;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m[3]));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m[0]) : "j"(x));
    }
    func_0040C0F0(&m[0], &m[0], 1.0f);
    func_0040BF20(&m[1], &m[0], &D_001A4EC0);
    func_0040C0F0(&m[1], &m[1], 1.0f);
    func_0040BF20(&m[2], &m[1], &m[0]);
    if (ang != 0.0f) {
        *(Q_3D9B98 *)&t = 0;
        t.x = ang;
        func_0040C638(&c, &t);
        func_0040C960(&m[0], &m[0], &c);
    }
    func_0040BE90(&t, &m[0], dist);
    {
        Q_3D9B98 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m[3]));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m[3]) : "j"(x));
    }
    for (i = 0; i < 4; i++) {
        func_0040BE90(&q.v[i], &D_001D7C50[i], size);
        func_0040C2F8(&q.v[i], &q.v[i], m);
    }
    func_004C1FE8(71, 0x31001);
    func_00405A58(&q, 0, 0);
    if (flag != 0) {
        c = q.v[0];
        for (j = 1; j < 4; j++) {
            Q_3D9B98 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(q.v[j]));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(c));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(c) : "j"(x));
        }
        func_0040BE90(&c, &c, 0.25f);
        for (k = 0; k < 4; k++) {
            {
                Q_3D9B98 x, y;
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(c));
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(q.v[k]));
                __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
            }
            func_0040BE90(&d, &d, 2.0f);
            {
                Q_3D9B98 x, y;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(c));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
                __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
            }
            func_00401BB0(&d, &q.uv[k][0], &q.uv[k][1]);
            if (func_00440848(1) == 0) {
                q.uv[k][0] += func_004408C0(-jit, jit);
                q.uv[k][1] += func_004408C0(-jit, jit);
            }
            if (q.uv[k][0] > 1.0f) {
                q.uv[k][0] = 1.0f;
            } else if (q.uv[k][0] < 0.0f) {
                q.uv[k][0] = 0.0f;
            }
            if (q.uv[k][1] > 1.0f) {
                q.uv[k][1] = 1.0f;
            } else if (q.uv[k][1] < 0.0f) {
                q.uv[k][1] = 0.0f;
            }
        }
    } else {
        for (l = 0; l < 4; l++) {
            func_00401BB0(&q.v[l], &q.uv[l][0], &q.uv[l][1]);
            if (func_00440848(1) == 0) {
                q.uv[l][0] += func_004408C0(-jit, jit);
                q.uv[l][1] += func_004408C0(-jit, jit);
            }
            if (q.uv[l][0] > 1.0f) {
                q.uv[l][0] = 1.0f;
            } else if (q.uv[l][0] < 0.0f) {
                q.uv[l][0] = 0.0f;
            }
            if (q.uv[l][1] > 1.0f) {
                q.uv[l][1] = 1.0f;
            } else if (q.uv[l][1] < 0.0f) {
                q.uv[l][1] = 0.0f;
            }
        }
    }
    func_004075A8(&q, -1, 6, 128);
    func_004C1FE8(71, 0x53001);
    func_00405A58(&q, 0, 0);
    func_004C1FE8(71, 0x5360B);
}
/* localdecomp:end func_003D9B98 */
