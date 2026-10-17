#include "common.h"

extern s32 func_00478B18(s32);
extern s32 func_00512028(s32);
extern void func_00512AB0(s32, s32, s32);
extern s32 D_001D80C8;
extern u8 D_001D80CC;

void func_004789D0(s32 a) {
    if (func_00512028(func_00478B18(0)) == 1) {
        D_001D80C8 = a;
        D_001D80CC = 0;
        func_00512AB0(0x20000, 1, a != 0);
    }
}
