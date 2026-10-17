#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_003F0BB8(void *a0, void *a1);
extern s32 func_004579C0(void *a0, s32 a1, void *a2);
extern f32 func_003F0B80(void *a0, void *a1);
void func_00350A30(u8 *a0, u8 *a1, u128_t *a2, s32 *a3, f32 *t0) {
    if (*(s32 *)(a1 + 624) != 0) {
        *a2 = *(u128_t *)(a0 + 16);
        *a3 = 0;
        *t0 = func_003F0BB8(a0 + 16, a1 + 544);
    } else {
        *a3 = func_004579C0(a2, *(s32 *)(a1 + 856), a1 + 544);
        *t0 = func_003F0B80(a1 + 544, a2);
    }
}
