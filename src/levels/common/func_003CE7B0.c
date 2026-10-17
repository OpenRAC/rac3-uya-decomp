#include "common.h"

extern void func_003CE5D8(u8 *, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_0042DBA8(s32, s32);

void func_003CE7B0(u8 *obj)
{
    if (*(u16 *)(obj + 150) == 0) {
        func_003CE5D8(obj, 1, 3, -0.3f, 2.5f, 0.15f, 0.03f, 1.0f, -8.0f, 7.0f);
        *(u16 *)(obj + 150) = func_0042DBA8(50, 400);
    }
    *(u16 *)(obj + 150) -= 1;
}
