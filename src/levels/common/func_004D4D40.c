#include "common.h"

/* localdecomp:start func_004D4D40 */
extern s16 D_0016C5A2[];
extern s32 func_0040BA90(s32 *);
void func_004D48B0(s16, s32, s32, s32);
extern u8 D_001E1370_003B8EF8;

s32 func_004D4D40(void) {
    s32 temp_s0;

    temp_s0 = func_0040BA90(&D_001E1370_003B8EF8) != 0;
    func_004D48B0(D_0016C5A2[0], 0x12C, 0xF, 0xF);
    return temp_s0;
}
/* localdecomp:end func_004D4D40 */
