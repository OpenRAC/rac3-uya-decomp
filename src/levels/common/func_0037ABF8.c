#include "common.h"

/* localdecomp:start func_0037ABF8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0037ABF8;
typedef int Q_0037ABF8 __attribute__((mode(TI)));
typedef struct {
    V_0037ABF8 v[4];
    u32 col[4];
    f32 uv[4][2];
    u8 pad[24];
    unsigned long tag;
} P_0037ABF8;
extern V_0037ABF8 D_001D7C50[];
extern void func_004075A8(void *, s32, s32, s32);
extern void func_0040C638(void *, void *);
extern void func_0040C960(void *, void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C2F8(void *, void *, void *);
extern void func_00405A58(void *, s32, s32);
void func_0037ABF8(u8 *o, V_0037ABF8 *p, s32 tex, u32 col, s32 flag, f32 size, f32 off, f32 ang) {
    P_0037ABF8 q;
    V_0037ABF8 m[4];
    V_0037ABF8 rot;
    V_0037ABF8 t[3];
    s32 i;

    func_004075A8(&q, tex, flag, 128);
    q.col[3] = col;
    q.col[2] = col;
    q.col[1] = col;
    q.col[0] = col;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    *(Q_0037ABF8 *)&m[3] = *(Q_0037ABF8 *)p;
    *(Q_0037ABF8 *)&m[0] = *(Q_0037ABF8 *)(o + 0xC0);
    *(Q_0037ABF8 *)&m[1] = *(Q_0037ABF8 *)(o + 0xD0);
    *(Q_0037ABF8 *)&m[2] = *(Q_0037ABF8 *)(o + 0xE0);
    if (ang != 0.0f) {
        *(Q_0037ABF8 *)&rot = 0;
        rot.x = ang;
        func_0040C638(t, &rot);
        func_0040C960(&m[0], &m[0], t);
    }
    func_0040BE90(&rot, &m[0], off);
    {
        Q_0037ABF8 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m[3]));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(rot));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m[3]) : "j"(x));
    }
    for (i = 0; i < 4; i++) {
        func_0040BE90(&q.v[i], &D_001D7C50[i], size);
        func_0040C2F8(&q.v[i], &q.v[i], m);
    }
    func_00405A58(&q, 0, 0);
}
/* localdecomp:end func_0037ABF8 */
