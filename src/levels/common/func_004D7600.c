#include "common.h"

extern s32 func_0011BB58(void *, s32, s32);
extern u8 D_001DB950;

extern s32 D_002513C8[];
extern s32 func_0011BB58(void *, s32, s32);
extern u8 D_001DB950;
void func_004D7600(s32 a0) {
    D_001DB950 = 1;
    func_0011BB58(D_002513C8, a0, 0x40);
}
