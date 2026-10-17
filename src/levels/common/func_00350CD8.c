#include "common.h"

extern void func_00424F38(u8 *o, s32 a, s32 b, s32 c);

void func_00350CD8(s32 unused, u8 *b, s32 x, s32 y, s32 z) {
    u8 *o = *(u8 **)(b + 608);
    if (o[67] != x) {
        func_00424F38(o, x, y, z);
    }
}
