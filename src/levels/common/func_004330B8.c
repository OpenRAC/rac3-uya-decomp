#include "common.h"

/* localdecomp:start func_004330B8 */
extern s32 D_001D67C8;

extern void func_004CE7B0(void *, s32);
void func_004330B8(void) {
    s32 i;
    if (D_001D67C8 != 0) {
        for (i = 0; i < 1; i++) {
            func_004CE7B0((void *)(D_001D67C8 + 0x1FCA8), i);
        }
    }
}
/* localdecomp:end func_004330B8 */
