#include "common.h"

/* localdecomp:start func_003C15A8 */
extern s32 D_001E2280[];
s32 func_003C15A8(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_001E2280[i] == 0) return 1;
    }
    return 0;
}
/* localdecomp:end func_003C15A8 */
