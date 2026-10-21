#include "common.h"

/* localdecomp:start func_0046E030 */
typedef int Q_46E030 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_46E030;
typedef struct {
    V4_46E030 vel;
    u8 pad16[4];
    s16 h20;
    s16 h22;
    u8 pad24[4];
    f32 f28;
} S_46E030;
typedef struct {
    u8 pad0[4];
    u32 color;
    u8 b8;
    u8 pad9;
    s16 h10;
    u8 pad12[4];
    V4_46E030 pos;
    S_46E030 s;
} P_46E030;
typedef struct {
    u8 pad0[128];
    V4_46E030 pos;
    u8 pad144[224];
    f32 f368;
} G_46E030;

extern V4_46E030 D_001A4C60;
extern s32 D_001DFBC0;
extern V4_46E030 D_001E2900;
extern void func_004C6EC8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern f32 func_0040BFB0(void *, void *);
extern f32 func_004408C0(f32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3E0(f32);
extern s32 func_0040BAC0(void *);
extern void func_0045E580(void *);

void func_0046E030(P_46E030 *p) {
    S_46E030 *s;
    V4_46E030 d;
    V4_46E030 t;
    V4_46E030 *tp;
    f32 sc;

    func_004C6EC8(&p->pos, &p->pos);
    s = &p->s;
    func_0040BE90(&s->vel, &s->vel, 0.9f);
    s->vel.z -= s->vel.w;
    {
        Q_46E030 x, y, r;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(p->s.vel));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(p->pos) : "j"(r));
    }
    tp = &D_001A4C60;
    if (func_0040BFB0(&p->pos, tp) < 1.05f && ((G_46E030 *)((u8 *)&D_001A4C60 - 128))->f368 != 0.0f) {
        t = *tp;
        {
            Q_46E030 x, y, r;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->pos));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(d) : "j"(r));
        }
        func_0040C0F0(&d, &d, ((G_46E030 *)((u8 *)&D_001A4C60 - 128))->f368 * 0.2f + func_004408C0(0.1f, 2.0f) * 0.016666668f * 0.15f);
        p->b8 += (s32)(s->h22 * ((G_46E030 *)((u8 *)&D_001A4C60 - 128))->f368 * 0.5f);
        {
            Q_46E030 x, y, r;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(p->pos));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(p->pos) : "j"(r));
        }
    }
    if (D_001DFBC0 % 10 == 0) {
        s->f28 = func_0040CEC8(s->f28, 1.0f);
        sc = func_0040C3E0(s->f28);
        func_0040C0F0(&d, &D_001E2900, sc * 0.0075f);
        {
            Q_46E030 x, y, r;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(s->vel));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(s->vel) : "j"(r));
        }
    }
    if (s->h20 >= 160) {
        if (p->h10 < s->h20) {
            p->color = ((s32)((f32)p->h10 / (f32)s->h20 * 128.0f) << 24) | 0x353535;
        } else {
            p->color = 0x9F353535;
        }
    } else {
        if (p->h10 < s->h20) {
            p->color = ((s32)((f32)p->h10 / (f32)s->h20 * 64.0f) << 24) | 0x909090;
        } else {
            p->color = 0x40909090;
        }
    }
    p->b8 = p->b8 + s->h22;
    if (func_0040BAC0(&p->h10) != 0) {
        func_0045E580(p);
    }
}
/* localdecomp:end func_0046E030 */
