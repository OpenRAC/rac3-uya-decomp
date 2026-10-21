#include "common.h"

/* localdecomp:start func_003270D8 */
extern u8 *func_003252E8(void);

s32 func_003270D8(void) {
    return ~*(s32 *)(*(u8 **)(func_003252E8() + 104) + 20) != 0;
}
/* localdecomp:end func_003270D8 */
