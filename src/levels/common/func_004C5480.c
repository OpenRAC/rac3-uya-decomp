#include "common.h"

/* localdecomp:start func_004C5480 */
typedef int Q_4C5480 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4C5480;
typedef struct {
    u8 pad0[52];
    s32 i52;
    u8 pad56[84 - 56];
    s32 i84;
    u8 pad88[104 - 88];
    f32 f104;
} P_4C5480;
typedef struct {
    u8 pad0[16];
    V4_4C5480 pos;
    u8 b32;
    u8 pad33[104 - 33];
    P_4C5480 *p104;
} O_4C5480;
typedef struct {
    u8 pad0[2];
    u8 b2;
} R_4C5480;
typedef struct {
    u8 pad0[356];
    u8 *p356;
} S_4C5480;
extern O_4C5480 *D_001E1160[2];
extern S_4C5480 D_00221118;
extern u8 D_001D66B0[8];
extern f32 func_0040C018(V4_4C5480 *, V4_4C5480 *);
extern void func_0040C0F0(V4_4C5480 *, V4_4C5480 *, f32);
extern void func_0040BE90(V4_4C5480 *, V4_4C5480 *, f32);
extern R_4C5480 *func_0046DCB8(V4_4C5480 *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_004C5480(void) {
    s32 i, j, k;
    f32 d, s;
    V4_4C5480 v;
    Q_4C5480 x, y;
    R_4C5480 *r;
    P_4C5480 *a, *b;

    for (i = 0; i < 6; i++) {
        if (D_001E1160[i] == 0) {
            continue;
        }
        for (j = 0; j < 6; j++) {
            if (i == j || D_001E1160[j] == 0) {
                continue;
            }
            d = func_0040C018(&D_001E1160[i]->pos, &D_001E1160[j]->pos);
            if (d > 0.01f && d < 50.0f) {
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E1160[i]->pos));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001E1160[j]->pos));
                __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(v) : "j"(x));
                func_0040C0F0(&v, &v, 0.2f);
                s = 1.0f / d;
                if (s > 0.75f) {
                    s = 0.75f;
                }
                func_0040BE90(&v, &v, s);
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(v));
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001E1160[j]->pos));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(D_001E1160[j]->pos) : "j"(x));
            }
            if (d < 0.01f) {
                b = D_001E1160[i]->p104;
                a = D_001E1160[j]->p104;
                if (a->i84 == 0) {
                    for (k = 0; k < 3; k++) {
                        r = func_0046DCB8(&D_001E1160[i]->pos, D_001D66B0, 20, 0xFF1020, 5, 0, 127, 6,
                                          1050000.0f, 42000.0f, 0.0f);
                        if (r != 0) {
                            r->b2 = *D_00221118.p356;
                        }
                    }
                    for (k = 0; k < 2; k++) {
                        r = func_0046DCB8(&D_001E1160[i]->pos, D_001D66B0, 20, 0x7F7F7F, 5, 0, 127, 6,
                                          840000.0f, 42000.0f, 0.0f);
                        if (r != 0) {
                            r->b2 = *D_00221118.p356;
                        }
                    }
                    b->f104 = b->f104 + a->f104 * 0.5f;
                    b->i52 = 0;
                    if (b->f104 > 1.5f) {
                        b->f104 = 1.5f;
                    }
                    D_001E1160[j]->b32 = 4;
                    D_001E1160[j] = 0;
                }
            }
        }
    }
}
/* localdecomp:end func_004C5480 */
