#include "common.h"

/* localdecomp:start func_002F8F60 */
typedef int Q_2F8F60 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_2F8F60;
typedef struct {
    u8 pad0[16];
    f32 f16;
    u8 pad20[16];
    f32 f36;
} C_2F8F60;
typedef struct {
    u8 pad0[32];
    V4_2F8F60 v32;
    V4_2F8F60 v48;
    u8 pad64[45];
    u8 b109;
    u8 pad110[10];
    f32 f120;
} S_2F8F60;
typedef struct M_2F8F60 {
    u8 pad0[16];
    V4_2F8F60 pos;
    u8 pad32[4];
    C_2F8F60 *p36;
    u8 pad40[4];
    f32 f44;
    u8 b48;
    u8 b49;
    u16 h50;
    u16 h52;
    u8 pad54[45];
    u8 b99;
    u8 pad100[4];
    S_2F8F60 *s;
    u8 pad108[76];
    struct M_2F8F60 *p184;
    u8 pad188[4];
    u8 v192[48];
    u8 v240[16];
} M_2F8F60;
typedef struct {
    f32 f;
    u8 pad[24];
} T_2F8F60;
typedef struct {
    u8 pad[60];
    s32 i60;
} G_2F8F60;
extern V4_2F8F60 D_001E2A40;
extern G_2F8F60 D_00142660;
extern T_2F8F60 D_002BE748[];
extern void *D_001A71A0[];
extern f32 func_0040C018(V4_2F8F60 *, V4_2F8F60 *);
extern M_2F8F60 *func_00435E70(s32, s32);
extern void func_002F7888(void);
extern void func_00441FB8(M_2F8F60 *, s32, s32);
extern s32 func_002F9520(M_2F8F60 *);
extern void func_0040C638(void *, void *);
extern void func_0044B598(M_2F8F60 *, u32);
extern void func_00438938(M_2F8F60 *, s32 *, s32 *, s32 *);
extern void func_004388E8(M_2F8F60 *, s32, s32, s32, s32);
extern void func_00438908(M_2F8F60 *, s32, s32, s32);
extern s32 func_00440848(s32);
extern f32 func_004408C0(f32, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_004475E8(void *, void *, f32);
extern void func_002F8D80(M_2F8F60 *, void *, s32, f32, f32);
extern void func_00439610(M_2F8F60 *);
M_2F8F60 *func_002F8F60(M_2F8F60 *parent, V4_2F8F60 *pos, V4_2F8F60 *dir, s32 flags, s32 amount, s32 flag2) {
    M_2F8F60 *m;
    M_2F8F60 *p;
    s32 id;
    s32 a, b, c;
    f32 f;
    f32 r;
    V4_2F8F60 t0, t1;
    Q_2F8F60 x, y;
    S_2F8F60 *s;

    if (func_0040C018(pos, &D_001E2A40) >= 4096.0f) {
        D_00142660.i60 += amount;
        return 0;
    }
    if (amount >= 30000) {
        id = 7077;
    } else if (amount >= 10000) {
        id = 7517;
    } else if (amount >= 3000) {
        id = 7516;
    } else if (amount >= 1000) {
        id = 19;
    } else if (amount >= 500) {
        id = 18;
    } else if (amount >= 100) {
        id = 17;
    } else if (amount >= 50) {
        id = 16;
    } else if (amount >= 20) {
        id = 15;
    } else if (amount >= 50) {
        id = 14;
    } else {
        id = 13;
    }
    m = func_00435E70(id, 128);
    if (m == 0) {
        return 0;
    }
    func_002F7888();
    s = m->s;
    s->b109 = 0;
    if (flag2) {
        s->b109 = 2;
    }
    if (parent == 0) {
        p = 0;
    } else {
        M_2F8F60 *q = parent;
        while (q->p184 != 0) {
            q = q->p184;
        }
        p = q;
    }
    m->p184 = p;
    m->b99 = 10;
    m->b48 = 64;
    m->h50 = 64;
    m->b49 = 1;
    func_00441FB8(m, 1, -1);
    m->h52 |= 0x100;
    m->f44 = m->p36->f36 * D_002BE748[func_002F9520(m)].f;
    func_0040C638(m->v192, m->v240);
    func_0044B598(m, 0x80181010);
    func_00438938(m, &a, &b, &c);
    func_004388E8(m, 0, 13, 0, 0);
    func_00438908(m, a, b, c);
    m->pos = *pos;
    s->v48 = *dir;
    if (func_00440848(2)) {
        s->b109 |= 1;
    }
    s->f120 = m->pos.z;
    r = func_004408C0(0.0f, 0.20943953f);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m->pos));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(parent->pos));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(t1) : "j"(x));
    func_0040BF20(&t0, &s->v48, &t1);
    func_0040C0F0(&s->v32, &t0, 1.0f);
    func_004475E8(&s->v32, &s->v32, r);
    if (flags & 2) {
        f = 0.0f;
        if (flags & 0x10) {
            f = func_004408C0(-0.5235988f, 0.5235988f);
        }
        func_002F8D80(m, D_001A71A0[0], 0, f, 0.0f);
    }
    func_00439610(m);
    return m;
}
/* localdecomp:end func_002F8F60 */
