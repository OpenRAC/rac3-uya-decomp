#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_403E80;

typedef struct {
    u8 pad0[0x10];
    u128_t pos;
} S_403E80M;

typedef struct {
    u8 pad0[0x1A0];
    S_403E80M *mobys[1];
} S_403E80T;

extern S_403E80T D_001E6080;
extern void func_0042B9A0(V4_403E80 *, f32);
extern f32 func_00422DB0(f32, f32);
extern s32 func_00422D38(s32);
extern void func_0044B380(V4_403E80 *, V4_403E80 *, s32, s32, u8, s32, s32, s32, f32);
extern void func_004038A8(S_403E80M *, s32, s32, s32, f32, f32, f32);

void func_00403E80(s32 idx, u128_t *pos, s32 n1, s32 n2, s32 a4, s32 a5, s32 a6, s32 a7, f32 s1, f32 s2, s32 a8) {
    V4_403E80 tmp;
    V4_403E80 p;
    V4_403E80 v;
    u128_t base;
    S_403E80M *m;
    s32 i;
    f32 sc;

    *(u128_t *)&tmp = *pos;
    base = *(u128_t *)&tmp;
    m = D_001E6080.mobys[idx];
    __asm__(
        "lqc2 $vf2, %1\n"
        "lqc2 $vf1, %0\n"
        "vadd.xyz $vf2, $vf2, $vf1\n"
        "sqc2 $vf2, %0\n"
        : "=m"(base) : "m"(m->pos), "m"(base));
    for (i = 0; i < n1; i++) {
        *(u128_t *)&p = base;
        func_0042B9A0(&p, 1.0f);
        __asm__("sq $0, %0" : "=m"(v));
        v.z = func_00422DB0(0.0f, 0.025000002f);
        sc = s1 * func_00422DB0(0.2f, 0.5f);
        func_0044B380(&p, &v, a6, a4, func_00422D38(0xFF), 0, 0x40, 0, sc);
    }
    for (i = 0; i < n2; i++) {
        *(u128_t *)&p = base;
        func_0042B9A0(&p, 0.3f);
        __asm__("sq $0, %0" : "=m"(v));
        v.z = func_00422DB0(0.0f, 0.008333334f);
        sc = s2 * func_00422DB0(1.5f, 2.5f);
        func_0044B380(&p, &v, a7, a5, func_00422D38(0xFF), 0, 0x40, 0, sc);
    }
    func_004038A8(m, a8, a8, 10, 3.0f, 7.0f, 3.0f);
}
