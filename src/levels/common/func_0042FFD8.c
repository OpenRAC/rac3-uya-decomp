#include "common.h"

typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x148 - 0x14]; s32 f148; } S_0042FFD8;
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_0042FFD8;
extern S_0042FFD8 D_00142430[];
extern s32 D_001D7594;
extern s32 D_001D7598;
extern s32 D_001D75A0;
extern s32 D_001D758C;
extern s32 D_001D7590;
extern s32 D_001D759C;
extern s8 D_001DFFA0;
extern F_0042FFD8 D_001D4CEC[4] __attribute__((section(".sdata")));
extern s8 D_001DFF98[16] __attribute__((section(".sdata")));
extern void func_00430258(void);

void func_0042FFD8(s32 a, s32 b, s32 c) {
    S_0042FFD8 *p = D_00142430;
    D_001D7594 = a;
    D_001D7598 = c;
    p->f148 = 0;
    p->f10 = 0;
    D_001D75A0 = b;
    D_001D758C = 0;
    D_001D7590 = 0;
    D_001D759C = 0;
    D_001DFFA0 = 0;
    func_00430258();
    D_001DFF98[0] = 1;
    D_001D4CEC[0].b2 = 1;
    D_001D4CEC[0].b1 = 0;
    D_001D4CEC[0].b6 = 0;
    D_001D4CEC[0].b4 = 0;
    D_001D4CEC[0].b14 = 0;
}
