#include "common.h"

extern f32 D_001DD748[6];
extern s32 func_00462650(u8 *);
extern void func_00446A40(u8 *, s32, void *);
extern void func_00451098(u8 *, s32, s32, s32);
extern void func_004513D8(u8 *, s32, s32);
extern s32 func_0045A4A8(u8 *, f32);
extern void func_00360940(u8 *, u8 *, s32, s32);

s32 func_00364968(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    u8 buf[0x40];
    s32 i;
    f32 *p;
    if (func_00462650(o) != 0) {
        func_00446A40(*(u8 **)(s + 0x2FC), 0, buf);
        if (o[0x43] != 0xD) {
            func_00451098(o, 0xD, 0, 0);
        }
        if ((*(u16 *)(o + 0x34) & 0x8000) && o[0x43] != 9) {
            func_00451098(o, 9, 0, 0);
        }
        *(s32 *)(s + 0x368) = -1;
    }
    i = *(s32 *)(s + 0x368);
    if (i < 6) {
        p = &D_001DD748[i];
        do {
            if (func_0045A4A8(o, *p) != 0) {
                *(s32 *)(s + 0x368) = i;
                func_00360940(o, s, i, 6);
            }
            i++;
            p++;
        } while (i < 6);
    }
    if (o[0x60] & 2) {
        func_004513D8(o, 0x15, -1);
        return 2;
    }
    return 0;
}
