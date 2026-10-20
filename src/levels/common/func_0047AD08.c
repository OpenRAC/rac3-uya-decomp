#include "common.h"

typedef struct {
    s32 state;
    u8 pad4[24];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u8 pad2C[68];
    u8 unk70;
} S_002E9FD8;

extern S_002E9FD8 D_002E9FD8[];
extern s32 D_001D6690;
extern s32 D_001D6694;
extern u8 D_001D672E;
extern void func_0047A350(s32);
extern void func_004C1BB0(void);
extern void func_0047A6B0(void);
extern void func_0013C1D0(s32);
extern s32 func_00417E70(void);
extern void func_0045BFD0(void);
extern void func_0013B620(void);
extern void func_004A57D8(void);
extern void func_0045D318(s32);
extern void func_004179B8(s32);
extern void func_004A7368(s32, s32, s32);
extern void func_0047A268(void);

void func_0047AD08(void)
{
    if ((u32)(D_002E9FD8[0].state - 20) < 2) {
        func_0047A350(1);
    }
    func_004C1BB0();
    D_002E9FD8[0].unk24 = 0;
    D_002E9FD8[0].unk28 = 0;
    func_0047A6B0();
    D_002E9FD8[0].unk1C = 0;
    if (D_002E9FD8[0].unk70 == 0 || (u32)(D_002E9FD8[0].state - 20) >= 2) {
        D_002E9FD8[0].unk20 = 0;
    }
    if (D_001D6690 != 5 && D_001D6694 != 5) {
        func_0013C1D0(77);
    }
    if (func_00417E70() == 0 && D_001D6690 != 5 && D_001D6694 != 5) {
        func_0045BFD0();
    }
    func_0013B620();
    func_004A57D8();
    func_0045D318(0);
    D_001D672E = 0;
    func_004179B8(0);
    if (D_001D6690 == 0) {
        func_004A7368(20, 0, 0);
    }
    func_0047A268();
}
