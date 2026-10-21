#include "common.h"

/* localdecomp:start func_003E23A8 */
typedef int Q_3E23A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3E23A8;
typedef struct {
    u8 pad0[0x50];
    s32 w50;
    u8 pad54[0x3C];
    V4_3E23A8 v90;
    u8 pad_a0[0xB0];
    struct {
        u8 pad0[0xF0];
        s32 wF0;
        u8 padF4[0x20];
        f32 f114;
        u8 pad118[8];
        s16 h120;
    } sub;
} O_3E23A8;
extern V4_3E23A8 D_001EAAA0;
extern void func_003E2238();
extern void func_0040BE90(void *, void *, f32);
extern s32 func_003F8448(void *, void *, s32, s32, s32);

s32 func_003E23A8(O_3E23A8 *o, V4_3E23A8 *out, s32 flag) {
    V4_3E23A8 a;
    V4_3E23A8 b;
    V4_3E23A8 c;
    V4_3E23A8 d;
    f32 f;
    typeof(o->sub) *p = &o->sub;

    if (p->h120 == 0) {
        func_003E2238(o->w50);
        return 1;
    }
    func_003E2238(o->w50, &a);
    f = p->f114;
    if (f >= 30.0f || flag == 0) {
        func_0040BE90(&d, &o->v90, 0.2f);
        {
        Q_3E23A8 s1_1;
        Q_3E23A8 s2_1;
        __asm__("lqc2 %0, %1" : "=j"(s1_1) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(s2_1) : "m"(d));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(s1_1) : "j"(s1_1), "j"(s2_1));
        __asm__("sqc2 %1, %0" : "=m"(b) : "j"(s1_1));
        }

        func_0040BE90(&d, &o->v90, -30.0f);
        {
        Q_3E23A8 s1_2;
        Q_3E23A8 s2_2;
        __asm__("lqc2 %0, %1" : "=j"(s1_2) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(s2_2) : "m"(d));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(s1_2) : "j"(s1_2), "j"(s2_2));
        __asm__("sqc2 %1, %0" : "=m"(c) : "j"(s1_2));
        }

        if (func_003F8448(&b, &c, 0x12, p->wF0, 0)) {
            *out = D_001EAAA0;
            return 0;
        }
        *out = a;
        return -1;
    }
    func_0040BE90(&b, &o->v90, -f);
    __asm__ __volatile__(
        "lqc2 $vf1, %1\n"
        "lqc2 $vf2, %2\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        : "=m"(*out) : "m"(a), "m"(b) : "memory");

    return 1;
}
/* localdecomp:end func_003E23A8 */
