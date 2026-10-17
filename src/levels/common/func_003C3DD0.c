#include "common.h"

extern void func_00452F40(u8 *o, s32 a);

void func_003C3DD0(u8 *a) {
    u8 *p = *(u8 **)(a + 104);
    func_00452F40(a, 1);
    p[259] = 1;
}
