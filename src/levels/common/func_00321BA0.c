#include "common.h"

/* localdecomp:start func_00321BA0 */
extern s32 D_001E1838[];
s32 func_00321BA0(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 7; i++) {
        if (D_001E1838[i]) n++;
    }
    return n;
}
/* localdecomp:end func_00321BA0 */
