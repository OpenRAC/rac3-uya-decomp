#include "common.h"

extern void func_004AF6D0(void);
extern void func_004C1FE8(s32, unsigned long);

extern s32 D_001D4BB4;
void func_0040BD58(s32, s32 *, s32);
void func_004C1AF0(s32 *);
extern void func_004C1FE8(s32, unsigned long);
void func_004AFA28();
void func_004B0990();
void func_004B1D60();
void func_004B2AA0();
void func_0011F0A0(s32);
extern s32 D_001D4BB0_003D47A0;
extern u8 D_001DA420[];
extern s32 D_001E10E8_003D47A0;
extern u8 D_00100AE0[];
extern u8 D_001159B0[];

void func_004AF6D0(void) {
    func_004C1FE8(0x47, 0x5340B);
    D_001D4BB0_003D47A0 = D_001D4BB4;
    func_0011F0A0(0);
    func_004AFA28();
    func_004AF5E0();
    func_0011F0A0(0);
    func_004B2AA0();
    func_004C1AF0(D_001159B0);
    func_004B0990();
    func_004B1D60();
    func_004C1AF0(D_00100AE0);
    func_0040BD58(D_001E10E8_003D47A0, D_001DA420, 0x20);
    D_001E10E8_003D47A0 += 0x20;
}
