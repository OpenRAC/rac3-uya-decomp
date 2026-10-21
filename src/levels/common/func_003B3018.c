#include "common.h"

/* localdecomp:start func_003B3018 */
extern s32 D_001D545C[];

s32 func_003B3018(void *a, u8 *b) {
    if (D_001D545C[0] != 26) {
        return 0;
    }
    return *(s32 *)(b + 36) != 0;
}
/* localdecomp:end func_003B3018 */
