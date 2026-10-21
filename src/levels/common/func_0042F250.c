#include "common.h"

/* localdecomp:start func_0042F250 */
extern s32 D_001D4CE8;
extern s32 (*D_001D7598)();
typedef struct { u8 pad0[0x16C]; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_0042F250;
extern S_0042F250 D_00142430[];

void func_0042F250(void) {
    if (D_001D7598 != 0) {
        D_001D7598();
        D_001D7598 = 0;
    }
    if (D_00142430->f16C == 0) {
        D_00142430->f17C = 1;
    }
    D_001D4CE8 = 1;
}
/* localdecomp:end func_0042F250 */
