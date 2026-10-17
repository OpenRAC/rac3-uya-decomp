#include "common.h"
extern u8 D_0031A698[];
extern void func_004026A0(void *a0, u8 *a1);
void func_0031A650(u8 *a0) {
    if (a0[32] == 0) {
        a0[32] = 1;
        *(f32 *)(a0 + 192) = 1.0f;
        *(f32 *)(a0 + 212) = 1.0f;
        *(f32 *)(a0 + 232) = 1.0f;
    }
    func_004026A0(D_0031A698, a0);
}
