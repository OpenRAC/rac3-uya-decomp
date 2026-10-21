#include "common.h"

/* localdecomp:start func_004908C8 */
void func_004908C8(void *p, s32 a) {
    void *q = *(void **)((u8 *)p + 0x4);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)q + 0x1C))(p, a, 0);
}
/* localdecomp:end func_004908C8 */
