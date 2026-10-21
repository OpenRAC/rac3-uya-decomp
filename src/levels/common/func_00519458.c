#include "common.h"

/* localdecomp:start func_00519458 */
extern void func_00519458();

void func_00519458(void *p, s32 *a, s32 *b) {
    *a = (*(u32 *)((u8 *)p + 0xC) >> 9) & 3;
    *b = (*(u32 *)((u8 *)p + 0xC) >> 11) & 3;
}
/* localdecomp:end func_00519458 */
