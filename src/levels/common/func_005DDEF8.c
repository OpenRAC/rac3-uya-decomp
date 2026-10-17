#include "common.h"

extern s32 D_001D8200[2];
extern u8 D_001D8210[4];
extern s32 func_005DF968(void);
extern s32 func_0060DD90(s32 a0);
extern void func_0060E900(s32 a0, s32 a1, s32 a2);

void func_005DDEF8(s32 a0, s32 a1) {
    if (func_0060DD90(func_005DF968()) == 1) {
        D_001D8200[a0] = a1;
        D_001D8210[a0] = 0;
        func_0060E900(0x30000, 1, 1);
    }
}
