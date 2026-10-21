#include "common.h"

/* localdecomp:start func_0042F490 */
typedef struct { u8 pad[0x15C]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396488;
extern S_396488 D_00142430_00396488[];
extern s32 D_001D4CEC_00396488;
extern s32 D_001D4CE8_00396488;
void func_0042F490(void) {
    S_396488 *p = D_00142430_00396488;
    if (p->x15C == 2 && p->x164 < 0) {
        if (p->x16C) {
            D_001D4CE8_00396488 = 0x13;
            D_001D4CEC_00396488 |= 0x40;
        } else {
            D_001D4CE8_00396488 = 0x10;
        }
    }
}
/* localdecomp:end func_0042F490 */
