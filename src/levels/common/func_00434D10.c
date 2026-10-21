#include "common.h"

/* localdecomp:start func_00434D10 */
extern u8 D_00142734[];

s32 func_00434D10(s32 k) {
    if ((u32)(k - 0x1F) < 5) {
        k -= 0x1E;
        if ((u32)k < 8) {
            return (D_00142734[0] >> k) & 1;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_00434D10 */
