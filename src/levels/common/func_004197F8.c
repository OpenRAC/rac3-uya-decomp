#include "common.h"
extern u8 D_001DFD72;
extern u8 D_001DFD73;
extern s16 D_001DFD60;
extern s16 D_001DFD48;
extern s32 func_00417F60(s32 a0, s32 a1);
void func_004197F8(void) {
    if (D_001DFD72 != 0) {
        if (func_00417F60((&D_001DFD48)[D_001DFD73], (&D_001DFD60)[D_001DFD73]) != 0) {
            D_001DFD72 = D_001DFD72 - 1;
            D_001DFD73 = (D_001DFD73 + 1) % 9;
        }
    }
}
