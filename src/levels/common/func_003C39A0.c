#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern void func_0040C638(u8 *, u8 *);
extern void func_0044C1D0(u8 *, u8 *);
extern void func_003C3908(u8 *, u8 *);

void func_003C39A0(u8 *a0, u8 *a1) {
    func_0040C638(a0 + 192, a0 + 240);
    func_0044C1D0(a0, a1 + 368);
    *(u128_t *)(a1 + 272) = *(u128_t *)(a0 + 16);
    *(u128_t *)(a1 + 288) = *(u128_t *)(a0 + 240);
    *(f32 *)(a1 + 248) = *(f32 *)(a1 + 1652);
    *(f32 *)(a1 + 252) = *(f32 *)(a1 + 1704);
    func_003C3908(a0, a1);
}
