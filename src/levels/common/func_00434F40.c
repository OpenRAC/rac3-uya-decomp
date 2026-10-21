#include "common.h"

/* localdecomp:start func_00434F40 */
extern u16 D_001A8E74[];
extern u8 D_00142CBF[];
s32 func_00434F40(void) {
    if (D_001A8E74[0] != 0) {
        return D_00142CBF[0] == 0;
    }
    return 0;
}
/* localdecomp:end func_00434F40 */
