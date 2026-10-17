#include "common.h"
extern u8 D_002E74B8[];
extern u8 D_002E7748[];
extern s32 func_00432730();
extern s32 func_00432A20();
extern void func_00432F60();
void func_004302C0(u8 *arg) {
    s32 a, b, t, i;
    u8 *q;
    a = func_00432730(D_002E74B8);
    b = func_00432730(D_002E7748);
    t = *(s32 *)arg;
    if (t == a) {
        if (*(s32 *)(arg + 4) == b) {
            arg += 8;
            q = arg + t;
            func_00432A20(arg, q, 0, D_002E74B8);
            arg = q;
            for (i = 0; i < 0x25; i++) {
                func_00432A20(arg, arg + b, i, D_002E7748);
                arg += b;
            }
            func_00432F60();
        }
    }
}
