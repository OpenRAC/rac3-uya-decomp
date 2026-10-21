#include "common.h"

/* localdecomp:start func_003C1BA8 */
typedef int Q_3C1BA8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C1BA8;
typedef struct {
    u8 pad0[0x3C];
    f32 f3C;
    u8 pad40[0x160 - 0x40];
    V4_3C1BA8 v160;
    u8 pad170[0x1CC - 0x170];
    f32 f1CC;
} Q2_3C1BA8;
typedef struct {
    u8 pad0[0x10];
    V4_3C1BA8 pos;
    u8 pad20[0x68 - 0x20];
    Q2_3C1BA8 *q;
    u8 pad6c[0xF8 - 0x6C];
    f32 fF8;
} O_3C1BA8;
extern V4_3C1BA8 D_001EAAC0;
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern f32 func_00443140(void *, s32, s32, f32);
extern f32 func_0040BF68(void *);
extern f32 func_0040C490(f32, f32);

s32 func_003C1BA8(O_3C1BA8 *o) {
    V4_3C1BA8 t0, t1, t2;
    Q_3C1BA8 a, b, c;
    Q2_3C1BA8 *q = o->q;
    f32 f21, f20, f1;
    t0 = o->pos;
    t1.x = func_0040C3C8(o->fF8);
    t1.y = func_0040C3E0(o->fF8);
    t1.z = 0;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(t0));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(t1));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(c) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(c));
    f21 = func_00443140(&t0, 0x22, 0, 0.5f);
    if (f21 < o->pos.z) {
        if (q->f3C < __builtin_fabsf(f21 - o->pos.z)) {
            Q_3C1BA8 d, e, g;
            t1.x = func_0040C3C8(o->fF8) * 9.0f;
            t1.y = func_0040C3E0(o->fF8) * 9.0f;
            t1.z = 0;
            __asm__("lqc2 %0, %1" : "=j"(d) : "m"(o->pos));
            __asm__("lqc2 %0, %1" : "=j"(e) : "m"(t1));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(g) : "j"(d), "j"(e));
            __asm__("sqc2 %1, %0" : "=m"(t0) : "j"(g));
            q->v160 = t0;
            f21 = func_00443140(&t0, 0x22, 0, 6.0f);
            t2 = D_001EAAC0;
            f20 = o->pos.z - 2.0f;
            f1 = func_0040BF68(&t2);
            f1 = func_0040C490(t2.z, f1);
            if (f20 < f21 && f1 < 0.17453292f) {
                q->f1CC = f21;
                return 1;
            }
            return 2;
        }
    }
    return 0;
}
/* localdecomp:end func_003C1BA8 */
