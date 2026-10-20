#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern u8 *func_00449388(u8 *);
extern void func_0040C658(void *, void *);
extern void func_0040C8E0(void *, void *);
extern void func_0040C2D0(void *, void *, void *);

s32 func_00449518(s32 a0, u8 *a1, s128 *a2, s128 *a3) {
    s128 m0[4];
    s128 m1[4];
    s128 m2[4];
    u8 *p = func_00449388(a1);
    if (p == 0) {
        *a3 = *a2;
        return 0;
    }
    func_0040C658(m0, p);
    if (*(s32 *)(p + 60) & 2) {
        func_0040C658(m2, p + 32);
        func_0040C8E0(m1, m2);
        func_0040C2D0(a3, a2, m1);
        func_0040C2D0(a3, a3, a1 + 192);
    } else {
        func_0040C2D0(a3, a2, m0);
    }
    return 1;
}
