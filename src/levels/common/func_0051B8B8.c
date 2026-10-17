#include "common.h"

extern void func_0051B8B8(u8 *p, u8, s32);

void func_0051B8B8(u8 *p, u8 m, s32 set) {
    if (set != 0) {
        p[0x44] |= m;
    } else {
        p[0x44] &= ~m;
    }
}
