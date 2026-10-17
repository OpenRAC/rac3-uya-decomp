#include "common.h"
extern u8 D_00632A28[];
extern void func_005890F0(void *a0, s32 a1);
void func_006326F0(u8 *a0) {
    if (a0[6676] && *(s16 *)(a0 + 6626) == 0) {
        *(s16 *)(a0 + 6626) = 1;
        func_005890F0(D_00632A28, *(s32 *)(a0 + 9508));
    }
}
