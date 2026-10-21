#include "common.h"

/* localdecomp:start func_00363008 */
extern s32 D_001DD7D0;
extern s32 D_0028F1E0[];

s32 func_00363008(void) {
    s32 i;
    for (i = 0; i < D_001DD7D0; i++) {
        if (D_0028F1E0[i] != 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_00363008 */
