#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 D_001FC450[];
extern u8 *func_004234F0(s32 a, s32 b);
extern void func_00426940(u8 *m);

u8 *func_0034AF30(u8 *a0, s32 a1) {
    u8 *m;

    if (D_001FC450[a1] == 255) {
        return 0;
    }
    if (a1 == 0) {
        return 0;
    }
    m = func_004234F0(a1, 128);
    if (m != 0) {
        *(u128_t *)(m + 16) = *(u128_t *)(a0 + 16);
        *(u128_t *)(m + 240) = *(u128_t *)(a0 + 240);
        *(long *)(m + 56) = *(long *)(a0 + 56);
        *(u8 *)(m + 48) = *(u8 *)(a0 + 48);
        *(s16 *)(m + 50) = *(u8 *)(a0 + 48);
        *(u8 **)(m + 184) = a0;
        *(u8 *)(m + 49) = 1;
        if (*(s32 *)(m + 36) != 0) {
            func_00426940(m);
        }
        return m;
    }
    return 0;
}
