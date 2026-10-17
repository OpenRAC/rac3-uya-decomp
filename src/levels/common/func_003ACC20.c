#include "common.h"

extern void func_00500118(s32, s32, s32);

void func_003ACC20(s32 arg0) {
    if (arg0) {
        func_00500118(0x4A000F, 1, 1);
        func_00500118(0x4A0010, 1, 1);
        func_00500118(0x4A000E, 1, 1);
    } else {
        func_00500118(0x4A000F, 1, 0);
        func_00500118(0x4A0010, 1, 0);
        func_00500118(0x4A000E, 1, 0);
    }
}
