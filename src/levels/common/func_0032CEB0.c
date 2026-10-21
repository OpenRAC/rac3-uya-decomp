#include "common.h"

/* localdecomp:start func_0032CEB0 */
typedef int Q_32CEB0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_32CEB0;
typedef struct {
    V4_32CEB0 v[4];
    u32 c[4];
    V4_32CEB0 uv[2];
    unsigned long tag[4];
} B_32CEB0;
typedef struct { V4_32CEB0 r[4]; } M_32CEB0;
typedef struct { u8 b0; u8 b1; u8 pad[238]; } S_32CEB0;
typedef struct {
    u8 pad0[0x30];
    V4_32CEB0 v30;
} P_32CEB0;
typedef struct {
    u8 pad0[0x68];
    P_32CEB0 *p;
    u8 pad6C[0x54];
    M_32CEB0 mC0;
} O_32CEB0;
extern void func_00437698(void *, s32, void *);
extern f32 func_004408C0(f32, f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0032CAF8(O_32CEB0 *, V4_32CEB0 *);
extern void func_0032CA20(B_32CEB0 *);
extern s32 func_0013D3E0(void);
extern long func_00401CD0(s32);
extern void func_0040C0F0(V4_32CEB0 *, V4_32CEB0 *, f32);
extern void func_0040BF20(V4_32CEB0 *, V4_32CEB0 *, V4_32CEB0 *);
extern void func_0040BE90(V4_32CEB0 *, V4_32CEB0 *, f32);
extern void func_0040C2F8(V4_32CEB0 *, V4_32CEB0 *, M_32CEB0 *);
extern void func_00405A58(B_32CEB0 *, s32, s32);
extern u8 D_001425C0[];
extern S_32CEB0 D_002C5640[];
extern V4_32CEB0 D_001E2A40;

void func_0032CEB0(O_32CEB0 *obj) {
    B_32CEB0 buf;
    B_32CEB0 buf2;
    M_32CEB0 m;
    V4_32CEB0 pos;
    V4_32CEB0 dir;
    V4_32CEB0 out;
    P_32CEB0 *p;
    u32 a, b;
    Q_32CEB0 x, y;

    p = obj->p;
    func_00437698(obj, 1, &out);
    pos = out;
    func_0040C0F0(&dir, &p->v30, func_004408C0(2.0f, 4.0f));
    func_0040C2D0(&dir, &dir, &obj->mC0);
    {
        Q_32CEB0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(dir));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(out));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(x));
    }
    func_0032CAF8(obj, &pos);
    buf.tag[1] = func_00401CD0(0x17);
    buf.tag[2] = 0xFF9000000260;
    buf.tag[0] = 0;
    buf.tag[3] = 0x8000000048;
    if (((S_32CEB0 *)(D_001425C0[21] * 240 + (s32)D_002C5640))->b1 >= 2) {
        a = 0x803010;
        b = 0x7F803010;
        buf.c[3] = a;
        buf.c[2] = a;
        buf.c[1] = b;
        buf.c[0] = b;
    } else {
        a = 0x103080;
        b = 0x7F103080;
        buf.c[3] = a;
        buf.c[2] = a;
        buf.c[1] = b;
        buf.c[0] = b;
    }
    buf2.tag[1] = func_00401CD0(0x17);
    buf2.tag[2] = 0xFF9000000260;
    buf2.tag[3] = 0x8000000048;
    buf2.tag[0] = 0;
    if (((S_32CEB0 *)(D_001425C0[21] * 240 + (s32)D_002C5640))->b1 >= 2) {
        a = 0x803010;
        b = 0x3F803010;
        buf2.c[3] = a;
        buf2.c[2] = a;
        buf2.c[1] = b;
        buf2.c[0] = b;
    } else {
        a = 0x103080;
        b = 0x3F103080;
        buf2.c[3] = a;
        buf2.c[2] = a;
        buf2.c[1] = b;
        buf2.c[0] = b;
    }
    {
        V4_32CEB0 seg[2];

        *(Q_32CEB0 *)&seg[0] = 0;
        *(Q_32CEB0 *)&seg[1] = 0;
        seg[0].w = 1.0f;
        seg[1].w = 1.0f;
        seg[0].z = func_004408C0(0.1f, 0.3f);
        seg[1].z = seg[0].z * 2.0f;
        func_0032CA20(&buf);
        func_0032CA20(&buf2);
        if ((func_0013D3E0() & 1) == 0) {
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
        } else {
            buf.uv[0].x = 0.0f;
            buf.uv[0].y = 1.0f;
            buf.uv[0].z = 0.0f;
            buf.uv[0].w = 0.0f;
            buf.uv[1].x = 1.0f;
            buf.uv[1].y = 1.0f;
            buf.uv[1].z = 1.0f;
            buf.uv[1].w = 0.0f;
            buf2.uv[0].x = 0.0f;
            buf2.uv[0].y = 1.0f;
            buf2.uv[0].z = 0.0f;
            buf2.uv[0].w = 0.0f;
            buf2.uv[1].x = 1.0f;
            buf2.uv[1].y = 1.0f;
            buf2.uv[1].z = 1.0f;
            buf2.uv[1].w = 0.0f;
        }
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(dir));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(m.r[0]) : "j"(y));
        func_0040C0F0(&m.r[0], &m.r[0], 1.0f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E2A40));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(m.r[1]) : "j"(y));
        func_0040BF20(&m.r[2], &m.r[1], &m.r[0]);
        func_0040C0F0(&m.r[2], &m.r[2], 1.0f);
        func_0040BF20(&m.r[1], &m.r[0], &m.r[2]);
        *(Q_32CEB0 *)&m.r[3] = *(Q_32CEB0 *)&pos;
        *(Q_32CEB0 *)&buf.v[0] = *(Q_32CEB0 *)&seg[0];
        *(Q_32CEB0 *)&buf2.v[0] = *(Q_32CEB0 *)&seg[1];
        func_0040BE90(&buf.v[1], &buf.v[0], -1.0f);
        func_0040BE90(&buf2.v[1], &buf2.v[0], -1.0f);
        func_0040C2F8(&buf.v[0], &buf.v[0], &m);
        func_0040C2F8(&buf.v[1], &buf.v[1], &m);
        func_0040C2F8(&buf2.v[0], &buf2.v[0], &m);
        func_0040C2F8(&buf2.v[1], &buf2.v[1], &m);
        *(Q_32CEB0 *)&m.r[3] = *(Q_32CEB0 *)&dir;
        seg[0].z *= 0.15f;
        seg[1].z = seg[0].z * 2.0f;
        *(Q_32CEB0 *)&buf.v[2] = *(Q_32CEB0 *)&seg[0];
        *(Q_32CEB0 *)&buf2.v[2] = *(Q_32CEB0 *)&seg[1];
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
/* localdecomp:end func_0032CEB0 */
