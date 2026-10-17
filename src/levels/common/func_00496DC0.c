#include "common.h"

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} E_496DC0;
extern s32 *func_00494DD0(s32);
extern s32 func_00494E58(s32 *);
extern s32 func_004181A0(s32);
extern s32 func_00512FE8(s32, s32);
extern s32 func_00512D70(s32, s32);
extern s32 func_005131A0(s32, s32);
extern s32 D_001D9308;
extern s32 D_001D930C;
extern E_496DC0 *D_001D9318;
extern s32 D_001D936C;

void func_00496DC0(void) {
    s32 cur = func_00494E58(func_00494DD0(0));

    D_001D9308 = cur;
    if (cur != D_001D930C) {
        func_00512FE8(0x4B000C, func_004181A0(D_001D9318[cur].x0));
        func_00512FE8(0x4B0005, func_004181A0(D_001D9318[D_001D9308].x0));
        func_00512FE8(0x4B0006, func_004181A0(D_001D9318[D_001D9308].x4));
        D_001D936C = 30;
    }
    D_001D930C = D_001D9308;
    if (D_001D936C != 0) {
        if (--D_001D936C == 0) {
            if (D_001D9318[D_001D9308].x8 < 0) {
                func_005131A0(0x4B0009, 0);
                func_00512D70(0x4B0009, 1);
            } else {
                func_00512D70(0x4B0009, 1);
                func_005131A0(0x4B0009, D_001D9318[D_001D9308].x8 + 1);
            }
        }
    }
}
