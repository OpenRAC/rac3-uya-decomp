#include "common.h"
extern u8 D_001A4C60[];
extern s32 func_00453210(void *, s32);
extern s32 func_0050DAC0(void);
s32 func_00326340(s32 a0, u8 *a1) {
    if (func_00453210(D_001A4C60, *(s32 *)(a1 + 36)) != 0) {
        if (*(s32 *)(D_001A4C60 + 9540) != 176) {
            return func_0050DAC0() == 0;
        }
    }
    return 0;
}
