#include "common.h"

/* localdecomp:start func_0050DA68 */
typedef int Q_0050DA68 __attribute__((mode(TI)));
typedef struct {
    u8 pad[0x1B4C];
    float f;
    s32 i;
    u8 pad2[0x25C4 - 0x1B54];
    s32 st;
} G_0050DA68;
extern Q_0050DA68 D_001A6720;
extern void func_004FC518(s32, s32);
void func_0050DA68(Q_0050DA68 *v, s32 b, float x) {
    G_0050DA68 *g;
    D_001A6720 = *v;
    g = (G_0050DA68 *)((u8 *)&D_001A6720 - 0x1B40);
    g->f = x;
    g->i = b;
    if ((u32)(g->st - 0x66) >= 4) func_004FC518(0x66, 2);
}
/* localdecomp:end func_0050DA68 */
