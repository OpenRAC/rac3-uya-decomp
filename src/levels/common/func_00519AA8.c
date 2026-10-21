#include "common.h"

/* localdecomp:start func_00519AA8 */
s32 func_00519AA8(void *a0, s32 a1) {
    void *p = *(void **)((u8 *)a0 + 0x2c);
    return (*(u8 *)((u8 *)p + 0x4c) & a1) != 0;
}
/* localdecomp:end func_00519AA8 */
