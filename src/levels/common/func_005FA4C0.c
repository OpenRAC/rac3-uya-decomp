#include "common.h"

extern u32 D_0024145C;
extern s32 D_0049A740[];
extern s32 D_00242AA0;
extern s32 D_001E1348;
extern s32 D_0024CBD8;
extern void func_005FA530(void);

void func_005FA4C0(void) {
    u32 m = D_0024145C;
    u32 k = m;
    if (m >= 37) {
        m = 0;
    }
    D_00242AA0 = 0x1E000;
    D_001E1348 = D_0049A740[m];
    if (k - 39 < 21) {
        D_0024CBD8 = 0x120000;
    }
    func_005FA530();
}
