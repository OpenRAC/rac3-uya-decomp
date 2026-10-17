#include "common.h"

extern u8 D_001A71C4[];
extern void func_004E9888(s32);

void func_004E3EC0(void) {
    if (D_001A71C4[0] == 3) {
        func_004E9888(0);
    }
}
