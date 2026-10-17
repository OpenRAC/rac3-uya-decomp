#include "common.h"

extern f32 D_00246190[];
extern void func_00630530(u8 *a0, s32 a1, f32 f);

void func_00630918(u8 *a0) {
    func_00630530(a0, 0, 1.0f);
    if (0.0f < *(f32 *)(a0 + 4016)) {
        *(f32 *)(a0 + 4016) = D_00246190[0] * 0.016666668f * *(f32 *)(a0 + 9320);
    }
}
