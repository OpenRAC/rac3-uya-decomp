#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3630E0;
typedef int Q_3630E0 __attribute__((mode(TI)));
typedef struct {
    V_3630E0 v[4];
    u32 col[4];
    f32 uv[4][2];
    u8 pad[24];
    unsigned long tag;
} P_3630E0;
extern V_3630E0 D_001E2AC0;
extern V_3630E0 D_001A4EC0;
extern V_3630E0 D_001D7C50[];
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

/* localdecomp:start func_003630E0 */
void func_003630E0(V_3630E0 *p, s32 tex, f32 size, f32 off, f32 ang, f32 scale) {
    P_3630E0 q;
    V_3630E0 m[4];
    V_3630E0 rot;
    V_3630E0 t[3];
    s32 i;
    s32 j;
    s32 k;

    func_004075A8(&q, tex, 1, 128);
    q.tag = 0x800000004AUL;
    q.col[3] = 0x80808080;
    q.col[2] = 0x80808080;
    q.col[1] = 0x80808080;
    q.col[0] = 0x80808080;
    *(Q_3630E0 *)&m[3] = *(Q_3630E0 *)p;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    {
        Q_3630E0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E2AC0));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m[3]));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m[0]) : "j"(x));
    }
    func_0040C0F0(&m[0], &m[0], 1.0f);
    func_0040BF20(&m[1], &m[0], &D_001A4EC0);
    func_0040C0F0(&m[1], &m[1], 1.0f);
    func_0040BF20(&m[2], &m[1], &m[0]);
    if (ang != 0.0f) {
        *(Q_3630E0 *)&rot = 0;
        rot.x = ang;
        func_0040C638(t, &rot);
        func_0040C960(&m[0], &m[0], t);
    }
    func_0040BE90(&rot, &m[0], off);
    {
        Q_3630E0 x, y;
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
    *(Q_3630E0 *)&t[0] = *(Q_3630E0 *)&q.v[0];
    for (j = 1; j < 4; j++) {
        Q_3630E0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(q.v[j]));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t[0]));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t[0]) : "j"(x));
    }
    func_0040BE90(&t[0], &t[0], 0.25f);
    for (k = 0; k < 4; k++) {
        {
            Q_3630E0 x, y;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(q.v[k]));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t[0]));
            __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(t[1]) : "j"(x));
        }
        func_0040BE90(&t[1], &t[1], scale);
        {
            Q_3630E0 x, y;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t[0]));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t[1]));
            __asm__("vadd.xyz %0, %0, %1" : "+j"(y) : "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(t[1]) : "j"(y));
        }
        func_00401BB0(&t[1], &q.uv[k][0], &q.uv[k][1]);
    }
    func_004075A8(&q, -1, 1, 128);
    q.tag = 0x2000000054UL;
    func_004C1FE8(71, 0x53001);
    func_00405A58(&q, 0, 0);
    func_004C1FE8(71, 0x5360B);
}
/* localdecomp:end func_003630E0 */
