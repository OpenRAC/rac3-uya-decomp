#include "common.h"

/* localdecomp:start func_0048F7E8 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F08 - 0x4958];
    u8 f6F08[1];
} S_48F7E8;
extern S_48F7E8 D_00160C40[];
extern void *D_001D8EA0;
extern void *D_001D8EA4;
extern void *func_0047B6F8(s32);
extern void *func_00490968(s32);
extern s32 func_00490B98(void *, s32, s32, s32, s32);

void func_0048F7E8(void) {
    D_001D8EA0 = func_0047B6F8(0);
    D_001D8EA4 = func_0047B6F8(0);
    func_00490B98(func_00490968(0), (s32)D_001D8EA0, (s32)D_001D8EA4, D_00160C40->f4954, (s32)D_00160C40->f6F08);
}
/* localdecomp:end func_0048F7E8 */
