#include "common.h"

/* localdecomp:start func_00572430 */
extern s32 D_001E03B4;
extern s32 D_002412A8;
extern u8 D_0024DF80[];

s32 func_00572430(u8 *a, u8 *b) {
    u8 *e = D_0024DF80 + *(s32 *)(a + 0x94) * 0x460;
    u8 *f = e + 0x150;

    if (D_002412A8 == 0 && *(s32 *)(f + 0xFC) == 0x20 && *(s16 *)(b + 0x86) == 0) {
        if (D_001E03B4 < 2) {
            *(s32 *)(e + 0x458) = 1;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00572430 */
