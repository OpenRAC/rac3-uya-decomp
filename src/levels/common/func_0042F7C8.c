#include "common.h"

/* localdecomp:start func_0042F7C8 */
extern s32 D_00142438[];
extern u8 D_001D672C;

extern s32 D_00142438[];
extern s32 D_001D4CEC_003967C0;
extern s32 D_001D4CE8_003967C0;
extern u8 D_001D672C;
void func_0042F7C8(void) {
    s32 f;
    if (D_00142438[0] != 2) { D_001D4CE8_003967C0 = 4; return; }
    f = D_001D4CEC_003967C0;
    if (f & 0x20) {
        D_001D4CEC_003967C0 = f ^ 0x20;
        if (D_001D672C != 0) { D_001D4CE8_003967C0 = 0x1B; } else { D_001D4CE8_003967C0 = 0xE; }
        return;
    }
    if (f & 0x2000) { D_001D4CE8_003967C0 = 0x10; }
}
/* localdecomp:end func_0042F7C8 */
