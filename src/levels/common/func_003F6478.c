#include "common.h"

/* localdecomp:start func_003F6478 */
typedef int Q_3F6478 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3F6478;
extern void func_0040BE68(void *, void *, void *, f32);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0044DF40(void *, void *, s32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BF20(void *, void *, void *);
extern void func_003F6CD0(void *, void *, void *);
extern void func_003F6DA0(void *, void *, void *);
extern void func_0040CB80(void *, void *);
extern void func_0040C960(void *, void *, void *);
void func_003F6478(u8 *p) {
    V4_3F6478 t0, t1, t2, t3, t4, t5, t6, t7, t8[3];
    Q_3F6478 a, b, c, d, e, g, h, k, l;
    u8 *q = *(u8 **)(p + 0x68);
        V4_3F6478 *m;
    u8 *m1, *w, *w1, *qv;
    if (q[0x5C] >= 2) {
        w1 = p + 0xC0;
        m1 = *(u8 **)(q + 0x30);
        func_0040BE68(&t0, m1 + (q[0x59] << 4), m1 + (q[0x5A] << 4), 0.5f);
        m = *(V4_3F6478 **)(q + 0x30);
        __asm__("lqc2 %0, %1" : "=j"(a) : "m"(m[q[0x59]]));
        __asm__("lqc2 %0, %1" : "=j"(b) : "m"(m[q[0x5A]]));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
        __asm__("sqc2 %1, %0" : "=m"(t4) : "j"(c));
        func_0040C2D0(&t4, &t4, w1);
        w = w1;
    } else {
        w = p + 0xC0;
        t0 = (*(V4_3F6478 **)(q + 0x30))[q[0x59]];
    }
    qv = q + 0x10;
    func_0040C2D0(&t1, &t0, w);
    func_0044DF40(p + 0x10, &t5, 1);
    __asm__("lqc2 %0, %1" : "=j"(d) : "m"(t0));
    __asm__("lqc2 %0, %1" : "=j"(e) : "m"(*(V4_3F6478 *)(q + 0x20)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(g) : "j"(d), "j"(e));
    __asm__("sqc2 %1, %0" : "=m"(t6) : "j"(g));
    func_0040C2D0(&t6, &t6, w);
    func_0040C0F0(&t6, &t6, 1.0f);
    func_0040BF20(&t7, &t6, &t5);
    func_0040C0F0(&t7, &t7, *(f32 *)(q + 0x4C));
    func_003F6CD0(p, qv, &t7);
    if (q[0x5C] >= 2) {
        func_003F6DA0(p, qv, &t4);
    }
    func_0040CB80(qv, &t8[0]);
    func_0040C960(w, &t8[0], w);
    func_0040C2D0(&t2, &t0, w);
    __asm__("lqc2 %0, %1" : "=j"(l) : "m"(t1));
    __asm__("lqc2 %0, %1" : "=j"(h) : "m"(t2));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(k) : "j"(h), "j"(l));
    __asm__("sqc2 %1, %0" : "=m"(t3) : "j"(k));
    {
        Q_3F6478 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3F6478 *)(p + 0x10)));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t3));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3F6478 *)(p + 0x10)) : "j"(z));
    }
}
/* localdecomp:end func_003F6478 */
