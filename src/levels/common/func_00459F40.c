#include "common.h"

typedef int Q_459F40 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_459F40;
typedef struct {
    u8 pad0[0x10];
    V_459F40 v10;
    u8 pad20[0xA0];
    V_459F40 vC0;
    u8 padD0[0x10];
    V_459F40 vE0;
} O_459F40;
typedef struct {
    u8 pad0[0x38];
    s32 f38;
    u8 pad3C[0x58];
    s32 f94;
    s32 f98;
    s32 f9C;
    Q_459F40 qA0;
    u8 padB0[4];
    s32 fB4;
    u8 padB8[4];
    s32 fBC;
    u8 padC0[0x2A];
    u8 bEA;
} S_459F40;

extern s32 D_001DFBC0;
extern V_459F40 D_001EAAC0;
extern S_459F40 *func_00458650(O_459F40 *, s32, s32);
extern void func_0040C8E0(void *, void *);
extern void func_0045A1B0(O_459F40 *, void *, s32);
extern void func_0045AEB0(void *, void *, void *);
extern void func_0040C2D0(void *, void *, void *);
extern void func_00458600(O_459F40 *, S_459F40 *);
extern void func_004585D0(O_459F40 *, S_459F40 *);
extern void func_0045A2B8(O_459F40 *, S_459F40 *);
extern void func_0045A480(O_459F40 *, S_459F40 *, s32, s32, void *, void *, void *);
extern void func_0045A758(O_459F40 *, S_459F40 *, void *, void *);
extern void func_0045A8E8(O_459F40 *, S_459F40 *, s32, void *);
extern void func_0040C0F0(void *, void *, f32);
extern f32 func_0040BEF8(void *, void *);
extern s32 func_003F8448(void *, void *, s32, void *, s32);

/* localdecomp:start func_00459F40 */
s32 func_00459F40(O_459F40 *o, s32 a1, s32 a2) {
    S_459F40 *s;
    V_459F40 m[4];
    V_459F40 t40;
    V_459F40 t50[3];
    V_459F40 *mp;
    V_459F40 *g;
    V_459F40 t80;
    V_459F40 t90;
    V_459F40 a;
    V_459F40 b;
    Q_459F40 x, y, z;
    s32 t;

    s = func_00458650(o, a1, a2);
    if (s == 0) {
        return 8;
    }
    if (D_001DFBC0 != s->fBC) {
        func_0040C8E0(m, &o->vC0);
        mp = m;
        func_0045A1B0(o, &t40, 0);
        func_0045AEB0(&o->vC0, &t40, t50);
        func_0040C2D0(&s->qA0, &s->qA0, t50);
        t = s->f94;
        s->f94 = 0;
        s->f98 = t;
        func_00458600(o, s);
        func_004585D0(o, s);
        if (D_001DFBC0 - s->fBC >= 2 || s->fBC == 0) {
            func_0045A2B8(o, s);
            s->fB4 = 0;
            s->f9C |= -3;
            s->bEA = 255;
            __asm__ __volatile__("sq $0,%0" : "=m"(s->qA0));
        }
        s->fBC = D_001DFBC0;
        func_0045A480(o, s, a1, a2, &t80, &t90, mp);
        func_0045A758(o, s, &t90, mp);
        func_0045A8E8(o, s, a1, mp);
        if (!(s->f38 & 0x400)) {
            func_0040C0F0(&a, &o->vE0, 0.1f);
            func_0040C0F0(&b, &o->vE0, -3.0f);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->v10));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(a) : "j"(x));
            __asm__("lqc2 %0, %1" : "=j"(z) : "m"(b));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(z), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(b) : "j"(z));
            g = &D_001EAAC0;
            if (func_0040BEF8(g, &o->vE0) > 0.7f) {
                if (func_003F8448(&a, &b, 2, o, 0) != 0) {
                    o->v10 = g[-2];
                }
            }
        }
    }
    return s->f94;
}
/* localdecomp:end func_00459F40 */
