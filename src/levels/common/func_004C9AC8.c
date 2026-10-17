#include "common.h"

void func_00116F98(void *, s32, void *);
extern u8 D_001DB338[];
extern u8 D_001DB358[];
typedef struct { s32 f0; s32 f4; u32 f8; s32 fC; s32 f10; s32 f14; } S_003A6888;

void func_004C9AC8(S_003A6888 *arg0, u32 arg1, s32 arg2, s32 arg3) {
    if (arg1 < 4U) {
        func_00116F98(D_001DB338, 0x26, D_001DB358);
    }
    arg0->f0 = arg2;
    arg0->f4 = arg3;
    arg0->f8 = arg1;
    arg0->f14 = 0;
    arg0->fC = 0;
    arg0->f10 = 0;
}
