#include "common.h"

/* localdecomp:start func_0042FD78 */
extern s32 D_00142438[];

typedef struct { u32 b0:5; u32 f5:1; u32 b6:7; u32 f13:1; u32 rest:18; } S_396D70;
extern s32 D_00142438[];
extern s32 D_001D4CE8_00396D70;
extern union { s32 i; S_396D70 b; } D_001D4CEC_00396D70;
void func_0042FD78(void) {
    if (D_00142438[0] != 2) { D_001D4CE8_00396D70 = 4; return; }
    if (D_001D4CEC_00396D70.i & 0x2020) {
        D_001D4CE8_00396D70 = 7;
        D_001D4CEC_00396D70.b.f5 = 0;
        D_001D4CEC_00396D70.b.f13 = 0;
    }
}
/* localdecomp:end func_0042FD78 */
