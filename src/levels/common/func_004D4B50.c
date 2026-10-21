#include "common.h"

extern void func_004D4B50(void);

/* The 16-byte .sdata declarations look small to gcc (no %hi/%lo split) but
   not to the assembler, which reaches them through lui, as Ps2EeAs did for
   symbols it had no size for yet; the other small ones go through $gp. */
extern u32 *D_001E10E8[4] __attribute__((section(".sdata")));
extern u32 *D_001E10E8_g; /* D_001E10E8 in a branch delay slot: $gp */
extern u8 D_001D02D0[];
extern u8 D_001D9DC0[];
extern s32 D_001DB930;
void func_004D4B50(void) {
    D_001E10E8[0][0] = 0x30000002;
    D_001E10E8[0][1] = (u32)&D_001DB930;
    D_001E10E8[0][2] = 0;
    D_001E10E8[0][3] = 0x50000002;
    D_001E10E8[0] += 4;
    D_001E10E8[0][0] = 0x30000029;
    D_001E10E8[0][1] = (u32)D_001D02D0;
    D_001E10E8[0][2] = 0;
    D_001E10E8[0][3] = 0x50000029;
    D_001E10E8[0] += 4;
    D_001E10E8[0][0] = 0x30000003;
    D_001E10E8[0][1] = (u32)D_001D9DC0;
    D_001E10E8[0][2] = 0;
    D_001E10E8[0][3] = 0x50000003;
    D_001E10E8_g = D_001E10E8[0] + 4;
}
