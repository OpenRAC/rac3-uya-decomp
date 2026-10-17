#include "common.h"

extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
extern void func_0040CEC8(f32, f32);
extern long func_00401CD0(s32);

typedef struct {
    u8 p0[0x10]; f32 f10; s32 f14; s32 f18; f32 f1C; u8 p20[6]; s16 h26; f32 f28; s32 f2C;
    u8 p30[8]; f32 f38; f32 f3C;
} S_3810C0;
extern void func_00404740(f32, f32, f32, f32, f32, s32, s32, long, s32, s32, s32, s32, f32, f32);
extern long func_00401CD0(s32);
extern f32 func_0040C3C8(f32);
extern f32 func_0040C3E0(f32);
void func_003F43E0(S_3810C0 *o, f32 x, f32 y) {
    long tex;
    f32 w, h, a;
    f32 p[4], q[4];
    s32 i;
    if (o == 0) return;
    w = o->f38;
    h = o->f3C;
    tex = func_00401CD0(o->f18);
    a = o->f1C;
    switch (o->f2C) {
    case 0:
        for (i = 0; i < o->h26; i++) {
            func_00404740(x, y, w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 0, 0.0f, 0.0f);
            a = ((f32 (*)(f32, f32))func_0040CEC8)(a, o->f28);
        }
        break;
    case 1:
        p[0] = h * func_0040C3E0(a) * o->f10;
        p[1] = h * func_0040C3C8(a) * o->f10;
        q[0] = w * func_0040C3C8(a) * o->f10;
        q[1] = -w * func_0040C3E0(a) * o->f10;
        func_00404740(x, y, w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 0, 0.0f, 0.0f);
        func_00404740(x + q[0], y + q[1], w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 1, 0, 0.0f, 0.0f);
        func_00404740(x - p[0], y - p[1], w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 1, 0.0f, 0.0f);
        func_00404740(x + q[0] - p[0], y + q[1] - p[1], w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 1, 1, 0.0f, 0.0f);
        break;
    case 2:
        func_00404740(x, y, w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 0, 0.5f, 0.5f);
        break;
    }
}
