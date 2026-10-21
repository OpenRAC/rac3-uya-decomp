#include "common.h"

/* localdecomp:start func_004C9050 */
extern s32 func_004C9A70(u8 *, s32);
void func_004C9050(u8 *p, u8 *a, s32 b) {
    *(s32 *)(p + 0x34) = func_004C9A70(a, b);
}
/* localdecomp:end func_004C9050 */
