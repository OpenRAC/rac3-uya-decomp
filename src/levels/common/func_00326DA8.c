#include "common.h"

/* localdecomp:start func_00326DA8 */
extern u8 *func_003252E8(void);
extern s32 func_00438850(s32 a0);
u8 func_00326DA8(s32 a0) {
    u8 *b = *(u8 **)(func_003252E8() + 104);
    u8 *p;
    b += 816;
    p = &b[a0];
    if (func_00438850(*p)) {
        *p = 255;
    }
    return *p;
}
/* localdecomp:end func_00326DA8 */
