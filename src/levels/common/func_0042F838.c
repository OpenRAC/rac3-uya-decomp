#include "common.h"

/* localdecomp:start func_0042F838 */
typedef struct { u8 pad[0x15C]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396830;
extern S_396830 D_00142430_00396830[];
extern s32 D_001D4CEC_00396830;
extern s32 D_001D4CE8_00396830;
void func_0042F838(void) {
    S_396830 *p = D_00142430_00396830;
    if (p->x15C == 2 && p->x164 < 0) {
        p->x164 = 9;
        D_001D4CEC_00396830 &= ~2;
        D_001D4CEC_00396830 &= ~0x10;
        p->x168 = 0;
        D_001D4CE8_00396830 = 0x11;
    }
}
/* localdecomp:end func_0042F838 */
