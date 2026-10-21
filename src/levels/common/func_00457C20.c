#include "common.h"

/* localdecomp:start func_00457C20 */
typedef int Q_457C20 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_457C20;
typedef struct {
    u8 pad0[16];
    V4_457C20 v10;
} A_457C20;
typedef struct {
    u8 pad0[0x28];
    f32 f28;
    u8 pad2C[0x38 - 0x2C];
    long q38;
    u8 pad40[0x60 - 0x40];
    V4_457C20 v60;
    V4_457C20 v70;
    s32 w80;
    s32 w84;
    u8 pad88[0x90 - 0x88];
    f32 f90;
    u8 pad94[0xA0 - 0x94];
    V4_457C20 vA0;
    f32 fB0;
} B_457C20;

extern V4_457C20 D_001E02C0;
extern s32 func_00458660(A_457C20 *, B_457C20 *);
extern s32 func_004587B8(A_457C20 *, B_457C20 *);
extern f32 func_0040BF38(void *);
extern void func_0040C0F0(void *, void *, f32);
extern void func_0040BA90(void *);

void func_00457C20(A_457C20 *a, B_457C20 *b) {
    V4_457C20 tmp;
    Q_457C20 x, y, q;
    s32 n, i, r;
    f32 len;

    if ((b->q38 & 0x404) == 4) {
        b->vA0.z = 0.0f;
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a->v10));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b->vA0));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(a->v10) : "j"(x));
    n = 0;
    i = 0;
    q = *(Q_457C20 *)&a->v10;
    b->w84 = 0;
    __asm__("sq $0,%0" : "=m"(b->v60), "+m"(tmp));
    *(Q_457C20 *)&tmp = q;
    for (; i < 8; i++) {
        r = func_00458660(a, b);
        r |= func_004587B8(a, b);
        n |= r;
        if (r == 0) {
            break;
        }
    }
    if (n != 0) {
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a->v10));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E02C0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(b->vA0) : "j"(x));
        len = func_0040BF38(&b->vA0);
        if (b->fB0 < len) {
            func_0040C0F0(&b->vA0, &b->vA0, b->fB0);
        } else {
            b->fB0 = len;
        }
        if (a->v10.z <= b->f90) {
            if (0.0f < b->f90) {
                if (a->v10.z < b->f90) {
                    a->v10.z = b->f90;
                }
            } else {
                if (a->v10.z < D_001E02C0.z) {
                    a->v10.z = D_001E02C0.z;
                }
            }
            if (b->vA0.z < 0.0f) {
                b->vA0.z = 0.0f;
            }
        }
        if (b->fB0 < b->f28 * 0.5f) {
            b->w80 = b->w80 + 1;
        } else {
            func_0040BA90(&b->w80);
        }
    } else {
        func_0040BA90(&b->w80);
    }
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a->v10));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(tmp));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(b->v70) : "j"(x));
}
/* localdecomp:end func_00457C20 */
