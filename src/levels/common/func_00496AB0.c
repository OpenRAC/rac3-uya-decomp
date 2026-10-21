#include "common.h"

/* localdecomp:start func_00496AB0 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x5628 - 0x4958];
    u8 fX[1];
} S_func_00496AB0;
extern S_func_00496AB0 D_00160C40[];
extern void *D_001D9310;
extern void *D_001D9314;
extern void *func_0047B6F8(s32);
extern void *func_00490968(s32);
extern s32 func_00490B98(void *, s32, s32, s32, s32);
void func_00496AB0(void) {
    D_001D9310 = func_0047B6F8(0);
    D_001D9314 = func_0047B6F8(0);
    func_00490B98(func_00490968(0), (s32)D_001D9310, (s32)D_001D9314, D_00160C40->f4954, (s32)D_00160C40->fX);
}
/* localdecomp:end func_00496AB0 */
