#include "common.h"

/* localdecomp:start func_003C8D98 */
extern s32 func_00335908(s32);
extern void func_003C8E40(s32, s32);

s32 func_003C8D98(s32 arg) {
    s32 r = func_00335908(arg);
    func_003C8E40(r, arg);
    return r;
}
/* localdecomp:end func_003C8D98 */
