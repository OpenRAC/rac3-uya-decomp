#include "common.h"

extern s32 func_0040BAC0(u8 *);
extern void func_003E37F0(u8 *, s32, void *, s32);
extern void func_003E3730(u8 *, u8 *, void *, f32, f32, f32);

void func_003E38B8(u8 *a0, s32 a1) {
    u8 buf[16];
    u8 *q;
    u8 *s;
    f32 scale;
    f32 x;
    f32 y;
    u8 t;

    q = *(u8 **)(a0 + 0x70);
    s = q + 0x60;
    if (func_0040BAC0(q + 0x146) != 0) {
        s[0xE5] = s[0xE4];
    }
    scale = (f32)*(s16 *)(s + 0xE6) * *(f32 *)(s + 0xE8);
    func_003E37F0(a0, a1, buf, s[0xE4]);
    t = s[0xE4];
    if (t == 3 || t == 5 || t == 6 || t == 7 || t == 1) {
        x = scale * -0.049999997f + 0.0599999987f;
        y = scale * -0.200000003f + 0.400000006f;
    } else {
        x = 0.00999999978f;
        y = 0.200000003f;
    }
    func_003E3730(a0, s + 0xB0, buf, x, y, 0.0f);
}
