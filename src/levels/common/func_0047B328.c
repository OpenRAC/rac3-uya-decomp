#include "common.h"

/* localdecomp:start func_0047B328 */
extern s32 func_00511FE0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001E0688;
extern s32 D_001E0670[2];
extern void func_0047A6E0();
extern void func_0047AC50(void);
extern void func_0047AAD0();
extern s32 func_0047ACE8(void);
void *func_0047B328() {
    if (D_001E0688 == 0) {
        func_00511FE0(D_001E0670, (s32)func_0047A6E0, (s32)func_0047AC50, (s32)func_0047AAD0, (s32)func_0047ACE8, 0);
        D_001E0688 = 1;
    }
    return D_001E0670;
}
/* localdecomp:end func_0047B328 */
