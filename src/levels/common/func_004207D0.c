#include "common.h"

typedef int u128_4207D0 __attribute__((mode(TI)));
typedef union { u128_4207D0 q; f32 f[4]; } V_4207D0;
extern V_4207D0 D_001DFE50[4];
extern s32 D_001DFE90;

void func_004207D0(u128_4207D0 *src, s32 v) {
    V_4207D0 *d;
    s32 i;
    D_001DFE90 = v;
    d = D_001DFE50;
    for (i = 3; i >= 0; i--) {
        d->q = *src++;
        d->f[3] = 1.0f;
        d++;
    }
}
