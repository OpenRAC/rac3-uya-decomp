#include "common.h"

extern void func_00500118(s32, s32, s32);

void func_003ACB88(s32 arg0) {
    if (arg0) {
        func_00500118(0x4A000A, 1, 1);
        func_00500118(0x4A000B, 1, 1);
        func_00500118(0x4A000C, 1, 1);
    } else {
        func_00500118(0x4A000A, 1, 0);
        func_00500118(0x4A000B, 1, 0);
        func_00500118(0x4A000C, 1, 0);
    }
}
