#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

extern void func_00630AC0(u8 *self, s32 a, f32 f0, f32 f1, f32 f2);

void func_006355C8(u8 *self) {
    f32 f;
    if (*(u8 *)(self + 6676) != 0) {
        if (*(s16 *)(*(u8 **)(*(u8 **)(self + 9520) + 80) + 134) == 33) {
            return;
        }
    }
    *(f32 *)(self + 4048) = *(f32 *)(self + 9144);
    *(f32 *)(self + 4052) = *(f32 *)(self + 1004);
    *(u128_t *)(self + 4032) = *(u128_t *)(self + 9152);
    func_00630AC0(self, 0, 0.09f, 0.25f, 0.378154665f);
    f = *(f32 *)(self + 4056);
    *(f32 *)(self + 1052) = f;
    *(f32 *)(self + 1004) = *(f32 *)(self + 4052);
    if (f == 0.0f) {
        *(s32 *)(self + 1020) += 1;
    } else {
        *(s32 *)(self + 1020) = 0;
    }
}
