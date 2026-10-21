#include "common.h"

/* localdecomp:start func_00438488 */
typedef s32 (*Fn438488)(s32, s32, void *);
extern u8 *func_0045B118(s32);

s32 func_00438488(s32 a0, s32 a1) {
    s32 buf[4];
    u8 *p;
    p = func_0045B118(a0);
    if (p == 0) {
        return 0;
    }
    if (*(Fn438488 *)(p + 24) == 0) {
        return 0;
    }
    return (*(Fn438488 *)(p + 24))(a0, a1, buf);
}
/* localdecomp:end func_00438488 */
