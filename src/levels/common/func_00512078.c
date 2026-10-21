#include "common.h"

/* localdecomp:start func_00512078 */
extern s32 func_00512028(s32);
extern void func_00512030(s32, s32);
s32 func_00512078(s32 a0) {
    if (func_00512028(a0) != 2) return 0;
    func_00512030(a0, 1);
    return 1;
}
/* localdecomp:end func_00512078 */
