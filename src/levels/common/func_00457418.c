#include "common.h"

extern s32 D_001D668C[];
extern s32 D_001D6690[];
extern s32 D_001D6694[];
extern s32 D_001D7DC8;
extern s32 D_001D7DCC;

void func_00457418(s32 a0) {
    D_001D6694[0] = a0;
    D_001D6690[0] = -2;
    D_001D668C[0] = a0;
    D_001D7DC8 = 0;
    D_001D7DCC = 0;
}
