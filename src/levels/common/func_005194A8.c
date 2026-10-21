#include "common.h"

/* localdecomp:start func_005194A8 */
extern void func_005194A8(void *, f32, f32);

void func_005194A8(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x18) = x;
    *(f32 *)((u8 *)p + 0x1C) = y;
}
/* localdecomp:end func_005194A8 */
