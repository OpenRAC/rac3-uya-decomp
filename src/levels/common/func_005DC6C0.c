#include "common.h"

extern u8 D_001D81BC;
extern s32 D_001D81B8;
extern s32 *D_002412A0[];
extern void func_0060F828(s32);
extern void func_0060E900(s32, s32, s32);

void func_005DC6C0(s32 arg0) {
    if (D_001D81BC) {
        func_0060F828((*D_002412A0[0] < 2) ? 0 : 4);
        D_001D81B8 = arg0;
        func_0060E900(0x80000, 1, 1);
        func_0060E900(0x80001, 1, 0);
        func_0060E900(0x80002, 1, 0);
        func_0060E900(0x80003, 1, 1);
    }
}
