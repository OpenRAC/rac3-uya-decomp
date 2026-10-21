#include "common.h"

/* localdecomp:start func_004759F0 */
extern u8 D_001D8058;
extern void func_00512AB0(s32, s32, s32);
s32 func_004759F0(void) {
    if (D_001D8058 != 0) {
        func_00512AB0(0x10000, 1, 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_004759F0 */
