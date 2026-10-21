#include "common.h"

/* localdecomp:start func_0045CD60 */
extern void func_0045CD60();

void func_0045CD60(s32 a, long l) {
    u8 *p = (u8 *)(s32)l;
    if (p == 0) return;
    *(s32 *)p = a;
    if (a != 0) {
        if (*(s16 *)(p + 0xA) == 1) *(s16 *)(p + 0xA) = 8;
    } else {
        *(s16 *)(p + 0xA) = 0;
    }
}
/* localdecomp:end func_0045CD60 */
