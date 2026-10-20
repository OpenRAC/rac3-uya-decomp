#include "common.h"

extern u8 *D_001E0F54;
extern u8 *D_001E0F58;
extern u8 *D_001E0E48;
extern u8 *D_001E0E4C;
extern u8 *D_001E009C;
extern u8 *D_001E00A0;
extern s32 func_00428118(void *);

void func_004281A8(s32 a0)
{
    u8 *p;

    for (p = D_001E0F54; p != D_001E0F58; p += 32) {
        if (func_00428118(p) != a0) {
            p[30] |= 4;
        } else {
            p[30] &= ~4;
        }
    }
    for (p = D_001E0E48; p != D_001E0E4C; p += 32) {
        if (func_00428118(p) != a0) {
            p[22] |= 1;
        } else {
            p[22] &= ~1;
        }
    }
    for (p = D_001E009C; p != D_001E00A0; p += 256) {
        if (*(s16 *)(p + 170) != 0) {
            if (func_00428118(p + 16) != a0) {
                *(u16 *)(p + 52) |= 0x80;
            } else {
                *(u16 *)(p + 52) &= ~0x80;
            }
        }
    }
}
