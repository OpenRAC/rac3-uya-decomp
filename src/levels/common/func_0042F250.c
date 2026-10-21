#include "common.h"

/* Retail stores to D_001D4CE8 with an assembler-expanded lui $at. The section
   attribute makes gcc emit the macro form; the 16-byte size keeps the
   assembler from using $gp for it. */
extern s32 D_001D4CE8[4] __attribute__((section(".sdata")));
extern s32 (*D_001D7598)();
typedef struct { u8 pad0[0x16C]; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_0042F250;
extern S_0042F250 D_00142430[];

void func_0042F250(void) {
    if (D_001D7598 != 0) {
        D_001D7598();
        D_001D7598 = 0;
    }
    if (D_00142430->f16C == 0) {
        D_00142430->f17C = 1;
    }
    D_001D4CE8[0] = 1;
}
