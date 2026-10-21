#include "common.h"

/* localdecomp:start func_004493C0 */
typedef int Q_4493C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4493C0;
typedef struct { V4_4493C0 v[4]; } M_4493C0;
typedef struct {
    u8 pad0[16];
    V4_4493C0 v10;
    V4_4493C0 v20;
    u8 pad30[12];
    u32 flags;
} R_4493C0;
typedef struct {
    u8 pad0[16];
    V4_4493C0 v10;
} A_4493C0;
extern R_4493C0 *func_00449388(A_4493C0 *);
extern void func_0040C658(void *, void *);
extern void func_0040C8E0(void *, void *);
extern void func_0040C2D0(void *, void *, void *);
extern void func_0040C9B0(void *, void *, void *);
extern void func_00447748(void *, void *);

s32 func_004493C0(s32 a0, A_4493C0 *a1, V4_4493C0 *a2, V4_4493C0 *a3, V4_4493C0 *t0, V4_4493C0 *t1) {
    M_4493C0 l0, l40, l80;
    M_4493C0 *p, *q;
    R_4493C0 *r = func_00449388(a1);
    Q_4493C0 x1, x2, s;
    if (r == 0) {
        *(Q_4493C0 *)t0 = *(Q_4493C0 *)a2;
        *(Q_4493C0 *)t1 = *(Q_4493C0 *)a3;
        return 0;
    }
    func_0040C658(&l0, r);
    __asm__ __volatile__(
        "lqc2 $vf2, %1\n"
        "lqc2 $vf1, %2\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        "lqc2 $vf2, %0\n"
        "lqc2 $vf1, %3\n"
        "vsub.xyz $vf2, $vf2, $vf1\n"
        "sqc2 $vf2, %0\n"
        : : "m"(*t0), "m"(r->v10), "m"(*a2), "m"(a1->v10) : "memory");
    p = &l80;
    if (r->flags & 2) {
        func_0040C658(p, &r->v20);
        q = &l40;
        func_0040C8E0(q, p);
        func_0040C2D0(t0, t0, q);
        func_0040C2D0(t0, t0, (u8 *)a1 + 0xC0);
        p = q;
    } else {
        func_0040C2D0(t0, t0, &l0);
        p = &l40;
    }
    __asm__("lqc2 %0, %1" : "=j"(x2) : "m"(a1->v10));
    __asm__("lqc2 %0, %1" : "=j"(x1) : "m"(*t0));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(s) : "j"(x1), "j"(x2));
    __asm__("sqc2 %1, %0" : "=m"(*t0) : "j"(s));
    func_0040C658(p, a3);
    func_0040C9B0(p, &l0, p);
    func_00447748(p, t1);
    return 1;
}
/* localdecomp:end func_004493C0 */
