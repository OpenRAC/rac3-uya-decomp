#include "common.h"

/* localdecomp:start func_003B00A0 */
typedef int Q_3B00A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B00A0;
typedef struct { f32 u, v; } UV_3B00A0;
typedef struct {
    V4_3B00A0 v[4];
    s32 c[4];
    UV_3B00A0 uv[4];
    unsigned long gif[4];
} Quad_3B00A0;
typedef struct {
    V4_3B00A0 v0;
    V4_3B00A0 v10;
    u8 pad20[24];
    f32 f38;
    u8 pad3C[8];
    s32 i44;
    s32 i48;
    u8 pad4C[8];
    f32 f54;
} P_3B00A0;
typedef struct {
    u8 pad0[104];
    P_3B00A0 *p;
} O_3B00A0;
extern V4_3B00A0 D_001E2A40;
extern f32 D_001DE650[2];
extern f32 D_001DE654[2];
extern void func_0040BF20(void *, void *, void *);
extern f32 func_00440918(f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern unsigned long func_00401CD0(s32);
extern void func_00405A58(void *, s32, s32);

static __inline__ V4_3B00A0 vsub_3B00A0(V4_3B00A0 *a, V4_3B00A0 *b) {
    V4_3B00A0 r;
    Q_3B00A0 x, y;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(r) : "j"(x));
    return r;
}
static __inline__ V4_3B00A0 vadd_3B00A0(V4_3B00A0 *a, V4_3B00A0 *b) {
    V4_3B00A0 r;
    Q_3B00A0 x, y;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(r) : "j"(x));
    return r;
}

static __inline__ void vsubp_3B00A0(V4_3B00A0 *d, V4_3B00A0 *a, V4_3B00A0 *b) {
    Q_3B00A0 x, y;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(x));
}

void func_003B00A0(O_3B00A0 *obj, V4_3B00A0 *arg) {
    V4_3B00A0 t;
    Quad_3B00A0 q;
    V4_3B00A0 m[3];
    P_3B00A0 *p;
    f32 s;
    s32 i;
    unsigned long g;

    t = *arg;
    p = obj->p;
    s = p->f54;
    if (p->f38 > 84.0f) {
        s = s * (1.0f - (p->f38 - 84.0f) / 6.0f);
        if (s < 0.001f) {
            s = 0.001f;
        }
    }
    vsubp_3B00A0(&m[2], &p->v0, &p->v10);
    vsubp_3B00A0(&m[0], &p->v0, &D_001E2A40);
    vsubp_3B00A0(&m[1], &p->v10, &D_001E2A40);
    func_0040BF20(&m[0], &m[0], &m[2]);
    func_0040C0F0(&m[0], &m[0], (p->f54 + func_00440918(0.1f, 0.3f)) * s);
    func_0040BF20(&m[1], &m[1], &m[2]);
    func_0040C0F0(&m[1], &m[1], (p->f54 + func_00440918(0.1f, 0.3f)) * s);
    g = func_00401CD0(0x3E);
    q.gif[2] = 0xFF9000000260UL;
    q.gif[1] = g;
    q.gif[3] = 0x3000000048UL;
    q.gif[0] = 0;
    q.c[0] = q.c[1] = q.c[2] = q.c[3] = p->i44;
    {
        s32 i;
        for (i = 0; i < 4; i++) {
            q.uv[i].u = D_001DE650[i * 2];
            q.uv[i].v = D_001DE654[i * 2];
        }
    }
    {
        q.v[0] = vsub_3B00A0(&p->v0, &m[0]);
    }
    {
        q.v[1] = vadd_3B00A0(&p->v0, &m[0]);
    }
    {
        q.v[2] = vsub_3B00A0(&p->v10, &m[1]);
    }
    {
        q.v[3] = vadd_3B00A0(&p->v10, &m[1]);
    }
    func_00405A58(&q, 0, 0);

    vsubp_3B00A0(&m[2], &p->v0, &p->v10);
    vsubp_3B00A0(&m[0], &p->v0, &D_001E2A40);
    vsubp_3B00A0(&m[1], &p->v10, &D_001E2A40);
    func_0040BF20(&m[0], &m[0], &m[2]);
    func_0040C0F0(&m[0], &m[0], (p->f54 * 0.5f + func_00440918(0.05f, 0.15f)) * s);
    func_0040BF20(&m[1], &m[1], &m[2]);
    func_0040C0F0(&m[1], &m[1], (p->f54 * 0.5f + func_00440918(0.05f, 0.15f)) * s);
    q.gif[1] = func_00401CD0(0x3F);
    q.gif[2] = 0xFF9000000260UL;
    q.gif[3] = 0x3000000048UL;
    q.gif[0] = 0;
    q.c[0] = q.c[1] = q.c[2] = q.c[3] = p->i48;
    for (i = 0; i < 4; i++) {
        q.uv[i].u = D_001DE650[i * 2];
        q.uv[i].v = D_001DE654[i * 2];
    }
    {
        q.v[0] = vsub_3B00A0(&p->v0, &m[0]);
    }
    {
        q.v[1] = vadd_3B00A0(&p->v0, &m[0]);
    }
    {
        q.v[2] = vsub_3B00A0(&p->v10, &m[1]);
    }
    {
        q.v[3] = vadd_3B00A0(&p->v10, &m[1]);
    }
    func_00405A58(&q, 0, 0);
}
/* localdecomp:end func_003B00A0 */
