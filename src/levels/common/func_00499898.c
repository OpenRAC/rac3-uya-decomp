#include "common.h"

/* localdecomp:start func_00499898 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F78 - 0x4958];
    u8 f6F78[1];
} S_499898;
extern S_499898 D_00160C40[];
extern void *D_001D94AC;
extern void *D_001D94B0;
extern void *func_0047B6F8(s32);
extern void *func_00490968(s32);
extern s32 func_00490B98(void *, s32, s32, s32, s32);
void func_00499898(void) {
    D_001D94AC = func_0047B6F8(0);
    D_001D94B0 = func_0047B6F8(0);
    func_00490B98(func_00490968(1), (s32)D_001D94AC, (s32)D_001D94B0, D_00160C40->f4954, (s32)D_00160C40->f6F78);
}
/* localdecomp:end func_00499898 */
