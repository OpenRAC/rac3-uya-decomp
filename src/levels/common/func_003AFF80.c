#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef int s64_003AFF80 __attribute__((mode(DI)));

extern u8 *func_00435E70(s32, s32);

u8 *func_003AFF80(u8 *parent, s128 *a, s128 *b, s32 a3, s32 t0, s32 t1, s32 t2, f32 fa, f32 fb) {
    s128 v[2];
    u8 *p;
    u8 *q;

    v[0] = *a;
    v[1] = *b;
    p = func_00435E70(6597, 128);

    if (p != 0) {
        p[48] = 255;
        *(s16 *)(p + 50) = 255;
        p[49] = 1;
        q = *(u8 **)(p + 104);
        p[32] = 0;
        if (parent != 0) {
            *(u8 **)(p + 184) = parent;
            *(s64_003AFF80 *)(p + 56) = *(s64_003AFF80 *)(parent + 56);
        }
        *(s128 *)(p + 16) = *(s128 *)q;
        *(s128 *)q = v[0];
        *(s128 *)(q + 32) = v[1];
        *(f32 *)(q + 84) = fb;
        *(f32 *)(q + 60) = fa;
        *(s32 *)(q + 68) = a3;
        *(s32 *)(q + 72) = t0;
        *(s32 *)(q + 76) = t1;
        *(s32 *)(q + 80) = t2;
        *(s32 *)(q + 56) = 0;
        *(s32 *)(q + 52) = 0;
    }
    return p;
}
