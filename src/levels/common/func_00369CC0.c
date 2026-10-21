#include "common.h"

/* localdecomp:start func_00369CC0 */
typedef int Q_369CC0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_369CC0;
typedef struct { u8 b0, b1, b2, b3; } P_369CC0;

typedef struct {
    V4_369CC0 v0;
    u8 pad10[16];
    V4_369CC0 v32;
    u8 pad30[8];
    s32 w56;
    u8 pad3C[20];
    V4_369CC0 v80;
    f32 f96;
} V_369CC0;

typedef struct {
    u8 pad0[16];
    union {
        Q_369CC0 q;
        V4_369CC0 v;
    } pos;
    u8 state;
    u8 pad21[104 - 33];
    V_369CC0 *vars;
} M_369CC0;

typedef struct {
    Q_369CC0 a;
    Q_369CC0 b;
    Q_369CC0 c;
} L_369CC0;

typedef struct {
    u8 pad[0x16C];
    u8 *p;
} G_369CC0;

extern u8 D_001D66B0;
extern u8 *D_002211EC[];
extern G_369CC0 D_00221118;

extern void func_0044DF40(void *, void *, s32);
extern s32 func_004C7670(void);
extern void func_004C6EC8(void *, void *);
extern s32 func_0040BA90(void *);
extern void func_00436220(void *);
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_00440848(s32);
extern P_369CC0 *func_0046C468(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_0036A198();
extern void func_004026A0(void *, void *);
extern f32 func_004408C0(f32, f32);
extern void func_0040BE68(f32, void *, void *, void *);
extern f32 func_00440918(f32, f32);

void func_00369CC0(M_369CC0 *m) {
    L_369CC0 l;
    V4_369CC0 p48;
    V4_369CC0 p64;
    V_369CC0 *vars;
    V4_369CC0 *vel;
    P_369CC0 *p;
    P_369CC0 *q;
    s32 c;
    s32 n;
    s32 i;
    f32 t;
    f32 a;
    f32 s;
    f32 r;

    l.a = m->pos.q;
    vars = m->vars;
    func_0044DF40(&m->pos, &l.b, 1);
    l.c = m->pos.q;
    if (func_004C7670()) {
        func_004C6EC8(&m->pos, &m->pos);
        func_004C6EC8(&vars->v80, &vars->v80);
        func_004C6EC8(vars, vars);
    }
    if (m->state == 0) {
        {
            V4_369CC0 *pd = &vars->v80;
            V4_369CC0 *pa = &vars->v80;
            V4_369CC0 *pb = &vars->v32;
            Q_369CC0 x, y, d;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pa));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pb));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(d) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(*pd) : "j"(d));
        }
        if (func_0040BA90(&vars->w56)) {
            func_00436220(m);
            return;
        }
        func_0040C0F0(&p48, &vars->v32, -0.5f);
        {
            Q_369CC0 x, y, d;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p48));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m->pos.v));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(d) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(p48) : "j"(d));
        }
        c = func_00440848(255);
        p = func_0046C468(&p48, &D_001D66B0, 2, 0x202080, c, 32, 16, 420000.0f, 420000.0f, 0.0f, 2);
        if (p != 0) {
            p->b2 = D_002211EC[0][0];
        }
        c = (c + 128) % 255;
        p = func_0046C468(&p48, &D_001D66B0, 2, 0x204080, c, 32, 16, 420000.0f, 420000.0f, 0.0f, 2);
        if (p != 0) {
            p->b2 = D_002211EC[0][0];
        }
        func_004026A0(func_0036A198, m);
        for (i = 1; i >= 0; i--) {
            t = func_004408C0(0.0f, 1.0f);
            func_0040BE68(t, &p64, vars, &p48);
            {
                s32 r0 = func_00440848(255);
                a = -(vars->f96 * 180.0f / 3.1415927f);
                c = r0;
            }
            n = t * 20.0f - a;
            s = 1.8f - a * 0.01f * 5.0f;
            if (n >= 10) {
                n = 9;
            } else if (n < 2) {
                n = 2;
            }
            p64.x += func_00440918(0.0f, 0.04f);
            p64.y += func_00440918(0.0f, 0.04f);
            p64.z += func_00440918(0.0f, 0.04f);
            q = func_0046C468(&p64, &vars->v32, n, 0xFF1010, c, 48, 0, s * 210000.0f, s * 0.2f * 210000.0f, a * 5.0f * (1.0f / 3600.0f), 2);
            if (q != 0) {
                q->b2 = *D_00221118.p;
            }
            s = s * 0.5f;
            q = func_0046C468(&p64, &vars->v32, n, 0x808080, c, 48, 0, s * 210000.0f, s * 0.2f * 210000.0f, a * 5.0f * (1.0f / 3600.0f), 2);
            if (q != 0) {
                q->b2 = *D_00221118.p;
            }
        }
    }
    if (m->pos.v.x < 2.0f || 1021.0f < m->pos.v.x || m->pos.v.y < 2.0f || 1021.0f < m->pos.v.y ||
        m->pos.v.z < 2.0f || 1021.0f < m->pos.v.z) {
        func_00436220(m);
    }
}
/* localdecomp:end func_00369CC0 */
