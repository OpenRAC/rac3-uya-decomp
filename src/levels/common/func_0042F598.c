#include "common.h"

/* localdecomp:start func_0042F598 */
typedef struct { u8 p0[8]; s32 f8; s32 fC; u8 p10[8]; s16 h18; u8 p1A[6]; s32 f20; u8 p24[0x15C - 0x24]; s32 f15C; u8 p160[4]; s32 f164; u8 p168[4]; s32 f16C; } S_396590;
extern S_396590 D_00142430_00396590[];
extern s32 D_001D4CE8_00396590;
void func_0042F598(void) {
    S_396590 *s = D_00142430_00396590;
    if (s->f15C != 2) return;
    if (s->f164 >= 0) return;
    if (s->f16C != 0) {
        D_001D4CE8_00396590 = 0xE;
        return;
    }
    if (s->f8 != 2) {
        D_001D4CE8_00396590 = 4;
        return;
    }
    if (s->h18 == -2) {
        if (s->fC + s->f20 < 0x258) {
            D_001D4CE8_00396590 = 0x15;
            return;
        }
        D_001D4CE8_00396590 = 0xE;
        return;
    }
    if (s->h18 >= -1) {
        D_001D4CE8_00396590 = 0x12;
    }
}
/* localdecomp:end func_0042F598 */
