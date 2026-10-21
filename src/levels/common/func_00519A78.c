#include "common.h"

/* localdecomp:start func_00519A78 */
extern void func_00519A78(void *p, s32, s32);

void func_00519A78(void *p, s32 m, s32 set) {
    if (set != 0) {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) |= m;
    } else {
        *(*(u8 **)((u8 *)p + 0x2C) + 0x4C) &= ~m;
    }
}
/* localdecomp:end func_00519A78 */
