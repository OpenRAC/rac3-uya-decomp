#include "common.h"

extern s32 D_00143950[];
extern s32 D_001D5520;
extern void func_0012A950(void);
extern void func_0012BEE8(s32, s32, s32, s32);
void func_00411D38(void) {
    func_0012A950();
    if (D_00143950[0]) D_001D5520 = 0;
    if (D_001D5520) func_0012BEE8(0, 0, 0x50, 1);
    else func_0012BEE8(0, 1, D_00143950[0] ? 3 : 2, 0);
}
