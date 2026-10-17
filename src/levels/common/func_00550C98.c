#include "common.h"

extern char D_00550D10[];
extern s32 func_00550FC8(u8 *);
extern s32 func_00551720(u8 *);
extern void func_005A8630(u8 *);
extern void func_005890F0(char *, u8 *);

void func_00550C98(u8 *a0) {
    s32 a = func_00550FC8(a0);
    s32 b = func_00551720(a0);
    if (a == 0 && b == 0) {
        if (a0[32] == 2) {
            func_005A8630(a0);
        }
    } else {
        func_005890F0(D_00550D10, a0);
    }
}
