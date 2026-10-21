#include "common.h"

/* localdecomp:start func_004A7CB0 */
extern void func_004A7CB0(void);

typedef struct { u8 x0; s8 x1; s8 x2; s8 x3; u16 x4; u16 x6; s32 x8; s32 xC; u32 x10; s32 x14; s32 x18; u8 pad[0x60-0x1C]; } S_3A0200;
extern S_3A0200 D_0023A870[];
void func_004A7CB0(void) {
    s32 i;
    for (i = 0; i < 12; i++) {
        S_3A0200 *p = &D_0023A870[i];
        p->x0 = 0;
        p->x1 = -1;
        p->x2 = -1;
        p->x3 = -1;
        p->xC = 0;
        p->x8 = 0;
        p->x4 = 0xFFFF;
        p->x10 = 0xFFFFFFFF;
        p->x14 = 0;
        p->x18 = -1;
    }
}
/* localdecomp:end func_004A7CB0 */
