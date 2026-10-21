#include "common.h"

/* localdecomp:start func_00501048 */
extern u8 D_001A4BE0[];
extern s32 D_001E2F10[];
extern void func_004FC518(s32 a0, s32 a1);

s32 func_00501048(void) {
    u8 *p = D_001A4BE0;
    if (*(s32 *)(p + 9676) != 17) {
        return 0;
    }
    if (!(*(f32 *)(p + 848) + 0.4f < *(f32 *)(p + 136))) {
        return 0;
    }
    D_001E2F10[0] = 0;
    func_004FC518(6, 1);
    return 1;
}
/* localdecomp:end func_00501048 */
