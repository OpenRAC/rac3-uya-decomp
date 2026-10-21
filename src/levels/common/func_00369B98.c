#include "common.h"

/* localdecomp:start func_00369B98 */
typedef int Q_369B98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_369B98;
typedef struct {
    V4_369B98 v0;
    u8 pad10[0x20 - 0x10];
    u8 f20;
    u8 pad21[0x30 - 0x21];
} T_369B98;
typedef struct {
    V4_369B98 v0;
    V4_369B98 v10;
    u8 f20;
    u8 pad21[0x30 - 0x21];
    u8 f30;
    u8 f31;
    s16 f32;
    u16 f34;
    u8 pad36[0x68 - 0x36];
    u8 *f68;
} O_369B98;
typedef struct {
    V4_369B98 v0;
    V4_369B98 v10;
    u8 pad20[0x14];
    s32 f34;
    s32 f38;
    f32 f3C;
    u8 pad40[0x10];
    V4_369B98 v50;
    f32 f60;
} S_369B98;
extern O_369B98 *func_00435E70(s32, s32);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0036A560(void *);
O_369B98 *func_00369B98(V4_369B98 *p0, void *a1, V4_369B98 *p2, s32 a3, f32 f) {
    O_369B98 *o;
    S_369B98 *s;
    V4_369B98 v;
    Q_369B98 x, y, z;
    void *q;
    o = func_00435E70(0x1862, 0x80);
    if (o != 0) {
        s = (S_369B98 *)o->f68;
        o->f30 = 0xFF;
        o->f20 = 0;
        o->f32 = 0xFF;
        o->f31 = 1;
        o->f34 |= 0x41;
        q = (u8 *)o + 0x10;
        func_0040C0F0((u8 *)s + 0x20, a1, 0.13333334f);
        s->v0 = *p0;
        o->v10 = *p2;
        func_0040C0F0(&v, (u8 *)s + 0x20, -1.5f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*p0));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(z) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(s->v50) : "j"(z));
        s->f60 = f;
        s->f34 = a3;
        s->f3C = 0.06666667f;
        s->f38 = 15;
        func_0036A560(q);
    }
    return o;
}
/* localdecomp:end func_00369B98 */
