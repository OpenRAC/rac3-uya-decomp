#include "common.h"

extern s32 func_00494DD0(s32);
extern char *func_004950A8(s32, s32, s32);
extern s32 func_004181A0(s32);
extern int func_0011B2E8(char *, char *, ...);
extern s32 D_001D8E40;
extern s32 D_001D8E44;
extern s32 D_001D8E38;
extern s32 D_001D8E3C;
extern char D_001D8E80[];
extern char D_001D8E88[];
extern u8 D_00143A06[];
extern u8 D_00143954[];
extern u8 D_00143955[];
extern u8 D_00143956[];

void func_0048EC60(void) {
    if (D_001D8E40 >= 0) {
        func_0011B2E8(func_004950A8(func_00494DD0(0), 0, D_001D8E40), D_001D8E80, func_004181A0(1287), D_00143A06[0] ? func_004181A0(373) : func_004181A0(374));
    }
    if (D_001D8E44 >= 0) {
        func_0011B2E8(func_004950A8(func_00494DD0(0), 0, D_001D8E44), D_001D8E88, func_004181A0(322), func_004181A0(397), D_00143954[0] ? func_004181A0(373) : func_004181A0(374));
    }
    if (D_001D8E38 >= 0) {
        func_0011B2E8(func_004950A8(func_00494DD0(0), 0, D_001D8E38), D_001D8E88, func_004181A0(322), func_004181A0(398), D_00143955[0] ? func_004181A0(373) : func_004181A0(374));
    }
    if (D_001D8E3C >= 0) {
        func_0011B2E8(func_004950A8(func_00494DD0(0), 0, D_001D8E3C), D_001D8E80, func_004181A0(328), D_00143956[0] ? func_004181A0(373) : func_004181A0(374));
    }
}
