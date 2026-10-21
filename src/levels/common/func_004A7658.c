#include "common.h"

/* localdecomp:start func_004A7658 */
extern u8 D_001A30B0[];
s32 func_004A7658(u32 a0, s32 a1) {
    if (a0 < 0x34) {
        u8 *p = (u8 *)&D_001A30B0[0] + a0 * 0x80;
        *(s32 *)(p + 0xd4) = a1;
    }
    return 1;
}
/* localdecomp:end func_004A7658 */
