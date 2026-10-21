#include "common.h"

/* localdecomp:start func_0050C4A0 */
typedef int Q_50C4A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_50C4A0;
typedef struct {
    u8 pad0[128];
    V4_50C4A0 v128;
    u8 pad144[96];
    V4_50C4A0 v240;
    u8 pad256[448];
    V4_50C4A0 v704;
    u8 pad720[8996];
    u8 b9716;
} S_50C4A0;
extern S_50C4A0 D_001A4BE0;
extern V4_50C4A0 D_001EAAA0;
extern V4_50C4A0 D_001EAAC0;
extern void func_0040BE90(void *, void *, f32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_00447650(void *, void *);
extern s32 func_003F8448(void *, void *, s32, void *, s32);
extern f32 func_0050D870(void *);
extern f32 func_0050D4D8(void *);
extern s32 func_00443080(f32, f32, f32, f32 *, f32 *);
f32 func_0050C4A0(f32 a, f32 b, f32 c) {
    S_50C4A0 *d = &D_001A4BE0;
    V4_50C4A0 t0, t16, t32, t48;
    Q_50C4A0 x, y, x2, y2;
    f32 o0a, o0b, o1a, o1b, o2a, o2b;

    switch (d->b9716) {
    case 0:
        if (c < 0.0f) {
            func_0040BE90(&t0, &d->v240, a);
            t0.z -= (a * a + a) * 0.5f * b;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d->v128));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t0));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(x));
            t16 = d->v128;
            func_00447650(&t16, &t0);
            t16 = d->v128;
            if (func_003F8448(&t16, &t0, 34, 0, 0)) {
                f32 *q = (f32 *)&D_001EAAC0;
                if (func_0050D870(q) <= 0.87266463f) {
                    c = q[-6];
                }
            }
        }
        if (0.0f < c) {
            f32 h = b * -0.5f;
            if (func_00443080(h, D_001A4BE0.v240.z - h, D_001A4BE0.v128.z - c, &o0a, &o0b) > 0 && 0.0f < o0a) {
                return o0a;
            }
        }
        break;
    case 1:
        t16 = d->v704;
        func_0040C0F0(&t16, &t16, b);
        func_0040BE90(&t16, &t16, -1.0f);
        func_0040BE90(&t0, &d->v240, a);
        func_0040BE90(&t32, &t16, (a * a + a) * 0.5f * b);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t0));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t32));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(y2) : "m"(d->v128));
        __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(t0));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y2) : "j"(y2), "j"(x2));
        __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(y2));
        t48 = d->v128;
        func_00447650(&t48, &t0);
        if (func_003F8448(&d->v128, &t0, 34, 0, 0)) {
            f32 h = b * -0.5f;
            f32 k = func_0050D4D8(&d->v240) - h;
            if (func_00443080(h, k, func_0050D4D8(&d->v128) - func_0050D4D8(&D_001EAAA0), &o1a, &o1b) > 0 && 0.0f < o1a) {
                return o1a;
            }
        }
        break;
    case 2:
        t32.x = t32.y = t32.z = 100.0f;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d->v128));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t32));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(t16) : "j"(y));
        func_0040C0F0(&t16, &t16, b);
        func_0040BE90(&t16, &t16, -1.0f);
        func_0040BE90(&t0, &d->v240, a);
        func_0040BE90(&t32, &t16, (a * a + a) * 0.5f * b);
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t0));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(t32));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(y2) : "m"(d->v128));
        __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(t0));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y2) : "j"(y2), "j"(x2));
        __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(y2));
        t48 = d->v128;
        func_00447650(&t48, &t0);
        if (func_003F8448(&d->v128, &t0, 34, 0, 0)) {
            f32 h = b * -0.5f;
            f32 k = func_0050D4D8(&d->v240) - h;
            if (func_00443080(h, k, func_0050D4D8(&d->v128) - func_0050D4D8(&D_001EAAA0), &o2a, &o2b) > 0 && 0.0f < o2a) {
                return o2a;
            }
        }
        break;
    }
    return a;
}
/* localdecomp:end func_0050C4A0 */
