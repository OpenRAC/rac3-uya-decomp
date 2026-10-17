#include "common.h"

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_498978;
extern s32 *func_00494DD0(s32);
extern s32 func_00494E58(s32 *);
extern s32 func_004181A0(s32);
extern s32 func_00512FE8(s32, s32);
extern s32 func_00512D70(s32, s32);
extern s32 func_005131A0(s32, s32);
extern s32 D_001D943C;
extern s32 D_001D9434;
extern s32 D_001D9484;
extern E_498978 D_002EBF28[];
extern char D_001D9488[];

void func_00498978(void) {
    D_001D943C = func_00494E58(func_00494DD0(0));
    if (D_001D943C < 0) {
        return;
    }
    if (D_001D9434 != D_001D943C) {
        if (D_002EBF28[D_001D943C].x14) {
            func_00512FE8(0x4E0005, func_004181A0(D_002EBF28[D_001D943C].x0));
            func_00512FE8(0x4E0006, func_004181A0(D_002EBF28[D_001D943C].x4));
        } else {
            func_00512FE8(0x4E0005, func_004181A0(456));
            func_00512FE8(0x4E0006, (s32)D_001D9488);
        }
        D_001D9484 = 30;
    }
    if (D_001D9484 != 0) {
        if (--D_001D9484 == 0) {
            if (D_002EBF28[D_001D943C].x14) {
                func_005131A0(0x4E0009, D_002EBF28[D_001D943C].x8 + 1);
                func_00512D70(0x4E0009, 1);
            } else {
                func_00512D70(0x4E0009, 0);
            }
        }
    }
    D_001D9434 = D_001D943C;
}
