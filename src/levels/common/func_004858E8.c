#include "common.h"

/* localdecomp:start func_004858E8 */
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[0x82];
    u16 x8A;
    u8 pad8C[0x64];
} E_4858E8;
extern s32 func_00484718(s32, s32, s32);
extern s32 func_00512D70(s32, s32);
extern s32 func_004181A0(s32);
extern int func_0011B2E8(char *, char *, ...);
extern s32 D_001D8878;
extern s32 D_001D8868;
extern s32 D_001D886C;
extern char D_001D8810[8];
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern E_4858E8 D_002C5640[];
extern char D_002EAAE8[];
extern char D_001D89F8[];
extern char D_001D8A00[];
extern char D_001D8A10[];
extern char D_001D8A20[];

void func_004858E8(void) {
    s32 i = func_00484718(D_001D8878, D_001D8868, D_001D886C);

    if (D_001D8878 == 1) {
        func_00512D70(0x190007, 0);
    } else {
        func_00512D70(0x190007, 1);
    }
    if (D_00142CA0[i]) {
        func_0011B2E8(D_002EAAE8, D_001D89F8, func_004181A0((D_002C5640 + D_001425C0[i])->x4));
        func_0011B2E8(D_001D8810, D_001D8A00, func_004181A0(376), D_001427F0[i], D_002C5640[D_001425C0[i]].x8A);
    } else {
        func_0011B2E8(D_002EAAE8, D_001D8A10);
        func_0011B2E8(D_001D8810, D_001D8A20);
    }
}
/* localdecomp:end func_004858E8 */
