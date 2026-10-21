#include "common.h"

/* localdecomp:start func_004DE900 */
extern s32 D_001D545C;
extern s32 func_005103E8(s32);

s32 func_004DE900(void) {
    s32 r = 0;

    switch (D_001D545C) {
    case 9:
        r = func_005103E8(4) != 0;
        break;
    case 19:
        if (func_005103E8(1) || func_005103E8(2)) {
            r = 1;
        }
        break;
    }
    return r;
}
/* localdecomp:end func_004DE900 */
