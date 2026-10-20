#include "common.h"

extern void **func_00438488(s32, s32, s32);
extern u8 D_002BB0F0[];
extern u8 D_001E2AC0[];
extern f32 func_0040C018(void *, void *);
extern void func_00444188(u8 *);
extern void func_00441FB8(u8 *, s32, s32);
extern void func_004A6DF8(u8 *, s32);

void func_003BACE8(u8 *p) {
    void **f;

    switch (p[0x20]) {
    case 0:
        f = func_00438488(6476, 0, 4);
        if (f == 0) {
            goto kill;
        }
        ((void (*)(u8 *, void *))f[0])(p, D_002BB0F0);
        goto kill;
    case 2:
        if (p[0x31] != 0) {
            if (func_0040C018(D_001E2AC0, p + 0x10) < 1024.0f) {
                func_00444188(p);
                p[0x6F] = 30;
            }
        }
        return;
    case 3:
        (*(u16 *)(p + 0x96))++;
        if (*(u16 *)(p + 0x96) <= 600) {
            return;
        }
    kill:
        func_00441FB8(p, 1, -1);
    case 1:
        *(s32 *)(p + 0x98) = 0;
        *(u16 *)(p + 0x34) = (*(u16 *)(p + 0x34) | 0x41) & 0xEFFF;
        func_004A6DF8(p, 1);
        *(u16 *)(p + 0x34) |= 2;
        return;
    }
}
