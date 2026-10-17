#include "common.h"

extern void func_00449518();
extern s32 D_001DB02C;
extern s32 D_001A71A0[];

void func_004C6FD8(int a0, int a1) {
    if (D_001DB02C) {
        func_00449518(D_001A71A0[0], D_001DB02C, a1, a0);
    }
}
