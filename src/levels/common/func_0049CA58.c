#include "common.h"

/* localdecomp:start func_0049CA58 */
typedef struct { u8 pad[0x4954]; s32 f4954; u8 p4958[0x4B90 - 0x4958]; u8 f4B90[4]; } S_49CA58;
extern S_49CA58 D_00160C40;
extern s32 D_001D95C0;
extern s32 func_0047B6F8(s32);
extern void *func_00490968(s32);
extern void func_00490B98(void *, s32, s32, s32, void *);

void func_0049CA58(void) {
    D_001D95C0 = func_0047B6F8(0);
    func_00490B98(func_00490968(0), D_001D95C0, 0, D_00160C40.f4954, D_00160C40.f4B90);
}
/* localdecomp:end func_0049CA58 */
