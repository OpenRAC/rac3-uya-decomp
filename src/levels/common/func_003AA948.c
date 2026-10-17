#include "common.h"

void func_003AA948(u8 *obj, s32 a, s32 b, s32 c, s32 d, f32 e, f32 f, f32 g, f32 h) {
    u8 *p = *(u8 **)(obj + 104);
    *(f32 *)(p + 44) = e;
    *(s32 *)(p + 48) = a;
    *(s32 *)(p + 52) = c;
    *(s32 *)(p + 56) = b;
    *(s32 *)(p + 60) = d;
    *(f32 *)(p + 64) = f;
    *(f32 *)(p + 68) = g;
    *(f32 *)(p + 72) = h;
}
