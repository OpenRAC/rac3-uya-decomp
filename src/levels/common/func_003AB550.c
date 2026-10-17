#include "common.h"

extern void func_004412D0(s32, s32, s32);
extern void func_003AB348(s32, s32);

void func_003AB550(s32 a0, u8 *a1) {
    *(s32 *)(a1 + 3360) = 1;
    func_004412D0(a0, 0, 3);
    (*(void (**)(s32))(*(u8 **)(a1 + 3144) + 4))(*(s32 *)(a1 + 100));
    func_003AB348(a0, 1);
}
