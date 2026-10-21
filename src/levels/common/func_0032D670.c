#include "common.h"

/* localdecomp:start func_0032D670 */
/* PROVISIONAL, VU0 j-constraint form */
typedef int Q_32D670 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32D670;
typedef struct {
    V4_32D670 v[4];
    u32 c[4];
    V4_32D670 uv[2];
    unsigned long tag[4];
} B_32D670;
typedef struct { V4_32D670 r[4]; } M_32D670;
typedef struct { u8 b0; u8 b1; u8 pad[238]; } S_32D670;
extern void func_0032CA20(B_32D670 *);
extern long func_00401CD0(s32);
extern void func_0032D350(s32, V4_32D670 *);
extern void func_0040C0F0(V4_32D670 *, V4_32D670 *, f32);
extern void func_0040BF20(V4_32D670 *, V4_32D670 *, V4_32D670 *);
extern void func_0040BE90(V4_32D670 *, V4_32D670 *, f32);
extern void func_0040C2F8(V4_32D670 *, V4_32D670 *, M_32D670 *);
extern void func_00405A58(B_32D670 *, M_32D670 *, s32);
extern u8 D_001425C0[];
extern S_32D670 D_002C5640[];
extern V4_32D670 D_001E2A40;

void func_0032D670(s32 a0, V4_32D670 *pos, V4_32D670 *tgt) {
    B_32D670 buf;
    B_32D670 buf2;
    M_32D670 m;
    u32 c;
    Q_32D670 x, y;

    buf.tag[1] = func_00401CD0(14);
    buf.c[1] = 0x7F7F7F7F;
    buf.c[0] = 0x7F7F7F7F;
    buf.tag[2] = 0xFF9000000260;
    buf.tag[0] = 0;
    buf.tag[3] = 0x8000000048;
    buf2.tag[1] = func_00401CD0(14);
    buf2.tag[2] = 0xFF9000000260;
    buf2.tag[3] = 0x8000000048;
    buf2.tag[0] = 0;
    if (((S_32D670 *)(D_001425C0[21] * 240 + (s32)D_002C5640))->b1 >= 2) {
        c = 0x7F806060;
        buf2.c[1] = c;
        buf2.c[0] = c;
    } else {
        c = 0x7F000080;
        buf2.c[1] = c;
        buf2.c[0] = c;
    }
    {
        V4_32D670 seg[2];

        *(Q_32D670 *)&seg[0] = 0;
        *(Q_32D670 *)&seg[1] = 0;
        seg[0].z = 0.015f;
        seg[1].z = 0.0824999958f;
        seg[0].w = 1.0f;
        seg[1].w = 1.0f;

        func_0032CA20(&buf);
        func_0032CA20(&buf2);
        func_0032D350(a0, pos);
        buf.uv[0].x = 0.0f;
        buf.uv[0].y = 0.0f;
        buf.uv[0].z = 0.0f;
        buf.uv[0].w = 1.0f;
        buf.uv[1].x = 1.0f;
        buf.uv[1].y = 0.0f;
        buf.uv[1].z = 1.0f;
        buf.uv[1].w = 1.0f;
        buf2.uv[0].x = 0.0f;
        buf2.uv[0].y = 0.0f;
        buf2.uv[0].z = 0.0f;
        buf2.uv[0].w = 1.0f;
        buf2.uv[1].x = 1.0f;
        buf2.uv[1].y = 0.0f;
        buf2.uv[1].z = 1.0f;
        buf2.uv[1].w = 1.0f;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*tgt));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(m.r[0]) : "j"(y));
        func_0040C0F0(&m.r[0], &m.r[0], 1.0f);
        {
            Q_32D670 a, b;

            __asm__("lqc2 %0, %1" : "=j"(a) : "m"(*pos));
            __asm__("lqc2 %0, %1" : "=j"(b) : "m"(D_001E2A40));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(b) : "j"(b), "j"(a));
            __asm__("sqc2 %1, %0" : "=m"(m.r[1]) : "j"(b));
        }
        func_0040BF20(&m.r[2], &m.r[1], &m.r[0]);
        func_0040C0F0(&m.r[2], &m.r[2], 1.0f);
        func_0040BF20(&m.r[1], &m.r[0], &m.r[2]);
        *(Q_32D670 *)&m.r[3] = *(Q_32D670 *)pos;
        *(Q_32D670 *)&buf.v[0] = *(Q_32D670 *)&seg[0];
        *(Q_32D670 *)&buf2.v[0] = *(Q_32D670 *)&seg[1];
        func_0040BE90(&buf.v[1], &buf.v[0], -1.0f);
        func_0040BE90(&buf2.v[1], &buf2.v[0], -1.0f);
        func_0040C2F8(&buf.v[0], &buf.v[0], &m);
        func_0040C2F8(&buf.v[1], &buf.v[1], &m);
        func_0040C2F8(&buf2.v[0], &buf2.v[0], &m);
        func_0040C2F8(&buf2.v[1], &buf2.v[1], &m);
        *(Q_32D670 *)&m.r[3] = *(Q_32D670 *)tgt;
        if (((S_32D670 *)(D_001425C0[21] * 240 + (s32)D_002C5640))->b1 >= 2) {
            c = 0x806060;
            buf2.c[3] = c;
            buf2.c[2] = c;
        } else {
            c = 0x80;
            buf2.c[3] = c;
            buf2.c[2] = c;
        }
        seg[0].z *= 0.25f;
        seg[1].z = seg[0].z * 5.5f;
        *(Q_32D670 *)&buf.v[2] = *(Q_32D670 *)&seg[0];
        *(Q_32D670 *)&buf2.v[2] = *(Q_32D670 *)&seg[1];
        func_0040BE90(&buf.v[3], &buf.v[2], -1.0f);
        func_0040BE90(&buf2.v[3], &buf2.v[2], -1.0f);
        func_0040C2F8(&buf.v[2], &buf.v[2], &m);
        func_0040C2F8(&buf.v[3], &buf.v[3], &m);
        func_0040C2F8(&buf2.v[2], &buf2.v[2], &m);
        func_0040C2F8(&buf2.v[3], &buf2.v[3], &m);
        func_00405A58(&buf, 0, 0);
        func_00405A58(&buf2, 0, 0);
    }
}
/* localdecomp:end func_0032D670 */
