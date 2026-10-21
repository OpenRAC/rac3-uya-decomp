#include "common.h"

typedef struct { u8 pad[0x10]; s32 x10; u8 padA[0x134]; s32 x148; } S_a;
extern void func_00430258(void);
/* Retail reaches the 16-byte .sdata declarations through lui (gcc treats
   them as small, the assembler sees 16 bytes) and the rest through $gp. */
extern s32 D_001D758C;
extern s32 D_001D7590_00396F18;
extern s32 D_001D75A0_00396F18;
extern s32 D_001D7594_00396F18;
extern s32 D_001D7598_00396F18;
extern s32 D_001D759C_00396F18;
extern s8 D_001DFF98;
extern s32 D_001D4CEC_00396F18[4] __attribute__((section(".sdata")));
extern s8 D_001DFFA0[16] __attribute__((section(".sdata")));
extern S_a D_00142430_00396F18[];
void func_0042FF20(s32 arg0, s32 arg1, s32 arg2) {
    S_a *p = D_00142430_00396F18;
    D_001D758C = arg0;
    D_001D7590_00396F18 = arg2;
    D_001D75A0_00396F18 = arg1;
    p->x148 = 0;
    D_001D7594_00396F18 = 0;
    D_001D7598_00396F18 = 0;
    D_001D759C_00396F18 = 0;
    D_001DFFA0[0] = 0;
    D_001DFF98 = 0;
    func_00430258();
    p->x10 = 0;
    D_001D4CEC_00396F18[0] &= ~4; D_001D4CEC_00396F18[0] |= 2; D_001D4CEC_00396F18[0] &= ~0x40; D_001D4CEC_00396F18[0] &= ~0x10; D_001D4CEC_00396F18[0] &= ~0x4000;
}
