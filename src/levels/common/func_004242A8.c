#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern u8 *D_0025BB18[];
extern u8 *func_0044C290(Vec4 *a0, Vec4 *a1, s32 a2, s32 a3, s32 t0);

u8 *func_004242A8(Vec4 *from, Vec4 *to, s32 arg) {
    Vec4 a;
    Vec4 b;
    u8 *hit;
    u8 *m;
    s16 type;

    a = *from;
    b = *to;
    hit = func_0044C290(&a, &b, 18, arg, 0);
    if (hit != 0) {
        m = D_0025BB18[0];
        if (m != 0) {
            type = *(s16 *)(m + 170);
            if (type == 4220 || type == 4222 || type == 4290) {
                hit = 0;
            }
        }
    }
    return hit;
}
