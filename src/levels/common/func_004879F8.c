#include "common.h"

/* localdecomp:start func_004879F8 */
extern s32 func_0047B6F8(s32);
extern s32 func_00490968(s32);
extern void func_00490B98(s32, s32, s32, s32, s32 *);
extern s32 D_001D8A70;
extern s32 D_001D8A74;
extern s32 D_001D8A78;
extern s32 D_001D8A7C;
extern s32 D_001D8A80;
extern s32 D_001D8A84;
extern s32 D_00160C40[];
void func_004879F8(void) {
    D_001D8A70 = func_0047B6F8(1);
    D_001D8A74 = func_0047B6F8(1);
    D_001D8A78 = func_0047B6F8(0);
    D_001D8A7C = D_001D8A78 + 0x9600;
    D_001D8A80 = func_0047B6F8(0);
    D_001D8A84 = D_001D8A80 + 0x9600;
    func_00490B98(func_00490968(0), D_001D8A70, D_001D8A74, D_00160C40[0x4954 / 4], &D_00160C40[0x6C68 / 4]);
    func_00490B98(func_00490968(1), D_001D8A78, D_001D8A7C, D_00160C40[0x4954 / 4], &D_00160C40[0x6C78 / 4]);
    func_00490B98(func_00490968(2), D_001D8A80, D_001D8A84, D_00160C40[0x4954 / 4], &D_00160C40[0x7080 / 4]);
}
/* localdecomp:end func_004879F8 */
