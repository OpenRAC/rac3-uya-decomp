#include "common.h"

/* localdecomp:start func_00495108 */
extern u8 *func_004950A8(u8 *a0, s32 a1, s32 a2);
void func_00495108(u8 *a0, s32 a1, s32 a2) {
    s32 i;
    for (i = 0; i < *(s32 *)(a0 + 20); i++) {
        *(s32 *)(func_004950A8(a0, i, a1) + 64) = a2;
    }
}
/* localdecomp:end func_00495108 */
