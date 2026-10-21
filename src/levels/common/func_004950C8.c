#include "common.h"

/* localdecomp:start func_004950C8 */
s32 func_004950C8(void *p, s32 x, s32 y) {
    y += 0x4F0000;
    return x * (*(s32 *)((u8 *)p + 0x14) * *(s32 *)((u8 *)p + 0x10)) + y;
}
/* localdecomp:end func_004950C8 */
