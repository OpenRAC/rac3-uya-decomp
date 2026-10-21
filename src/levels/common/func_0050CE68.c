#include "common.h"

/* localdecomp:start func_0050CE68 */
typedef struct {
    u8 pad[536];
    s16 h536;
    u8 pad2[872 - 538];
    s16 h872;
    u8 pad3[4];
    s16 h878;
    u8 pad4[5241 - 880];
    u8 b5241;
    u8 pad5[2];
    u8 b5244;
    u8 pad6[9668 - 5245];
    s32 f9668;
} St_0050CE68;

extern St_0050CE68 D_001A4BE0;
extern s32 D_001D673C;
extern s32 D_001D6740;
extern u8 D_00142CAD[];

s32 func_0050CE68(void) {
    s32 r = D_001A4BE0.h872;

    if (D_001D673C != 0 && D_001D6740 == 0) {
        r = 2;
    }
    if (D_001D6740 != 0 || D_001A4BE0.f9668 == 59 || (D_001A4BE0.f9668 == 115 && D_001A4BE0.b5244 == 0)
        || D_001A4BE0.f9668 == 114 || D_001A4BE0.h536 != 0
        || (D_001A4BE0.b5241 != 0 && D_00142CAD[0] != 0 && D_001A4BE0.f9668 == 0 && D_001A4BE0.h878 < 4)) {
        r = 1;
    }
    if (r == 1 && D_001A4BE0.b5244 != 0 && D_001A4BE0.b5241 == 0) {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_0050CE68 */
