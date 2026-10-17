#include "common.h"

extern s32 D_001EA8C0[];
extern void func_0040BBA8();

extern s32 func_003FEE38();
extern void func_0040BBA8();
extern s32 D_001DFC14;
extern s32 D_001EA8C0[];

void func_003FF920(void) {
    if (D_001DFC14 == 0) {
        func_0040BBA8(D_001EA8C0, -1, 0x80);
    } else if (D_001DFC14 == 2) {
        func_003FEE38();
    }
}
