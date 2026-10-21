#include "common.h"

/* The 16-byte .sdata declarations look small to gcc (no %hi/%lo split) but
   not to the assembler, which reaches them through lui, as Ps2EeAs did for
   symbols it had no size for yet; the other small ones go through $gp. */
extern s32 D_001D6690_0039BF98[4] __attribute__((section(".sdata")));
extern s32 D_001D6694_0039BF98[4] __attribute__((section(".sdata")));
extern s32 D_001A7430_0039BF98[];
extern s32 D_001E02A0_0039BF98[4] __attribute__((section(".sdata")));
extern s32 D_001D7DC8_0039BF98;
extern s32 D_001D7DC0_0039BF98;
extern s32 D_001D7DC4_0039BF98;
extern s32 D_001D7DCC_0039BF98;
s32 func_00457360(s32 screenId, s32 arg1) {
    s32 result;
    if (D_001D6690_0039BF98[0] != -2) result = 1; else result = 0;
    if (D_001D7DC8_0039BF98 == 0) result = 1;
    if (D_001D6694_0039BF98[0] != 4) {
        if (D_001A7430_0039BF98[0] == 0) result = -1;
    }
    if (result == 0) {
        s32 i = D_001D7DC8_0039BF98 - 1;
        D_001D7DC0_0039BF98 = screenId;
        D_001D7DC4_0039BF98 = arg1;
        D_001D7DC8_0039BF98 = i;
        D_001D6690_0039BF98[0] = D_001E02A0_0039BF98[i];
        D_001D7DCC_0039BF98 = 0;
    }
    return result;
}
