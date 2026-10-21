#include "common.h"

/* localdecomp:start func_004D1FB8 */
extern void func_004D1FB8();

void func_004D1FB8(void *p) {
    *(volatile s32 *)((u8 *)p + 0xC) = 0;
    *(volatile s32 *)((u8 *)p + 0x8) = 0;
}
/* localdecomp:end func_004D1FB8 */
