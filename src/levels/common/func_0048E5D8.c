#include "common.h"

/* localdecomp:start func_0048E5D8 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6EC0 - 0x4958];
    u8 fX[1];
} S_func_0048E5D8;
extern S_func_0048E5D8 D_00160C40[];
extern void *D_001D8E48;
extern void *D_001D8E4C;
extern void *func_0047B6F8(s32);
extern void *func_00490968(s32);
extern s32 func_00490B98(void *, s32, s32, s32, s32);
void func_0048E5D8(void) {
    D_001D8E48 = func_0047B6F8(0);
    D_001D8E4C = func_0047B6F8(0);
    func_00490B98(func_00490968(0), (s32)D_001D8E48, (s32)D_001D8E4C, D_00160C40->f4954, (s32)D_00160C40->fX);
}
/* localdecomp:end func_0048E5D8 */
