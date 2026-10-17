#include "common.h"

extern s32 D_001D8720[2];
extern u8 D_00142CA0[];
extern s32 func_00483C98(s32);
extern void func_00512AB0(s32, s32, s32);

void func_00483FE0(void)
{
    s32 i;
    s32 *p = D_001D8720;

    for (i = 0; i < 9; i++) {
        s32 r = func_00483C98(i);
        if (D_00142CA0[*p++]) {
            func_00512AB0(r, 1, 1);
        } else {
            func_00512AB0(r, 1, 0);
        }
    }
}
