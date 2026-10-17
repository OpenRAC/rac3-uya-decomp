#include "common.h"

extern u8 D_001D672E;
extern s32 D_001D5528;
extern s32 D_00143950[];

void func_00474978(void) {
    if (D_001D672E == 0) {
        D_001D5528++;
        if (D_001D5528 % 50 == 0 && D_00143950[0] != 0) {
            D_001D5528 += 10;
        }
    }
}
