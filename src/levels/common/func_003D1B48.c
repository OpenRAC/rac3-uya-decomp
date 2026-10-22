#include "common.h"

extern void func_00451098(u8 *, s32, s32, s32);

void func_003D1B48(u8 *o, u8 *src) {
    u8 *s = *(u8 **)(src + 0x68);
    u8 *d = *(u8 **)(o + 0x68);
    s32 t;
    d[0x80] = s[0x54];
    t = *(s32 *)(s + 0x1C);
    if (t == 2) {
        *(s32 *)(d + 0xD0) = -1;
        *(s32 *)(d + 0xD4) = 0;
        d[0x81] = 1;
        d[0x82] = 1;
    } else if (t == 3) {
        d[0x82] = 2;
        *(s32 *)(d + 0xD0) = *(s32 *)(s + 0x70);
        *(s32 *)(d + 0xD4) = 0;
    } else {
        d[0x81] = s[0x1C];
        *(s32 *)(d + 0xD0) = -1;
        d[0x82] = 0;
        *(s32 *)(d + 0xD4) = 0;
    }
    if (o[0x43] != 0) {
        func_00451098(o, 0, 0, 0);
    }
}
