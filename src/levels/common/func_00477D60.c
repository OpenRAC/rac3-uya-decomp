#include "common.h"

extern s32 D_001D80A0;
extern s32 func_00512AB0(s32, s32, s32);
extern void func_00476C68(void);
extern u8 D_001D80B6;
extern void func_00477D60();

extern s32 D_001D80A0;
extern u8 D_001D80B6;
extern void func_00477C28(s32);
extern void func_00476C68(void);
extern void func_00477268(void);
extern void func_00477330(void);
extern s32 func_00512AB0(s32, s32, s32);
void func_00477D60(void) {
    if (D_001D80A0 != 0 && D_001D80B6 == 0) {
        D_001D80A0--;
        func_00477C28(0x90000);
        func_00476C68();
        func_00477268();
        func_00477330();
    } else {
        func_00512AB0(0x90000, 1, 0);
    }
}
