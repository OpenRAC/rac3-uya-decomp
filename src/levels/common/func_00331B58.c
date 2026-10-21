#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_331B58;
typedef int Q_331B58 __attribute__((mode(TI)));
typedef struct {
    V_331B58 v[4];
    u32 col[4];
    f32 uv[4][2];
    u8 pad[24];
    unsigned long tag;
} P_331B58;
typedef struct { u8 pad[0x1D0]; V_331B58 v1D0; u8 pad2[1120 - 0x1E0]; } E_331B58;
extern s32 D_001D52F0;
extern E_331B58 D_001E2AC0[];
extern V_331B58 D_001D7C50[];
extern void func_004075A8(void *, s32, s32, s32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040C638(void *, void *);
extern void func_0040C960(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern void func_004C1FE8(s32, unsigned long);
extern void func_00405A58(void *, s32, s32);
extern void func_00401BB0(void *, f32 *, f32 *);
extern s32 func_00440848(s32);
extern f32 func_004408C0(f32, f32);

/* localdecomp:start func_00331B58 */
void func_00331B58(V_331B58 *p, s32 tex, s32 flag, f32 size, f32 off, f32 ang, f32 unused, f32 jit) {
    P_331B58 q;
    V_331B58 m[4];
    V_331B58 rot;
    V_331B58 t[3];
    s32 i;

    func_004075A8(&q, tex, 1, 128);
    q.tag = 0x800000004AUL;
    q.col[3] = 0x80808080;
    q.col[2] = 0x80808080;
    q.col[1] = 0x80808080;
    q.col[0] = 0x80808080;
    *(Q_331B58 *)&m[3] = *(Q_331B58 *)p;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    {
        Q_331B58 x, y;
        __asm__("lqc2 %0, %2\n\tlqc2 %1, %3" : "=&j"(y), "=j"(x) : "m"(m[3]), "m"(D_001E2AC0[D_001D52F0]), "m"(q));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m[0]) : "j"(x));
    }
    func_0040C0F0(&m[0], &m[0], 1.0f);
    { u8 *c2 = (u8 *)&D_001E2AC0[D_001D52F0]; func_0040BF20(&m[1], &m[0], c2 + 464); }
    func_0040C0F0(&m[1], &m[1], 1.0f);
    func_0040BF20(&m[2], &m[1], &m[0]);
    if (ang != 0.0f) {
        *(Q_331B58 *)&rot = 0;
        rot.x = ang;
        func_0040C638(t, &rot);
        func_0040C960(&m[0], &m[0], t);
    }
    func_0040BE90(&rot, &m[0], off);
    {
        Q_331B58 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m[3]));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(rot));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m[3]) : "j"(x));
    }
    for (i = 0; i < 4; i++) {
        func_0040BE90(&q.v[i], &D_001D7C50[i], size);
        func_0040C2F8(&q.v[i], &q.v[i], m);
    }
    func_004C1FE8(71, 0x31001);
    func_00405A58(&q, 0, 0);
    if (flag) {
        s32 j, k;
        *(Q_331B58 *)&t[0] = *(Q_331B58 *)&q.v[0];
        for (j = 1; j < 4; j++) {
            Q_331B58 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(q.v[j]));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t[0]));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(t[0]) : "j"(x));
        }
        func_0040BE90(&t[0], &t[0], 0.25f);
        for (k = 0; k < 4; k++) {
            {
                Q_331B58 x, y;
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t[0]));
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(q.v[k]));
                __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(t[1]) : "j"(x));
            }
            func_0040BE90(&t[1], &t[1], 0.8f);
            {
                Q_331B58 x, y;
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t[0]));
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t[1]));
                __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
                __asm__("sqc2 %1, %0" : "=m"(t[1]) : "j"(y));
            }
            func_00401BB0(&t[1], &q.uv[k][0], &q.uv[k][1]);
            if (0.0f < jit && func_00440848(1) == 0) {
                q.uv[k][0] += func_004408C0(-jit, jit);
                q.uv[k][1] += func_004408C0(-jit, jit);
            }
            if (1.0f < q.uv[k][0]) {
                q.uv[k][0] = 1.0f;
            } else if (q.uv[k][0] < 0.0f) {
                q.uv[k][0] = 0.0f;
            }
            if (1.0f < q.uv[k][1]) {
                q.uv[k][1] = 1.0f;
            } else if (q.uv[k][1] < 0.0f) {
                q.uv[k][1] = 0.0f;
            }
        }
    } else {
        s32 n;
        for (n = 0; n < 4; n++) {
            func_00401BB0(&q.v[n], &q.uv[n][0], &q.uv[n][1]);
            if (func_00440848(1) == 0) {
                q.uv[n][0] += func_004408C0(-jit, jit);
                q.uv[n][1] += func_004408C0(-jit, jit);
            }
            if (1.0f < q.uv[n][0]) {
                q.uv[n][0] = 1.0f;
            } else if (q.uv[n][0] < 0.0f) {
                q.uv[n][0] = 0.0f;
            }
            if (1.0f < q.uv[n][1]) {
                q.uv[n][1] = 1.0f;
            } else if (q.uv[n][1] < 0.0f) {
                q.uv[n][1] = 0.0f;
            }
        }
    }
    func_004075A8(&q, -1, 1, 128);
    q.tag = 0x8000000054UL;
    func_004C1FE8(71, 0x53001);
    func_00405A58(&q, 0, 0);
    func_004C1FE8(71, 0x5360B);
}
/* localdecomp:end func_00331B58 */
