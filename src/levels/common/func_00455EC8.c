#include "common.h"
typedef unsigned int Q __attribute__((mode(TI)));
extern void func_00454C30(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12);
void func_00455EC8(u8 *a0, Q *a1, u8 *a2) {
    Q v = *a1;
    Q tmp[1];
    *(s32 *)(a2 + 80) = 0;
    *(Q *)(a2 + 32) = v;
    *(Q *)(a2 + 16) = v;
    *(Q *)(a2 + 0) = v;
    tmp[0] = v;
    *(Q *)(a2 + 112) = *(Q *)(a0 + 16);
    func_00454C30(a0, a2, 0, 0, 12.0f);
    *(s32 *)(a2 + 64) = 0;
}
