#include "common.h"

/* localdecomp:start func_0049E448 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x7070 - 0x4958];
    u8 f7070[1];
} S_49E448;
extern S_49E448 D_00160C40[];
extern void *D_001D9694;
extern void *D_001D9698;
extern void *func_0047B6F8(s32);
extern void *func_00490968(s32);
extern s32 func_00490B98(void *, s32, s32, s32, s32);
void func_0049E448(void) {
    D_001D9694 = func_0047B6F8(0);
    D_001D9698 = func_0047B6F8(0);
    func_00490B98(func_00490968(0), (s32)D_001D9694, (s32)D_001D9698, D_00160C40->f4954, (s32)D_00160C40->f7070);
}
/* localdecomp:end func_0049E448 */
