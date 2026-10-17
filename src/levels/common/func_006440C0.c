#include "common.h"
void func_006440C0(u8 *a, u8 *b) {
    if (b[66] == b[67] && b[66] >= 3 && *(s32 *)(a + 9500) == 0) {
        b[49] = 1;
        *(u16 *)(b + 52) &= 0xFFFE;
    } else {
        b[49] = 0;
        *(u16 *)(b + 52) |= 1;
    }
}
