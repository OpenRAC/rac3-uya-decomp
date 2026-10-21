#include "common.h"

/* localdecomp:start func_003E2260 */
typedef int Q_3E2260 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3E2260;
typedef struct {
    u8 pad0[0x14];
    s32 i14;
} R_3E2260;
typedef struct {
    V_3E2260 v0[3];
    V_3E2260 v30;
    V_3E2260 pad40[4];
} E_3E2260;
extern E_3E2260 *D_001E01A4;
extern V_3E2260 D_001EAAB0;
extern R_3E2260 *func_003F51A8(void *);
extern f32 func_0040BF38(void *);
extern void func_0040BE90(void *, void *, f32);
s32 func_003E2260(V_3E2260 *a, f32 f) {
    V_3E2260 t, d;
    Q_3E2260 x, y;
    R_3E2260 *r;
    E_3E2260 *e;
    V_3E2260 *p;
    f32 l0, l1, k;
    t = *a;
    r = func_003F51A8(&t);
    if (r != 0) {
    e = D_001E01A4 + r->i14;
    p = &D_001EAAB0;
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(e->v30));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(y));
    l0 = func_0040BF38(e);
    l1 = func_0040BF38(&d);
    k = 1.0f / l1;
    func_0040BE90(p, &d, (l0 + f) * k);
    func_0040BE90((u8 *)p - 0x10, &d, l0 * k);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(e->v30));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(D_001EAAB0));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(D_001EAAB0) : "j"(x));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(e->v30));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V_3E2260 *)((u8 *)p - 0x10)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V_3E2260 *)((u8 *)p - 0x10)) : "j"(x));
    return 1;
    }
    return 0;
}
/* localdecomp:end func_003E2260 */
