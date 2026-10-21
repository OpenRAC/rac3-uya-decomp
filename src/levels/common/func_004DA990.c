#include "common.h"

/* localdecomp:start func_004DA990 */
/* Retail reaches these two through lui and D_001DBCE4 through $gp. The
   .sdata section makes gcc treat them as small (no %hi/%lo split); their
   16-byte size makes the assembler expand each access with lui. */
extern s32 D_001D55F0[4] __attribute__((section(".sdata")));
extern u32 *D_001E10E8[4] __attribute__((section(".sdata")));
extern u32 *D_001E10E8_g;
extern s32 D_001DBCE4;
extern s32 D_001D0A50[];
void func_004DA990(void) {
    D_001DBCE4 = 0x6000;
    D_001E10E8[0][0] = (D_001D55F0[0] >> 4) | 0x30000000;
    D_001E10E8[0][1] = (u32)D_001D0A50;
    D_001E10E8[0][2] = 0;
    D_001E10E8[0][3] = (D_001D55F0[0] >> 4) | 0x50000000;
    D_001E10E8_g = D_001E10E8[0] + 4;
}
/* localdecomp:end func_004DA990 */
