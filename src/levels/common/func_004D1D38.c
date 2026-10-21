#include "common.h"

/* localdecomp:start func_004D1D38 */
extern s32 func_004D1D38();

extern void func_0011AF48(void *, s32);
extern u8 D_001DB8D8[];
 
s32 func_004D1D38(s32 a0, void *p) {
    func_0011AF48(D_001DB8D8, *(s32 *)((u8 *)p + 0x4));
    return 1;
}
/* localdecomp:end func_004D1D38 */
