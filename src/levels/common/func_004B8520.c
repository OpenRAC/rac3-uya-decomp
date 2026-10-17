#include "common.h"

extern u8 D_00244740[];
extern u8 D_001DAD08[];
extern void func_0011B2E8(s32, u8 *, s32);

void func_004B8520(s32 a0) {
    u8 *s = D_00244740;
    func_0011B2E8(*(s32 *)(s + 60), D_001DAD08, a0);
    *(s32 *)(s + 100) = 0;
}
