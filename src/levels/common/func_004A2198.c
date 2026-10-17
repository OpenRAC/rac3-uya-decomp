#include "common.h"

extern void func_004A2198(void);
extern s32 D_001D4BB0;

extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
void func_0040BDE0(s32 *, s32, s32);
void func_004A2200();
void func_0011F0A0(s32);
extern s32 D_001E10E8_003D99D8;
extern s32 D_001E0E60;
extern u8 D_0023A070[];

void func_004A2198(void) {
    s32 t = D_001E10E8_003D99D8;
    D_001E0E60 = t;
    t += 0x10;
    D_001D4BB0 = D_001D4BB4;
    D_001E10E8_003D99D8 = t;
    func_0011F0A0(0);
    func_004A2200();
    func_0040BDE0(D_0023A070, 0x3200, 0x40);
    func_004A1F88();
}
