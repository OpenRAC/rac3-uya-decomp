#include "common.h"

extern void func_00500118(s32, s32, s32);

void func_003ACB48(s32 on) {
    if (on) {
        func_00500118(0x4A0000, 1, 1);
    } else {
        func_00500118(0x4A0000, 1, 0);
    }
}
