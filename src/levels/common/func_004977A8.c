#include "common.h"

/* localdecomp:start func_004977A8 */
extern s32 D_001DFC14;
extern s32 D_001D93AC;
extern s32 func_00513928(s32 a0);
extern u8 *func_00490968(s32 a0);
extern void func_0045CA60(s32 a0);
extern void func_0047B7B8(s32 a0);
void func_004977A8(void) {
    u8 *p;
    func_00513928(16);
    func_00513928(17);
    D_001DFC14 = 2;
    p = func_00490968(0);
    (*(void (**)(u8 *))(*(u8 **)(p + 4) + 12))(p);
    func_0045CA60(1);
    func_0047B7B8(D_001D93AC);
    func_0045CA60(1);
}
/* localdecomp:end func_004977A8 */
