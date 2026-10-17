#include "common.h"

extern s32 D_001D7D28;
extern s32 D_001D7D2C;
extern s16 D_0022582E[];
extern s32 func_005B24C8(s32 a0, s32 a1);
extern void func_005BFD58(s32 a0, s32 a1);
extern void func_005BFA78(s32 a0, s32 a1, s32 a2);

void func_005BFA18(s32 a0, s32 a1) {
    s32 x;
    D_001D7D28 = a0;
    D_001D7D2C = a1 - a0 + 1;
    x = func_005B24C8(a0, a1) * 2;
    if (D_0022582E[0] == 4) {
        func_005BFD58(x, -1);
    } else {
        func_005BFA78(x, 1, 1024);
    }
}
