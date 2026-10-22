#include "common.h"

extern s32 func_00462650(u8 *);
extern void func_00468218(u8 *, f32, f32, f32, f32);
extern s32 func_0044FC98(s32, s32);
extern void func_00451098(u8 *, s32, s32, s32);
extern void func_00465620(u8 *, s32, void *);
extern void func_00465410(u8 *, void *, s32, s32);
extern void func_00466BC8(u8 *, void *);
extern f32 func_0041C8C0(void *, void *);
extern f32 func_0041CDA8(f32, f32);
extern f32 func_0041D8C8(f32, f32);
extern void func_004513D8(u8 *, s32, s32);

s32 func_00363900(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    if (func_00462650(o) != 0) {
        func_00468218(o, 0.00444444455f, 0.100000009f, 0.00698131742f, 0.209439531f);
        if (o[0x43] != 3) {
            func_00451098(o, 3, 0, func_0044FC98(8, 0xE));
        }
        func_00465620(o, *(s32 *)(s + 0x230), s + 0x410);
    }
    if (*(s32 *)(s + 0x4E4) == 0) {
        *(s32 *)(s + 0x460) = *(s32 *)(s + 0x230);
        func_00465410(o, s + 0x410, 0, 0);
        func_00466BC8(o, s + 0x410);
    }
    if (*(f32 *)(s + 0x120) < *(f32 *)(s + 0x98) * 0.8f) {
        *(s32 *)(s + 0x450) += 1;
    }
    if (*(s32 *)(s + 0x230) != *(s32 *)(s + 0x460)) {
        func_00465620(o, *(s32 *)(s + 0x230), s + 0x410);
    }
    if (func_0041C8C0(o + 0x10, s + 0x220) < 15.0f) {
        if (func_0041D8C8(*(f32 *)(o + 0xF8), func_0041CDA8(*(f32 *)(s + 0x220) - *(f32 *)(o + 0x10), *(f32 *)(s + 0x224) - *(f32 *)(o + 0x14))) < 0.17453292f) {
            func_004513D8(o, 0xD, -1);
            return 1;
        }
        return 0;
    }
    return 0;
}
