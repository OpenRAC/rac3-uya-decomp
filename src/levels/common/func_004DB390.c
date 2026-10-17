#include "common.h"

extern void func_004D9680(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_004D9C20(s32, s32, s32);
extern void func_004D9C20();

extern s32 D_001D5600_003D3A50;
extern s32 D_001D5604_003D3A50;
extern s32 D_001D5628_003D3A50;
extern s32 D_001D5630_003D3A50;
extern s32 D_001D5634_003D3A50;
extern s32 D_001D55F8_003D3A50;
extern u8 D_001D3650_003D3A50[];
extern void func_004D9680(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_004D9C20();
void func_004DB390(void) {
    u8 *p;
    unsigned long *q = (unsigned long *)D_001D3650_003D3A50;
    q[0] = 0x5000000000000001UL;
    q[1] = 0xEEEEEEEEEEEEEEEEUL;
    q[2] = 0;
    q[3] = 0x3F;
    q[4] = 0xA0000000A0UL;
    q[5] = 0x19;
    q[6] = 0x100000000UL;
    q[7] = 0x4F;
    q[8] = 0x60;
    q[9] = 0x15;
    q[10] = 5;
    q[11] = 9;
    p = D_001D3650_003D3A50 + 0x60;
    func_004D9680(&p, D_001D5630_003D3A50, D_001D5600_003D3A50, D_001D5604_003D3A50, D_001D5628_003D3A50, 0x100, 0x100);
    func_004D9C20(&p, D_001D5628_003D3A50, D_001D5634_003D3A50);
    func_004D9C20(&p, D_001D5628_003D3A50, D_001D5634_003D3A50);
    D_001D55F8_003D3A50 = p - D_001D3650_003D3A50;
}
