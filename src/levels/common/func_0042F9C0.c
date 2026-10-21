#include "common.h"

typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x148 - 0x1A]; s32 x148; u8 pad3[0x10]; s32 x15C; s32 pad4; s32 x164; } S_3969B8;
extern S_3969B8 D_00142430_003969B8[];
extern void (*D_001D7594)(void);
extern u16 D_001D75A0;
/* gcc treats an .sdata symbol as small and emits a bare reference; the
   assembler, knowing no size, expands it with lui $at as retail does. */
extern s32 D_001D4CE8[] __attribute__((section(".sdata")));
void func_0042F9C0(void) {
    S_3969B8 *p = D_00142430_003969B8;
    if (p->x15C == 2 && p->x164 < 0) {
        if (D_001D7594) {
            D_001D7594();
            D_001D7594 = 0;
        }
        p->h18 = D_001D75A0;
        p->x148 = 0;
        D_001D4CE8[0] = 0x17;
    }
}
