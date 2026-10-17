#include "common.h"

extern u8 D_001A4BE0[];
extern f32 func_0040CEC8(f32, f32);
extern f32 func_0040C3E0(f32);
extern s32 func_0040D020(f32, s32, s32);

void func_0050E9D0(u8 *arg0)
{
    u8 *p = D_001A4BE0;
    f32 f;
    s32 c;
    u8 *o;

    f = func_0040CEC8(*(f32 *)(p + 10256), 0.061086528f);
    *(f32 *)(p + 10256) = f;
    f = func_0040C3E0(f);
    c = func_0040D020(f * 0.5f + 0.5f, 0x808C8C8C, 0x80464646);
    *(s32 *)(arg0 + 120) = c;
    o = *(u8 **)(p + 4768);
    if (o != 0) {
        *(s32 *)(o + 120) = c;
    }
}
