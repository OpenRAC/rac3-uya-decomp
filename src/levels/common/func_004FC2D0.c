#include "common.h"

/* localdecomp:start func_004FC2D0 */
typedef struct {
    u8 pad0[0x1B8];
    s32 x1B8;
    u8 pad1BC[0x23D4 - 0x1BC];
    s32 x23D4[16];
    s32 x2414[16];
    s32 x2454[16];
    s32 x2494;
    u8 pad2498[0x25C4 - 0x2498];
    s32 x25C4;
    s32 x25C8;
    s32 x25CC;
    s32 x25D0;
    s32 x25D4;
    s32 x25D8;
    s32 x25DC;
    s32 x25E0;
} G_4FC2D0;
extern G_4FC2D0 D_001A4BE0;
void func_004FC2D0(void) {
    s32 n = D_001A4BE0.x2494;
    s32 i;
    if (n >= 16) {
        n = 15;
    }
    for (i = n - 1; i >= 0; i--) {
        D_001A4BE0.x23D4[i + 1] = D_001A4BE0.x23D4[i];
        D_001A4BE0.x2414[i + 1] = D_001A4BE0.x2414[i];
        D_001A4BE0.x2454[i + 1] = D_001A4BE0.x2454[i];
    }
    D_001A4BE0.x23D4[0] = D_001A4BE0.x25C4;
    D_001A4BE0.x2414[0] = D_001A4BE0.x25CC;
    D_001A4BE0.x2454[0] = D_001A4BE0.x1B8;
    D_001A4BE0.x2494++;
    if (D_001A4BE0.x2494 > 16) {
        D_001A4BE0.x2494 = 16;
    }
    D_001A4BE0.x25DC = D_001A4BE0.x25D0;
    D_001A4BE0.x25E0 = D_001A4BE0.x25D4;
    D_001A4BE0.x25D8 = D_001A4BE0.x1B8;
    D_001A4BE0.x25D0 = D_001A4BE0.x25C4;
    D_001A4BE0.x25D4 = D_001A4BE0.x25CC;
}
/* localdecomp:end func_004FC2D0 */
