#include "common.h"
typedef int u128_00378010 __attribute__((mode(TI)));
extern u8 *func_004452B0(s32, s32);
extern void func_00378290(u8 *);
extern void func_00448A30(u8 *);
u8 *func_00378010(u128_00378010 *a0) {
    u8 *m = func_004452B0(6239, 128);
    if (m != 0) {
        *(s16 *)(m + 50) = 64;
        m[48] = 40;
        m[32] = 0;
        *(u128_00378010 *)(m + 16) = *a0;
        func_00378290(m);
        func_00448A30(m);
    }
    return m;
}
