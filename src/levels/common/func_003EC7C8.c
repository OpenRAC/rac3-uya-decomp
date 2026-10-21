#include "common.h"

/* localdecomp:start func_003EC7C8 */
extern u8 D_001E2AC0[];
extern s32 D_001D6694;
extern s32 D_001A4E18[];
s32 func_003EC7C8(u8 *a0, u8 *a1) {
    u8 *e = D_001E2AC0 + *(s32 *)(a0 + 148) * 1120;
    u8 *p = e + 336;
    if (D_001D6694 == 0) {
        if (*(s32 *)(p + 252) == 32 && *(s16 *)(a1 + 134) == 0 && D_001A4E18[0] <= 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003EC7C8 */
