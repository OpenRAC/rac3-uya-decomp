#include "common.h"

/* localdecomp:start func_004495F8 */
typedef int Q_4495F8 __attribute__((mode(TI)));
typedef struct {
    f32 m0[16];
    f32 v40[4];
    f32 m50[16];
    f32 m90[16];
    f32 vD0[4];
} __attribute__((aligned(16))) L_4495F8;
typedef struct {
    u8 pad0[0x10];
    f32 v10[4];
    u8 pad20[0x1C];
    s32 flags3C;
} O_4495F8;
typedef struct {
    u8 pad0[0x10];
    f32 v10[4];
    u8 pad20[0xA0];
    f32 mC0[16];
} P_4495F8;
extern O_4495F8 *func_00449388(P_4495F8 *);
extern void func_0040C658(void *, void *);
extern void func_0040C8E0(void *, void *);
extern void func_0040C2D0(void *, void *, void *);

s32 func_004495F8(s32 a0, P_4495F8 *a1, f32 *a2, f32 *a3) {
    L_4495F8 L;
    O_4495F8 *v;
    s32 r;
    v = func_00449388(a1);
    if (v == 0) {
        __asm__ __volatile__("sq $0, 0(%0)" : : "r"(a3) : "memory");
        return 0;
    }
    func_0040C658(L.m0, v);
    __asm__ __volatile__(
        "lqc2 $vf1, 0x10(%2)\n"
        "lqc2 $vf2, 0(%3)\n"
        "vadd.xyz $vf2, $vf2, $vf1\n"
        "lqc2 $vf1, 0x10(%4)\n"
        "sqc2 $vf1, %0\n"
        "sqc2 $vf2, %1\n"
        "lqc2 $vf1, %1\n"
        "lqc2 $vf2, %0\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %1\n"
        : "=m"(L.vD0), "+m"(L.v40) : "r"(v), "r"(a2), "r"(a1));
    if (v->flags3C & 2) {
        func_0040C658(L.m90, (u8 *)v + 0x20);
        func_0040C8E0(L.m50, L.m90);
        func_0040C2D0(L.v40, L.v40, L.m50);
        func_0040C2D0(L.v40, L.v40, a1->mC0);
    } else {
        func_0040C2D0(L.v40, L.v40, L.m0);
    }
    __asm__ __volatile__(
        "lqc2 $vf2, 0x10(%1)\n"
        "lqc2 $vf1, %0\n"
        "vadd.xyz $vf1, $vf1, $vf2\n"
        : "+m"(L.v40) : "r"(a1));
    r = 1;
    __asm__ __volatile__(
        "lqc2 $vf2, 0(%2)\n"
        "sqc2 $vf1, %0\n"
        "lqc2 $vf1, %0\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, 0(%1)\n"
        : "+m"(L.v40) : "r"(a3), "r"(a2), "r"(r) : "memory");
    return r;
}
/* localdecomp:end func_004495F8 */
