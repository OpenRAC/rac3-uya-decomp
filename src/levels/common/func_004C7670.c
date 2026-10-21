#include "common.h"

/* localdecomp:start func_004C7670 */
extern s32 D_001DB07C;
extern s32 D_001DFBC0[];
extern u8 *D_001DB02C;
extern u8 *D_001A4F3C[];
s32 func_004C7670(void) {
    u8 *p;
    if (D_001DB07C >= D_001DFBC0[0]) {
        p = D_001A4F3C[0];
        D_001DB02C = p;
        if (p) return *(s16 *)(p + 170);
        return 1;
    }
    D_001DB02C = 0;
    return 0;
}
/* localdecomp:end func_004C7670 */
