#include "common.h"

extern void func_004B4C90(void);
extern u8 D_001A30B0[];
extern void func_00402A10(s32);
extern s32 D_001D6690;
extern void func_004C1C68(void);
extern void func_00402A10();

extern s32 D_001D4D40;
extern void *D_001E0FAC_003A3508;
extern u8 D_001A30B0[];
extern void (*D_001D6724)(s32);
extern s32 D_001EA8A0[];
extern s32 D_001D6690;
extern s32 D_001D6728;
extern void func_00402A10(s32);
extern void func_0045BB60(void *, s32, s32);
extern void func_0045BFD0(void);
extern void func_004C1C68(void);
void func_004B4C90(void) {
    if (D_001D4D40 == 0) { D_001D4D40 = 1; }
    func_00402A10(4);
    func_0045BB60(D_001E0FAC_003A3508, 1, 0x400);
    func_0045BFD0();
    D_001A30B0[0x43] |= 0x10;
    func_004C1C68();
    if (D_001D6724 != 0 && D_001EA8A0[0] == 0 && D_001D6690 != 2 && D_001D6690 != 1) {
        D_001D6724(D_001D6728);
        D_001D6724 = 0;
        D_001D6728 = 0;
    }
}
