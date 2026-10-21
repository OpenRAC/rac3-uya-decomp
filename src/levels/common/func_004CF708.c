#include "common.h"

/* localdecomp:start func_004CF708 */
extern s32 func_004CF708();

s32 func_004CF708(u8 *p) {
    switch (*(s32 *)(p + 4)) {
    case 4:
    case 2:
        return *(s32 *)(p + 0x50) >= *(s32 *)(p + 0x4C);
    case 3:
        return *(s32 *)(p + 0x50) >= 0x1000;
    default:
        return 1;
    }
}
/* localdecomp:end func_004CF708 */
