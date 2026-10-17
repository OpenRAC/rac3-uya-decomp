#include "common.h"

extern void func_003ACDE0(u8 *);
extern void func_003ACD60(u8 *);
extern void func_00422428(u8 *, s32, s32);

void func_003ACC28(u8 *arg0)
{
    u8 *v = *(u8 **)(arg0 + 104);

    if (*(s32 *)(v + 908) != -1) {
        func_003ACDE0(arg0);
        func_00422428(arg0, 23, -1);
    } else if (*(s32 *)(v + 916) != -1) {
        func_003ACDE0(arg0);
        func_00422428(arg0, 21, -1);
    } else {
        func_003ACD60(arg0);
        func_00422428(arg0, 22, -1);
    }
}
