#include "common.h"

/* localdecomp:start func_0033E5C8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_33E5C8;
typedef int Q_33E5C8 __attribute__((mode(TI)));
typedef struct {
    V4_33E5C8 a;
    V4_33E5C8 b;
} P_33E5C8;
typedef struct {
    u8 p0[0xB0];
    V4_33E5C8 vB0;
    u8 pC0[0x2500];
    s32 f25C0;
} G_33E5C8;
typedef struct {
    u8 p0[0x30];
    V4_33E5C8 v30;
} S_33E5C8;
typedef struct {
    u8 p0[0x10];
    V4_33E5C8 pos;
    u8 p20[0x48];
    S_33E5C8 *f68;
} O_33E5C8;
extern G_33E5C8 D_001A4BE0;
extern P_33E5C8 D_001EAAB0;
extern s32 D_001D673C;
extern s32 func_003F9498(void *, s32, s32, f32);
extern void func_0040C0F0(void *, void *, f32);
extern f32 func_0040BEF8(void *, void *);
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C260(void *, void *, void *);
void func_0033E5C8(O_33E5C8 *o) {
    S_33E5C8 *s;
    P_33E5C8 *p;
    V4_33E5C8 *q;
    V4_33E5C8 t0, t1, t2;
    Q_33E5C8 x, y;
    f32 f;
    s = o->f68;
    if (func_003F9498(&o->pos, 0, D_001A4BE0.f25C0, 0.25f) != 0) {
        p = &D_001EAAB0;
        *(Q_33E5C8 *)&o->pos = *(Q_33E5C8 *)&p->a;
        if (D_001D673C != 0) {
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(o->pos));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001A4BE0.vB0));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(x));
            func_0040C0F0(&t0, &t0, 1.0f);
            q = &s->v30;
            f = func_0040BEF8(&t0, q);
            func_0040BE90(&t1, &t0, f);
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t1));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*q));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(t2) : "j"(x));
            func_0040C260(q, &t2, &p->b);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*q));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t1));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(*q) : "j"(x));
        } else {
            f = s->v30.z;
            s->v30.z = 0.0f;
            func_0040C260(&s->v30, &s->v30, &p->b);
            s->v30.z = f;
        }
    }
}
/* localdecomp:end func_0033E5C8 */
