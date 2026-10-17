#include "common.h"
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6D28 - 0x4958];
    u8 fX[1];
} S_func_0049A930;
extern S_func_0049A930 D_00160C40[];
extern void *D_001D950C;
extern void *D_001D9510;
extern void *func_0047B6F8(s32);
extern void *func_00490968(s32);
extern s32 func_00490B98(void *, s32, s32, s32, s32);
void func_0049A930(void) {
    D_001D950C = func_0047B6F8(1);
    D_001D9510 = func_0047B6F8(1);
    func_00490B98(func_00490968(0), (s32)D_001D950C, (s32)D_001D9510, D_00160C40->f4954, (s32)D_00160C40->fX);
}
