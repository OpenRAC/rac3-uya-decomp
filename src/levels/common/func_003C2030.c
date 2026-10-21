#include "common.h"

/* localdecomp:start func_003C2030 */
extern s32 D_001E2290[];
s32 func_003C2030(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (D_001E2290[i] == 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_003C2030 */
