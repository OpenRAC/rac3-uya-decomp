#include "common.h"

/* localdecomp:start func_003F5B38 */
typedef int Q_3F5B38 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3F5B38;
extern void func_0040BE90(void *, void *, f32);
extern s32 func_004369B8(void *, void *, s32, s32);
extern void func_004367E8(void *, s32, void *);
extern void func_0044DC18(void *, void *, void *, s32);
#define F_(p, o) (*(f32 *)((u8 *)(p) + (o)))
void func_003F5B38(u8 *p, f32 x, s32 mode, s32 n, V4_3F5B38 *v1, V4_3F5B38 *v2, s32 b, s32 h) {
    V4_3F5B38 t0;
    Q_3F5B38 a0, c0, d0, a1, c1, d1, a2, c2, d2;
    u8 *q, *w;
    x *= 0.000277777785f;
    *(s32 *)(p + 0x98) = 0;
    *(u16 *)(p + 0x34) |= 0x100;
    q = *(u8 **)(p + 0x68);
    *(V4_3F5B38 *)q = *v1;
    *(V4_3F5B38 *)(q + 0x10) = *v2;
    F_(q, 0x38) = 0.45f;
    F_(q, 0x3C) = 0.0333333351f;
    F_(q, 0x40) = 0.5f;
    F_(q, 0x44) = 0.0130899707f;
    F_(q, 0x48) = x;
    F_(q, 0x4C) = 0.00174532935f;
    *(s16 *)(q + 0x34) = h;
    q[0x5E] = b;
    q[0x5D] = mode;
    q[0x58] = 0;
    q[0x5C] = 0;
    *(s32 *)(q + 0x30) = 0;
    switch (mode) {
    case 2:
        *(s16 *)(q + 0x36) = n;
        *(u16 *)(p + 0x7C) = (1 << n) | 0x8000;
        q[0x58] = func_004369B8(p, q + 0x20, *(s32 *)(q + 0x30), n);
        __asm__("lqc2 %0, %1" : "=j"(a2) : "m"(*(V4_3F5B38 *)(q + 0x20)));
        __asm__("lqc2 %0, %1" : "=j"(c2) : "m"(*(V4_3F5B38 *)(p + 0x10)));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(d2) : "j"(a2), "j"(c2));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3F5B38 *)(q + 0x20)) : "j"(d2));
        func_0044DC18(p, q + 0x20, q + 0x20, 0);
        break;
    case 0:
    case 3:
        func_0040BE90(q + 0x20, p, 0.0009765625f);
        F_(q, 0x2C) = F_(p, 0xC) * 0.0009765625f;
        __asm__("lqc2 %0, %1" : "=j"(a0) : "m"(*(V4_3F5B38 *)(q + 0x20)));
        __asm__("lqc2 %0, %1" : "=j"(c0) : "m"(*(V4_3F5B38 *)(p + 0x10)));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(d0) : "j"(a0), "j"(c0));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3F5B38 *)(q + 0x20)) : "j"(d0));
        func_0044DC18(p, q + 0x20, q + 0x20, 0);
        break;
    case 1:
        *(s16 *)(q + 0x36) = n;
        *(u16 *)(p + 0x7C) = (1 << n) | 0x8000;
        func_004367E8(p, n, &t0);
        w = q + 0x20;
        __asm__("lqc2 %0, %1" : "=j"(a1) : "m"(t0));
        __asm__("lqc2 %0, %1" : "=j"(c1) : "m"(*(V4_3F5B38 *)(p + 0x10)));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(d1) : "j"(a1), "j"(c1));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3F5B38 *)(q + 0x20)) : "j"(d1));
        func_0044DC18(p, w, w, 0);
        break;
    }
}
/* localdecomp:end func_003F5B38 */
