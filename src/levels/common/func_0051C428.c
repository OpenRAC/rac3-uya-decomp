#include "common.h"

/* localdecomp:start func_0051C428 */
extern void func_0051C428(u8 *p, s32 m, s32 on);

void func_0051C428(u8 *p, s32 m, s32 on) {
    if (on) *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) |= m;
    else *(u16 *)(*(u8 **)(p + 0x2C) + 0x48) &= ~m;
    p[0x30] = 0;
    *(s32 *)(p + 0x34) = 0;
}
/* localdecomp:end func_0051C428 */
