#include "common.h"

extern u8 D_001A4BE0[];
extern s32 func_004DC0D0(s32);
extern void func_0050BB98(s32, s32, f32);

void func_004E6CB0(void)
{
    u8 *g = D_001A4BE0;
    u8 *h;

    if (g[9705] == 0) {
        return;
    }
    if (*(s32 *)(g + 3704) != 0) {
        *(s32 *)(g + 3716) = 1;
    } else if (*(s32 *)(g + 9668) == 0 && (*(u8 **)(g + 9664))[67] == *(s32 *)(g + 10288)) {
        func_0050BB98(func_004DC0D0(0), 0, -2.0f);
    }
    h = D_001A4BE0;
    h[9705] = 0;
    h[9707] = 0;
}
