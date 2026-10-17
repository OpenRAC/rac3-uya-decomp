#include "common.h"

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_49E5B8;
extern s32 *func_00494DD0(s32);
extern s32 func_00494E58(s32 *);
extern s32 func_004181A0(s32);
extern s32 func_00512FE8(s32, s32);
extern s32 func_00512D70(s32, s32);
extern s32 func_005131A0(s32, s32);
extern s32 D_001D9690;
extern s32 D_001D9688;
extern s32 D_001D96DC;
extern E_49E5B8 D_002ED8A0[];
extern char D_001D96E0[];

void func_0049E5B8(void) {
    D_001D9690 = func_00494E58(func_00494DD0(0));
    if (D_001D9690 < 0) {
        return;
    }
    if (D_001D9688 != D_001D9690) {
        if (D_002ED8A0[D_001D9690].x14) {
            func_00512FE8(0x570005, func_004181A0(D_002ED8A0[D_001D9690].x0));
            func_00512FE8(0x570006, func_004181A0(D_002ED8A0[D_001D9690].x4));
        } else {
            func_00512FE8(0x570005, func_004181A0(456));
            func_00512FE8(0x570006, (s32)D_001D96E0);
        }
        D_001D96DC = 30;
    }
    if (D_001D96DC != 0) {
        if (--D_001D96DC == 0) {
            if (D_002ED8A0[D_001D9690].x14) {
                func_005131A0(0x570009, D_002ED8A0[D_001D9690].x8 + 1);
                func_00512D70(0x570009, 1);
            } else {
                func_00512D70(0x570009, 0);
            }
        }
    }
    D_001D9688 = D_001D9690;
}
