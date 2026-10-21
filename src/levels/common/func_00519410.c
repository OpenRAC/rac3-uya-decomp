#include "common.h"

/* localdecomp:start func_00519410 */
extern s32 func_00519410();

s32 func_00519410(void *p, s32 mask) {
    return (*(s32 *)((u8 *)p + 0xC) & mask) != 0;
}
/* localdecomp:end func_00519410 */
