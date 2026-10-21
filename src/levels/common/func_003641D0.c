#include "common.h"

extern s32 func_00462650(u8 *);
extern void func_00451098(u8 *, s32, s32, s32);
extern void func_004513D8(u8 *, s32, s32);
extern f32 func_00445940(u8 *);
extern void func_00446AD8(void *, s32, void *);
extern s32 func_00452BB0(u8 *, f32, f32, void *, s32, f32, s32, s32, s32);

s32 func_003641D0(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    u8 a[16];
    u8 b[16];
    f32 d;
    if (func_00462650(o) != 0 && o[0x43] != 0x16) {
        func_00451098(o, 0x16, 0, 6);
    }
    d = func_00445940(o);
    if (d >= 14.0f && d < 19.0f && o[0x42] == 0x16) {
        func_00446AD8(*(u8 **)(s + 0x2FC), 0, b);
        func_00446AD8(o, 0, a);
        func_00452BB0(o, 0.5f, s[0x45], b, 1, 1.0f, 0, 1, 0);
        func_00452BB0(o, 0.5f, s[0x45], a, 1, 1.0f, 0, 1, 0);
    }
    if (o[0x60] & 2) {
        func_004513D8(o, 0xD, -1);
        return 2;
    }
    return 0;
}
