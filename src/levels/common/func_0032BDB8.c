#include "common.h"

/* localdecomp:start func_0032BDB8 */
typedef int Q_0032BDB8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0032BDB8;
typedef struct {
    u8 pad0[0x10];
    Q_0032BDB8 q10;
    u8 b20;
    u8 pad21[3];
    u8 *p24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[4];
    u16 h34;
    u8 pad36[0xAA];
    f32 vE0[4];
} H2_0032BDB8;
typedef struct {
    u8 pad0[0x68];
    H2_0032BDB8 *h2;
} H_0032BDB8;
typedef struct {
    u8 pad0[0x10];
    f32 v10[4];
    u8 b20;
    u8 pad21[0x1F];
    u8 pad40[0x28];
    H_0032BDB8 *h;
    u8 pad6C[0x54];
    f32 vC0[4];
} O_0032BDB8;
typedef struct {
    u8 pad0[0x10];
    f32 f10;
} T_0032BDB8;
extern T_0032BDB8 *func_00440728(H2_0032BDB8 *);
extern void func_004C41E8(f32 *, f32 *);
extern void func_0040BE90(f32 *, f32 *, f32);
extern void func_00437698(O_0032BDB8 *, s32, f32 *);
extern void func_0040C0F0(f32 *, f32 *, f32);
extern void func_0040C920(f32 *, f32 *);
extern void func_0040C2D0(f32 *, f32 *, f32 *);
void func_0032BDB8(O_0032BDB8 *o) {
    H_0032BDB8 *h;
    T_0032BDB8 *t;
    V4_0032BDB8 a, b, c, d, e[3];
    Q_0032BDB8 q1, q2, q3;
    f32 k;
    f32 *p;
    h = o->h;
    t = func_00440728(h->h2);
    func_004C41E8(o->v10, (f32 *)&b);
    *(Q_0032BDB8 *)&a = h->h2->q10;
    if (t != 0) {
        func_0040BE90((f32 *)&d, h->h2->vE0, t->f10);
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(d));
    } else {
        *(Q_0032BDB8 *)&a = *(Q_0032BDB8 *)(h->h2->p24 + 0x30);
        k = h->h2->f2C * 0.0009765625f;
        func_0040BE90((f32 *)&a, (f32 *)&a, k);
        a.w = a.w * k;
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(V4_0032BDB8 *)&h->h2->q10));
    }
    __asm__("vadd.xyz %0, %1, %2" : "=j"(q3) : "j"(q1), "j"(q2));
    __asm__("sqc2 %1, %0" : "=m"(a) : "j"(q3));
    if (h->h2 == 0 || h->h2->b20 == 0xFE || h->h2->b20 == 0xFD || (h->h2->h34 & 0x1000) == 0) {
        o->b20 = 3;
        h->h2 = 0;
    } else {
        p = (f32 *)((u8 *)h + 0x20);
        func_00437698(o, 0, (f32 *)&c);
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(c));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(q3) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(q3));
        func_0040C0F0(p, (f32 *)&d, 1.0f);
        func_0040C920((f32 *)e, o->vC0);
        func_0040C2D0(p, p, (f32 *)e);
    }
}
/* localdecomp:end func_0032BDB8 */
