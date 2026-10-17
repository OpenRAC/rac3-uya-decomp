#include "common.h"

typedef struct { u8 pad0[0x10]; s32 x10; u8 pad[0x15C-0x14]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396628;
extern S_396628 D_00142430_00396628[];
extern s32 D_001D4CEC_00396628;
extern s32 D_001D4CE8_00396628;
void func_0042F630(void) {
    S_396628 *p = D_00142430_00396628;
    if (p->x15C == 2 && p->x164 < 0) {
        p->x164 = 7;
        p->x10 = 0;
        p->x168 = 0;
        D_001D4CEC_00396628 &= ~0x800;
        D_001D4CE8_00396628 = 0x20;
    }
}
