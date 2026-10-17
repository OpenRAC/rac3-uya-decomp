#include "common.h"
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x7058 - 0x4958];
    u8 fX[1];
} S_func_00498868;
extern S_func_00498868 D_00160C40[];
extern void *D_001D9440;
extern void *D_001D9444;
extern void *func_0047B6F8(s32);
extern void *func_00490968(s32);
extern s32 func_00490B98(void *, s32, s32, s32, s32);
void func_00498868(void) {
    D_001D9440 = func_0047B6F8(0);
    D_001D9444 = func_0047B6F8(0);
    func_00490B98(func_00490968(0), (s32)D_001D9440, (s32)D_001D9444, D_00160C40->f4954, (s32)D_00160C40->fX);
}
