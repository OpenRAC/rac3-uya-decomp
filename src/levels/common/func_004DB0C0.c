#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; } T_3D3780;
extern T_3D3780 D_001A1ED0_003D3780;
s32 func_004DB0C0(long **pp, s32 w, s32 h, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 c) {
    T_3D3780 *t = &D_001A1ED0_003D3780;
    *(*pp)++ = 0x2000000000000001UL;
    *(*pp)++ = 0xEE;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = (t->f8 >> 13) | 0x31000000;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0x4000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x19;
    *(*pp)++ = ((long)(w - 1) << 16) | ((long)(h - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = ((long)t->f4 >> 13) | ((long)a3 << 16) | 0xFFFFFF00000000UL;
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x70802;
    *(*pp)++ = 0x48;
    *(*pp)++ = 0x4400000000000001UL;
    *(*pp)++ = 0x5510;
    *(*pp)++ = 0x306;
    *(*pp)++ = 0xFFFFFF;
    *(*pp)++ = a4 | ((long)a5 << 16) | ((long)c << 32);
    *(*pp)++ = a6 | ((long)a7 << 16) | ((long)c << 32);
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0x1000000000008001UL;
    *(*pp)++ = 0xE;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
