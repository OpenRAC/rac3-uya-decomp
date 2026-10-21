#include "common.h"

/* localdecomp:start func_003B3D00 */
extern u8 *D_001E0180[];
extern void func_004F12C0(u8 *, u8 *, s32, s32);
void func_003B3D00(s32 a0, s32 a1, s32 a2) {
    u8 *p = D_001E0180[0] + (a2 << 7);
    func_004F12C0(p + 48, p + 112, 0, 1);
}
/* localdecomp:end func_003B3D00 */
