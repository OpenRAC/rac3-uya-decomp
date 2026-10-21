#include "common.h"

/* localdecomp:start func_003D0910 */
extern s32 D_001DF360;
extern s32 D_001A4E18[];
extern void func_0044F2E8(s32, s32, s32, s32, s32, s32, s32);

void func_003D0910(void) {
    D_001A4E18[0] = D_001DF360;
    func_0044F2E8(0, 5, 0, 1, 0, 0, 0);
}
/* localdecomp:end func_003D0910 */
