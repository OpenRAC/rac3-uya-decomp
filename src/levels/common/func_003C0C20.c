#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern void func_00405D10(u8 *a0, u8 *a1);
extern void func_0043AAF8(u8 *a0, s32 a1, s32 a2);
void func_003C0C20(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    *(s16 *)(p + 408) = 0;
    *(f32 *)(p + 48) = *(s16 *)(p + 52);
    a0[127] = 0;
    *(u128_t *)(a0 + 16) = *(u128_t *)(p + 832);
    *(u128_t *)(a0 + 240) = *(u128_t *)(p + 816);
    func_00405D10(a0 + 192, p + 816);
    *(s32 *)(a0 + 152) = *(s32 *)(*(u8 **)(a0 + 36) + 16);
    func_0043AAF8(a0, 0, 0);
}
