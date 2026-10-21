#include "common.h"

/* localdecomp:start func_003E5728 */
typedef int Q_003E5728 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E5728;
typedef struct {
    u8 pad0[0x2C];
    f32 f2C;
} A_003E5728;
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[2];
    s16 h38;
} B_003E5728;
typedef struct {
    u8 pad0[0xE0];
    u8 *p0E0;
} C_003E5728;
typedef struct {
    u8 pad0[0x100];
    f32 f100;
} T_003E5728;
typedef struct {
    u8 pad0[0x104];
    s32 f104;
} G_003E5728;
typedef struct {
    u8 pad0[0x70];
    u8 *p70;
    u8 pad74[0x20];
    s32 f94;
} O_003E5728;
extern u8 D_001E2C10[];
extern f32 func_0040BF38(void *);
extern void func_0040C0F0(f32, void *, void *);
extern void func_0040BE90(f32, void *, void *);
s32 func_003E5728(O_003E5728 *o, V4_003E5728 *in, s32 a2, s32 a3) {
    u8 *s = o->p70;
    u8 *g = D_001E2C10 + o->f94 * 0x460;
    A_003E5728 *a = (A_003E5728 *)(s + 0x180);
    B_003E5728 *b = (B_003E5728 *)(s + 0x210);
    C_003E5728 *c = (C_003E5728 *)(s + 0x60);
    f32 f20;
    f32 f2;
    Q_003E5728 x, y, r;
    f20 = func_0040BF38(a);
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*in));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_003E5728 *)(s + 0xB0)));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_003E5728 *)(s + 0x180)) : "j"(r));
    if (b->h38 != 0) {
        func_0040C0F0(a->f2C - b->f30, a, a);
        return a3;
    }
    f2 = func_0040BF38(a);
    if (g[0x12B] != 2) {
        f32 t = ((T_003E5728 *)*(u8 **)(g + 0x134))->f100;
        if (0.05f < __builtin_fabsf(t) && a3 != 0) {
            b->h34 = 0x884;
            f2 -= 0.075f;
        }
    }
    if (a2 == 0 && ((G_003E5728 *)g)->f104 != 2 && f20 < f2) {
        func_0040BE90(f20 / f2, a, a);
        b->f30 = a->f2C - f20;
        return a3;
    }
    if (f2 < 0.2f) {
        if (f2 <= 0.0001f) {
            func_0040C0F0(-0.2f, a, c->p0E0 + 0xC0);
        } else {
            func_0040BE90(0.2f / f2, a, a);
        }
        f2 = 0.2f;
    }
    b->f30 = a->f2C - f2;
    return 1;
}
/* localdecomp:end func_003E5728 */
