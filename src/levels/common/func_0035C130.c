#include "common.h"

extern u8 D_001A30B0[];
extern void func_0049FCB0(s32);
extern void func_00439E10(u8 *, s32, s32);
extern void func_0042F160(u8 *);

void func_0035C130(u8 *arg0)
{
    u8 *v;
    s32 i;
    u8 *e;

    v = *(u8 **)(arg0 + 104);
    i = *(s32 *)(v + 748);
    if (i != -1) {
        e = D_001A30B0 + (i << 7);
        if (*(u8 **)(e + 220) == arg0 && e[208] != 0) {
            func_0049FCB0(i);
        }
    }
    *(s32 *)(v + 748) = -1;
    func_00439E10(arg0, 0, 3);
    func_0042F160(arg0);
}
