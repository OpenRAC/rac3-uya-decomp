#include "common.h"

/* localdecomp:start func_0048D030 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_48D030;
extern S_48D030 D_00160C40[];
extern void *D_001D8DA4;
extern void *D_001D8DA8;
extern void *func_0047B6F8(s32);
extern void *func_00490968(s32);
extern s32 func_00490B98(void *, s32, s32, s32, s32);
void func_0048D030(void) {
    D_001D8DA4 = func_0047B6F8(0);
    D_001D8DA8 = func_0047B6F8(0);
    func_00490B98(func_00490968(1), (s32)D_001D8DA4, (s32)D_001D8DA8, D_00160C40->f4954, (s32)D_00160C40->f6F30);
}
/* localdecomp:end func_0048D030 */
