#include "common.h"

/* localdecomp:start func_004D1998 */
s32 func_004D1998(void *a0, s32 a1) {
    s32 old = *(s32 *)((u8 *)a0 + 168);
    *(s32 *)((u8 *)a0 + 168) = a1;
    return old;
}
/* localdecomp:end func_004D1998 */
