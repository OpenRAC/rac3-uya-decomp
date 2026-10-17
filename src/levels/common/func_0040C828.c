#include "common.h"

extern void func_0047F5C0(u8 *, s32, s32, s32);

void func_0040C828(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *v = *(u8 **)(a0 + 104);
    if (a0[67] != a1) {
        func_0047F5C0(a0, a1, a2, a3);
    }
    a0 = *(u8 **)(v + 624);
    if (a0[67] != a1) {
        func_0047F5C0(a0, a1, a2, a3);
    }
}
