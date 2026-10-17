#include "common.h"

extern s32 D_001A1ED0[];

extern s32 D_001A1ED0[];
void func_004DAD68(unsigned long **pp, s32 a1) {
    s32 i;
    s32 x0, x1;
    long step0, step1; /* steps kept in registers, not folded into the adds */
    *(*pp)++ = 0x8000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = (D_001A1ED0[1] >> 13) | 0x2080000 | 0x3FFF00000000UL;
    *(*pp)++ = 0x4D;
    *(*pp)++ = (D_001A1ED0[2] >> 13) | 0x31000000 | 0x100000000UL;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0x30000;
    *(*pp)++ = 0x48;
    *(*pp)++ = 0;
    *(*pp)++ = 0x19;
    *(*pp)++ = 0x33F000001FF0000UL;
    *(*pp)++ = 0x41;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0;
    *(*pp)++ = 0x15;
    if (a1) {
        *(*pp)++ = (D_001A1ED0[2] >> 8) | 0x2B220000 | 0x680000000UL;
        *(*pp)++ = 7;
    } else {
        *(*pp)++ = 7;
        *(*pp)++ = (D_001A1ED0[2] >> 8) | 0x2B220000 | 0xE80000000UL;
    }
    *(*pp)++ = 0x2400000000000001UL;
    *(*pp)++ = 1;
    if (a1) {
        *(*pp)++ = 0x3F80000040808080UL;
    } else {
        *(*pp)++ = 0x3F80000080808080UL;
    }
    *(*pp)++ = 0x316;
    *(*pp)++ = 0x4400000000008020UL;
    *(*pp)++ = 0x5353;
    x0 = 8;
    x1 = 8;
    step0 = 0x10;
    step1 = 0x10;
    for (i = 0; i < 32; i++) {
        *(*pp)++ = ((x0 << 4) - 0x78) | 0x80000;
        *(*pp)++ = x1 << 4;
        *(*pp)++ = ((x0 << 4) + 8) | 0x34080000;
        *(*pp)++ = ((x1 << 4) + 0x80) | 0x34000000;
        x0 += step0;
        x1 += step1;
    }
}
