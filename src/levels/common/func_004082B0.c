#include "common.h"

/* localdecomp:start func_004082B0 */
typedef struct { u8 pad0[0x24]; f32 f24; f32 f28; u8 pad2C[4]; s32 f30; u8 pad34[4]; s32 f38; s32 f3C; u8 pad40[8]; s32 f48; s32 f4C; } E_3A3028;
extern void func_004082B0(E_3A3028 *, s32, s32, s32, f32, f32, f32);
extern void func_004075A8(void *, s32, s32, long);

typedef int Q_3D3FA0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3D3FA0;
typedef struct { V_3D3FA0 v[4]; s32 c[4]; f32 uv[8]; long t70, t78, t80, t88; } B_3D3FA0;
extern V_3D3FA0 D_001E2A40_003D3FA0[];
extern V_3D3FA0 D_001D7C50[];
typedef struct { u8 pad[0x80]; f32 f80[4]; u8 pad2[0x3D0]; } G_3D3FA0;
extern G_3D3FA0 D_001E2C10_003D3FA0[];
extern u8 D_001E2C10[];
extern s32 D_001D52F0;
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040C638(void *, void *);
extern void func_0040C960(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern void func_00405A58(void *, s32, s32);
void func_004082B0(E_3A3028 *e, s32 tex, s32 col, s32 blend, f32 size, f32 dist, f32 ang) {
    B_3D3FA0 buf;
    V_3D3FA0 m[4];
    V_3D3FA0 q;
    f32 rot[12];
    Q_3D3FA0 a, b, r;
    s32 k;
    G_3D3FA0 *p;
    func_004075A8(&buf, tex, blend, 0x80);
    *(Q_3D3FA0 *)&m[3] = *(Q_3D3FA0 *)e;
    buf.c[3] = col;
    buf.c[2] = col;
    buf.c[1] = col;
    buf.c[0] = col;
    buf.uv[0] = 0;
    buf.uv[1] = 0;
    buf.uv[2] = 0;
    buf.uv[3] = 1.0f;
    buf.uv[4] = 1.0f;
    buf.uv[5] = 0;
    buf.uv[6] = 1.0f;
    buf.uv[7] = 1.0f;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(D_001E2A40_003D3FA0[0]));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(m[3]));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(m[0]) : "j"(a));
    func_0040C0F0(&m[0], &m[0], 1.0f);
    p = &D_001E2C10_003D3FA0[D_001D52F0];
    func_0040BF20(&m[1], &m[0], (u8 *)p + 0x80);
    func_0040C0F0(&m[1], &m[1], 1.0f);
    func_0040BF20(&m[2], &m[1], &m[0]);
    if (ang != 0) {
        *(Q_3D3FA0 *)&q = 0;
        q.x = ang;
        func_0040C638(rot, &q);
        func_0040C960(&m[0], &m[0], rot);
    }
    func_0040BE90(&q, &m[0], dist);
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(m[3]));
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(q));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(b) : "j"(b), "j"(a));
    __asm__("sqc2 %1, %0" : "=m"(m[3]) : "j"(b));
    for (k = 0; k < 4; k++) {
        func_0040BE90(&buf.v[k], &D_001D7C50[k], size);
        func_0040C2F8(&buf.v[k], &buf.v[k], m);
    }
    func_00405A58(&buf, 0, 0);
}
/* localdecomp:end func_004082B0 */
