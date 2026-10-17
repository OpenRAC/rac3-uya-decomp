#include "common.h"

extern u8 *D_001E009C;
extern void (**func_00326898(void))(u8 *, s32);
extern void func_003B5048(u8 *, u8 *, s32);

void func_003B5940(u8 *a0, u8 *a1) {
    void (**v)(u8 *, s32) = func_00326898();
    u8 *m = D_001E009C + (*(s32 *)(a1 + 108) << 8);
    func_003B5048(a0, m, 0);
    (*v)(m, 0);
}
