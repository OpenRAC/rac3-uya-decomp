#include "common.h"

extern u8 D_001D81D4;
extern void func_0060E900(s32, s32, s32);

void func_005DC830(void) {
    if (D_001D81D4 != 0) {
        func_0060E900(0x60000, 1, 0);
        func_0060E900(0x60001, 1, 0);
        func_0060E900(0x60002, 1, 0);
        func_0060E900(0x60003, 1, 0);
        func_0060E900(0x60004, 1, 0);
    }
}
