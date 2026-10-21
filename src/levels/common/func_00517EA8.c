#include "common.h"

/* localdecomp:start func_00517EA8 */
extern s32 func_00517EA8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_0051ABA0();

extern void func_0051ABA0(void *, s32, s32, s32, s32);
extern s32 D_001DC1F0_003E7028;
s32 func_00517EA8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x10))(arg0, D_001DC1F0_003E7028) != 0) {
        func_0051ABA0(arg0, arg1, arg2, arg3, arg4);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_00517EA8 */
