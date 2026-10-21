#include "common.h"

/* localdecomp:start func_003154A8 */
extern u8 D_00271BC0[];
extern s32 D_001E17C0;
extern void func_0040BBD0(void *, s32);

void func_003154A8(void) {
    func_0040BBD0(D_00271BC0, 2048);
    D_001E17C0 = 0;
}
/* localdecomp:end func_003154A8 */
