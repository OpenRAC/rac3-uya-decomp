#include "common.h"

/* localdecomp:start func_0042FE88 */
typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x148 - 0x14]; s32 f148; } S_396E80;
extern S_396E80 D_00142430_00396E80[];
extern s32 D_001D758C;
extern s32 D_001D7590;
extern s32 D_001D7594;
extern s32 D_001D7598;
extern s32 D_001D759C;
extern s8 D_001DFF98;
extern s32 D_001D4CEC;
extern s8 D_001DFFA0;
extern s32 func_00430060();
extern void func_00430258(void);
s32 func_0042FE88(s32 a, s32 b) {
    s32 r = func_00430060(a);
    if (r) {
        S_396E80 *p = D_00142430_00396E80;
        s32 f = D_001D4CEC;
        f |= 0x10;
        f &= ~4;
        f &= ~2;
        f &= ~0x40;
        D_001D759C = b;
        p->f148 = 0;
        D_001D4CEC = f;
        p->f10 = 0;
        D_001D758C = 0;
        D_001D7590 = 0;
        D_001D7594 = 0;
        D_001D7598 = 0;
        D_001DFFA0 = 0;
        D_001DFF98 = 0;
        func_00430258();
    }
    return r;
}
/* localdecomp:end func_0042FE88 */
