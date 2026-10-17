#include "common.h"

extern void func_00477B38(s32);
extern s32 D_001D80A0;
extern s32 func_00512AB0(s32, s32, s32);
extern u8 D_001D80A4;

extern u8 D_001D80A4;
extern u8 D_001D80B6;
extern s32 D_001D80A0;
extern s32 func_00512AB0(s32, s32, s32);
extern s32 func_00477DE8(s32);
extern void func_00477D60();
void func_00477B38(s32 a) {
    if (D_001D80A4 != 0 && D_001D80B6 == 0) {
        D_001D80A0 = a;
        func_00512AB0(0x90000, 1, a != 0);
        func_00477D60(func_00477DE8(0));
    }
}
