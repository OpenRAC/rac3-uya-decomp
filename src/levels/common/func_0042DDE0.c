#include "common.h"

extern s32 func_0042DFD8(s32 a, s32 b, f32 c);
extern u8 *func_0042F078(s32 a);

s32 func_0042DDE0(s32 a0, s32 a1, s32 a2, f32 f0, f32 f1, f32 f2, f32 f3) {
    u8 *p;
    s32 old38;
    f32 old28, old20, old24;
    s32 ret;

    p = func_0042F078(a0);
    if (p == 0) {
        return 8;
    }
    old38 = *(s32 *)(p + 0x38);
    *(s32 *)(p + 0x38) = a2;
    old28 = *(f32 *)(p + 0x28);
    if (f1 > 0.0f) {
        *(f32 *)(p + 0x28) = f1;
    }
    old20 = *(f32 *)(p + 0x20);
    if (f2 > 0.0f) {
        *(f32 *)(p + 0x20) = f2;
    }
    old24 = *(f32 *)(p + 0x24);
    if (f3 > 0.0f) {
        *(f32 *)(p + 0x24) = f3;
    }
    ret = func_0042DFD8(a0, a1, f0);
    *(s32 *)(p + 0x38) = old38;
    *(f32 *)(p + 0x28) = old28;
    *(f32 *)(p + 0x20) = old20;
    *(f32 *)(p + 0x24) = old24;
    return ret;
}
