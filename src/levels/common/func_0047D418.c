#include "common.h"

extern s32 D_001D841C;
extern u8 D_001D8438;
extern void func_00430120(s32, s32);

extern s32 D_001D841C;
extern u8 D_001D8438;
extern void func_00430120(s32, s32);
void func_0047D418(void) {
    if (D_001D841C != 0) {
        func_00430120(D_001D841C, 1);
        D_001D8438 = 1;
    }
}
