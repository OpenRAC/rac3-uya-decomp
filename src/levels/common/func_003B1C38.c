#include "common.h"

/* localdecomp:start func_003B1C38 */
extern u8 *D_001E009C[];

u8 *func_003B1C38(u8 *a0) {
    return D_001E009C[0] + (**(s32 **)(a0 + 104) << 8);
}
/* localdecomp:end func_003B1C38 */
