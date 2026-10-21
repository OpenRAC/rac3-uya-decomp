#include "common.h"

/* localdecomp:start func_004D4A10 */
extern s32 func_004D4960(s32, s32, s32);
extern u8 D_001D558C[];
void func_004D4A10(void) {
    if (func_004D4960(0x1C, 8, 0)) return;
    if (func_004D4960(8, 8, 0)) return;
    if (func_004D4960(8, 0x1B, 0)) return;
    if (func_004D4960(8, 0x1C, 0)) return;
    if (func_004D4960(-1, 8, 0x11)) return;
    if (D_001D558C[0] != 0) func_004D4960(8, -1, 0x12);
}
/* localdecomp:end func_004D4A10 */
