#include "common.h"

/* localdecomp:start func_004DAA88 */
extern s32 D_001A1ED0[];
void func_004DAA88(unsigned long **pp, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    *(*pp)++ = 0x7000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = 0;
    *(*pp)++ = 0x19;
    *(*pp)++ = ((long)(a1 - 1) << 16) | ((long)(a2 - 1) << 48);
    *(*pp)++ = 0x41;
    *(*pp)++ = ((long)D_001A1ED0[2] >> 13) | ((long)a3 << 16) | 0xFF00000001000000UL;
    *(*pp)++ = 0x4D;
    *(*pp)++ = 0x30802;
    *(*pp)++ = 0x48;
    *(*pp)++ = (D_001A1ED0[2] >> 13) | 0x31000000 | 0x100000000UL;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0x80000000A4UL;
    *(*pp)++ = 0x43;
    *(*pp)++ = 0x4400000000000001UL;
    *(*pp)++ = 0x5510;
    *(*pp)++ = 0x346;
    *(*pp)++ = 0xFFFFFFFFUL;
    *(*pp)++ = (long)a4 | ((long)a5 << 16);
    *(*pp)++ = (long)a6 | ((long)a7 << 16);
    *(*pp)++ = 0x3000000000000001UL;
    *(*pp)++ = 0xEEEEEEEEEEEEEEEEUL;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
    *(*pp)++ = (D_001A1ED0[2] >> 13) | 0x31000000;
    *(*pp)++ = 0x4F;
    *(*pp)++ = 0;
    *(*pp)++ = 0x3F;
}
/* localdecomp:end func_004DAA88 */
