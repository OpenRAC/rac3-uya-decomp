#include "common.h"

void func_004C9188(u8 *a0, s32 a1, s32 a2) {
    u32 *p = *(u32 **)(a0 + 12);
    p[0] = (p[0] & 0xFFFFFF) | (a1 << 24);
    (*(u32 **)(a0 + 12))[1] = ((*(u32 **)(a0 + 12))[1] & 0xFFFFFF) | (a2 << 24);
}
