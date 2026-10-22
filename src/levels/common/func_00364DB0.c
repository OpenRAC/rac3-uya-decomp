#include "common.h"

extern void func_00360940(void *a0, void *a1, s32 a2, s32 a3);
extern void func_00446A40(s32 a0, s32 a1, void *a2);
extern void func_00451098(void *a0, s32 a1, s32 a2, s32 a3);
extern void func_004513D8(void *a0, s32 a1, s32 a2);
extern s32 func_0045A4A8(void *a0, f32 f);
extern s32 func_00462650(void *a0);
extern f32 D_001DD760[6];

s32 func_00364DB0(u8 *a0) {
    u8 *s3;
    s32 i;
    u8 buf[0x40];

    s3 = *(u8 **)(a0 + 0x68);
    if (func_00462650(a0) != 0) {
        func_00446A40(*(s32 *)(s3 + 0x2FC), 0, buf);
        if (a0[0x43] != 9) {
            func_00451098(a0, 9, 0, 0);
        }
        if ((*(u16 *)(a0 + 0x34) & 0x8000) && a0[0x43] != 0xD) {
            func_00451098(a0, 0xD, 0, 0);
        }
        *(s32 *)(s3 + 0x368) = -1;
    }
    for (i = *(s32 *)(s3 + 0x368); i < 6; i++) {
        if (func_0045A4A8(a0, D_001DD760[i]) != 0) {
            *(s32 *)(s3 + 0x368) = i;
            func_00360940(a0, s3, i, 6);
        }
    }
    if (a0[0x60] & 2) {
        func_004513D8(a0, 0x18, -1);
        return 2;
    }
    return 0;
}
