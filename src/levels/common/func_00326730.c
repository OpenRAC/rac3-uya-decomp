#include "common.h"

typedef int u128_00326730 __attribute__((mode(TI)));
typedef union { u128_00326730 q; f32 f[4]; s32 w[4]; } V_00326730;

extern u128_00326730 D_001E1320[];
extern void func_003E4858(V_00326730 *, V_00326730 *, f32);
extern void func_003E4648(void *, V_00326730 *, V_00326730 *);

void func_00326730(V_00326730 *v, void *a1) {
    V_00326730 t;
    v->q = D_001E1320[0];
    t.q = 0;
    v->w[2] = 0;
    t.f[2] = 1.0f;
    t.f[3] = 1.0f;
    v->f[3] = 1.0f;
    func_003E4858(v, v, 1.0f);
    func_003E4648(a1, v, &t);
}
