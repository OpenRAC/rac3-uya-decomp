#include "common.h"
extern s32 func_0060F870(void);
extern void func_0060FA98(s32);
extern u8 D_001D7F10[8];
void func_005D80A8(void) {
    D_001D7F10[func_0060F870()] = 0;
    func_0060FA98(6);
}
