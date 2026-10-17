#include "common.h"

typedef struct {
    u8 pad0[8];
    s16 x8;
    s16 xA;
    u16 *xC;
    s32 x10;
    u8 pad1[0x1C];
} S_1F1CC0;

extern S_1F1CC0 D_001F1CC0[];
extern void func_004AF4D8(u16 *, u16 *, s32);

void func_004223F0(void) {
    S_1F1CC0 *p = D_001F1CC0;
    s32 i;

    for (i = 0; i < 8; i++, p++) {
        if (p->x10 != 0 && p->xC != 0) {
            u16 *a = p->xC + p->x8;
            func_004AF4D8(a, a + p->xA, i);
            p->x8 = 0;
            p->xA = 0;
        }
    }
}
