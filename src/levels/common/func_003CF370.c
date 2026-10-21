#include "common.h"

typedef int Q_003CF370 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003CF370;

extern void func_004180E0(V4_003CF370 *p, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14, s32 t0, s32 t1, s32 t2);
extern void func_004196A0(V4_003CF370 *p, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14);
extern void func_0041C768(V4_003CF370 *out, V4_003CF370 *in, f32 f);
extern f32 func_0044FD98(void);
extern void func_00458238(V4_003CF370 *p, f32 f);

void func_003CF370(V4_003CF370 *a, V4_003CF370 *b) {
    V4_003CF370 cur;
    V4_003CF370 d;
    V4_003CF370 pts[10];
    s32 i;
    Q_003CF370 x, y;
    f32 w;
    f32 k;
    f32 lo;
    f32 hi;

    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*b));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "0"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(x));
    w = 0.075f;
    func_0041C768(&d, &d, 0.11111111f);
    cur = *a;
    for (i = 0; i < 10; i++) {
        *(Q_003CF370 *)&pts[i] = *(Q_003CF370 *)&cur;
        if (i != 0 && i != 9) {
            func_00458238(&pts[i], 0.3f);
        }
        pts[i].w = w;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(cur));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(d));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "0"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(cur) : "j"(x));
    }
    k = 0.3f;
    func_004180E0(pts, 0x17, 0x17, 0xB, 0.075f, 4.0f, 0.0f, -1, 0x80802020, 0);
    lo = 0.5f;
    hi = 1.2f;
    func_004196A0(a, 0x31, -1, 1, lo, k, func_0044FD98());
    func_004196A0(a, 0x31, 0x80802020, 1, hi, k, func_0044FD98());
    func_004196A0(b, 0x31, -1, 1, lo, k, func_0044FD98());
    func_004196A0(b, 0x31, 0x80802020, 1, hi, k, func_0044FD98());
}
