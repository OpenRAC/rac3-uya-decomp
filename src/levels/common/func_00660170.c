#include "common.h"

extern void func_0058F0A0(void *, s32, s32);

void func_00660170(s32 *p) {
    p[2] = 0;
    p[1] = 0;
    p[0] = 0;
    func_0058F0A0(&p[3], 0xCDCDCDCD, 64);
    p[19] = 0;
    ((u8 *)p)[84] = 0;
    p[20] = -1;
    ((u8 *)p)[85] = 0;
}
