#include "common.h"

extern u8 D_001A4BE0[];
extern u8 D_001CCFD0[];
extern u16 D_0016C5AA[];
extern void func_0045BF98(s32);
extern void func_004A57D8(void);
extern void func_00418028(void);
extern void func_004A8F10(s32);

void func_004A9148(void)
{
    u8 *g = D_001A4BE0;
    u8 *p;

    if (*(s32 *)(g + 10320) <= 0) {
        *(s32 *)(g + 10320) = 1;
    }
    func_0045BF98(0);
    p = D_001CCFD0;
    if (*(u16 *)(p + 118) != 6 && *(u16 *)(p + 118) != 7) {
        *(u16 *)(p + 118) = 5;
    }
    if (*(u16 *)(p + 158) != 6 && *(u16 *)(p + 158) != 7) {
        *(u16 *)(p + 158) = 5;
    }
    func_004A57D8();
    func_00418028();
    func_004A8F10(0);
    D_0016C5AA[0] = 0;
}
