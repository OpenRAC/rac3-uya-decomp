#include "common.h"

/* localdecomp:start func_00434E00 */
extern s32 D_001D7B58[2];
extern u8 D_00142CA0[];
extern u32 D_00142C34[];
extern s32 func_00434EA0();
extern s32 func_004175C8(s32, s32);
s32 func_00434E00(void) {
    s32 i;
    s32 *p;
    if ((D_00142C34[0] & 0x200000) == 0) return 0;
    if (func_00434EA0()) return 1;
    i = 0;
    p = D_001D7B58;
    for (; i < 5; i++, p++) {
        if (func_004175C8(*p, -1) && D_00142CA0[*p] == 0) return 1;
    }
    return 0;
}
/* localdecomp:end func_00434E00 */
