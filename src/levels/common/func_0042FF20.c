#include "common.h"

/* localdecomp:start func_0042FF20 */
typedef struct { u8 pad[0x10]; s32 x10; u8 padA[0x134]; s32 x148; } S_a;
extern void func_00430258(void);
extern s32 D_001D758C;
extern s32 D_001D7590;
extern s32 D_001D75A0;
extern s32 D_001D7594;
extern s32 D_001D7598;
extern s32 D_001D759C;
extern s8 D_001DFF98;
extern s32 D_001D4CEC;
extern s8 D_001DFFA0;
extern S_a D_00142430_00396F18[];
void func_0042FF20(s32 arg0, s32 arg1, s32 arg2) {
    S_a *p = D_00142430_00396F18;
    D_001D758C = arg0;
    D_001D7590 = arg2;
    D_001D75A0 = arg1;
    p->x148 = 0;
    D_001D7594 = 0;
    D_001D7598 = 0;
    D_001D759C = 0;
    D_001DFFA0 = 0;
    D_001DFF98 = 0;
    func_00430258();
    p->x10 = 0;
    D_001D4CEC &= ~4; D_001D4CEC |= 2; D_001D4CEC &= ~0x40; D_001D4CEC &= ~0x10; D_001D4CEC &= ~0x4000;
}
/* localdecomp:end func_0042FF20 */
