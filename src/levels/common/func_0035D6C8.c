#include "common.h"

/* localdecomp:start func_0035D6C8 */
extern s32 D_001E1AF0[];
s32 func_0035D6C8(void) {
    s32 i;
    for (i = 0; i < 12; i++) {
        if (D_001E1AF0[i] == 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_0035D6C8 */
