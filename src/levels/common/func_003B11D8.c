#include "common.h"

/* localdecomp:start func_003B11D8 */
extern u8 *D_001E0180[];
extern void func_004F12C0(u8 *, u8 *, s32, s32);
extern void func_003EC710(s32);

void func_003B11D8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 *p = D_001E0180[0] + (*(s32 *)(v + 16) << 7);
    func_004F12C0(p + 48, p + 112, 0, 1);
    if (*(s32 *)(v + 20) != -1) {
        func_003EC710(*(s32 *)(v + 20));
    }
}
/* localdecomp:end func_003B11D8 */
