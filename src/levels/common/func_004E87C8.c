#include "common.h"

/* localdecomp:start func_004E87C8 */
extern u8 D_001A4BE0[];
extern s32 func_0050DAC0(void);
s32 func_004E87C8(void) {
    u8 *p;
    u32 v;
    if (func_0050DAC0() != 0) {
        return 0;
    }
    p = D_001A4BE0;
    if (p[9700] != 0) {
        return 0;
    }
    v = *(u32 *)(p + 9676);
    if (v < 3 || v == 4) {
        if (*(s16 *)(p + 872) != 0) {
            return 0;
        }
        return p[5238] == 0;
    }
    return 0;
}
/* localdecomp:end func_004E87C8 */
