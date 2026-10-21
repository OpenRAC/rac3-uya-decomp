#include "common.h"

/* localdecomp:start func_00458660 */
typedef int Q_458660 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_458660;
typedef struct {
    u8 pad0[0x10];
    V4_458660 v10;
    u8 pad20[0xA0];
    V4_458660 vC0;
    u8 padD0[0x10];
    V4_458660 vE0;
} A_458660;
typedef struct {
    f32 f0;
    f32 f4;
    u8 pad8[0x30];
    u32 w38;
    u8 pad3C[0x24];
    V4_458660 v60;
    u8 pad70[0x14];
    s32 w84;
    u8 pad88[0x64];
    f32 fEC;
} B_458660;
typedef struct {
    u8 pad0[0x18];
    s32 w18;
    s32 w1C;
    V4_458660 v20;
    u8 pad30[8];
    f32 f38;
} D_458660;
extern D_458660 D_001EAA80;
extern V4_458660 D_001EAAB0;
extern void func_0040C0F0(void *, void *, f32);
extern s32 func_003F9498(void *, s32, void *, f32);

s32 func_00458660(A_458660 *a, B_458660 *b) {
    V4_458660 v0;
    V4_458660 v1;
    V4_458660 v2;
    Q_458660 x, y;
    f32 f;
    D_458660 *d;

    if (b->w38 & 0x400) {
        func_0040C0F0(&v1, &a->vE0, b->f4 + b->f0);
    } else {
        __asm__("sq $0, %0" : "=m"(v1));
        v1.z = b->f4 + b->f0;
    }
    f = b->fEC;
    if (f != 0.0f) {
        func_0040C0F0(&v2, &a->vC0, f);
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v1));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v2));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(v1) : "j"(x));
    }
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v1));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a->v10));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(v0) : "j"(x));
    if (func_003F9498(&v0, (b->w38 & 2) ? 6 : 4, a, b->f0)) {
        d = &D_001EAA80;
        b->w84 = d->w18;
        b->v60 = d->v20;
        if (d->w18 != 0 && d->w1C < 0) {
            if (d->f38 > v0.z) {
                d->f38 = v0.z;
            }
        }
        v0 = D_001EAAB0;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v0));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v1));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(a->v10) : "j"(x));
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00458660 */
