#include "common.h"

/* localdecomp:start func_00663340 */
void func_00663340(u8 *p, s32 i) {
    u8 *e = p + i * 0x50;
    if (*(s32 *)(*(u8 **)(p + 0x2534) + 0x1A0) & *(s32 *)(e + 0x460)) {
        *(u8 *)(e + 0x458) = 1;
    } else {
        *(u8 *)(e + 0x458) = 0;
    }
}
/* localdecomp:end func_00663340 */
