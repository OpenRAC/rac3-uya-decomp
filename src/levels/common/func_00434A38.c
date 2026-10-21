#include "common.h"

/* localdecomp:start func_00434A38 */
extern u8 *D_002E9A30[];

u8 *func_00434A38(u32 a0, s32 a1) {
    u8 *r = 0;
    if (a0 < 96) {
        r = D_002E9A30[a0] + a1 * 48;
    }
    return r;
}
/* localdecomp:end func_00434A38 */
