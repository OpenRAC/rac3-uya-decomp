#include "common.h"

extern s32 func_00494440(s32, s32);
extern void func_004945A8(s32);

void func_0032EF30(s32 a0) {
    s32 i;

    for (i = 0; i < 52; i++) {
        if (func_00494440(a0, i)) func_004945A8(i);
    }
}
